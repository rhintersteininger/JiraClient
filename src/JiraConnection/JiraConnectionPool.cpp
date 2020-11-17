#include "JiraConnectionPool.h"

#include "JiraSslConnection.h"

std::unique_ptr<Jira::JiraConnectionWrapper> Jira::JiraConnectionPool::request_connection()
{
	std::unique_ptr<Jira::JiraConnectionWrapper> wrapper = std::make_unique<Jira::JiraConnectionWrapper>(get_or_create_connection(), this, 0);
	return wrapper;
}

void Jira::JiraConnectionPool::release_connection(Jira::JiraConnection* connection_)
{
	if (connection_ == nullptr) return;
	std::unique_lock <std::recursive_mutex> mtx(_connection_mutex);
	_availableConnections.push_front(connection_);
}

void Jira::JiraConnectionPool::destroy_connection(Jira::JiraConnection* connection_)
{
	delete connection_;
	std::unique_lock<std::recursive_mutex> mtx(_connection_mutex);
	_currentConnections--;
}

std::unique_ptr<Jira::JiraConnectionWrapper> Jira::JiraConnectionPool::recreate_connection(Jira::JiraConnection* connection_)
{
	std::unique_lock<std::recursive_mutex> mtx(_connection_mutex);
	destroy_connection(connection_);
	return std::make_unique<Jira::JiraConnectionWrapper>(create_new_connection(), this, 0);
}


Jira::JiraConnection* Jira::JiraConnectionPool::get_or_create_connection()
{
	std::unique_lock<std::recursive_mutex> mtx(_connection_mutex);
	if (_availableConnections.empty())
	{
		if (_currentConnections < _maxConnections)
		{
			_currentConnections++;
			mtx.unlock();
			return create_new_connection();
		}
		else
		{
			//TODO: Wait for connection
			throw std::exception("currently no connection available");
		}
	}
	else
	{
		return _availableConnections.front();
	}

}

Jira::JiraConnection* Jira::JiraConnectionPool::create_new_connection()
{
	Jira::JiraConnection* con;
	if (_useSecureConnection)
		con = new Jira::JiraSslConnection(_basicAuthToken, _host, _port);
	else
		throw new std::exception("only secure connection supported");

	if (con == nullptr) throw std::exception("could not create connection");

	con->open_connection(true);

	return con;
}

boost::beast::http::response<boost::beast::http::dynamic_body> Jira::JiraConnectionPool::send_request(boost::beast::http::verb verb_, std::string target_, std::vector<std::tuple<boost::beast::http::field, boost::string_view>> additionalHeaderFields, std::string body_)
{
	std::unique_ptr<JiraConnectionWrapper> connWraper = request_connection();
	JiraConnection* connection = connWraper->get_connection();

	bool requestFailed = false;
	try
	{
		boost::beast::http::response<boost::beast::http::dynamic_body> result = connection->send_request(verb_, target_, additionalHeaderFields, body_);
		return result;
	}
	catch (boost::wrapexcept<boost::system::system_error> ex)
	{
		requestFailed = true;
	}
	catch (std::exception e)
	{
		requestFailed = true;
	}
	//Catch all jira exceptions Rework when adding http exceptions
	catch (...)
	{
		requestFailed = true;
	}

	if (requestFailed)
	{
		connWraper->_destroyed = true;
		return recreate_connection(connection)->get_connection()->send_request(verb_, target_, additionalHeaderFields, body_);
	}
	throw new std::exception("unknown exception on send request");
}