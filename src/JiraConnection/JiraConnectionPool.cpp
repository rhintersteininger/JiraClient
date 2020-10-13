#include "JiraConnectionPool.h"

#include "JiraSslConnection.h"

std::unique_ptr<Jira::JiraConnectionWrapper> Jira::JiraConnectionPool::request_connection()
{
	std::unique_ptr<Jira::JiraConnectionWrapper> wrapper = std::make_unique<Jira::JiraConnectionWrapper>(get_or_create_connection(), this, 0);
	return wrapper;
}

void Jira::JiraConnectionPool::release_connection(int connectionId_)
{

}


Jira::JiraConnection* Jira::JiraConnectionPool::get_or_create_connection()
{
	std::unique_lock<std::mutex> mtx(_connection_mutex);
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
			throw new std::exception("currently no connection available");
		}
	}
	else
	{
		_availableConnections.pop_front();
	}

}

Jira::JiraConnection* Jira::JiraConnectionPool::create_new_connection()
{
	Jira::JiraConnection* con;
	if (_useSecureConnection)
		con = new Jira::JiraSslConnection(_basicAuthToken, _host, _port);
	else
		throw new std::exception("only secure connection supported");

	if (con == nullptr) throw new std::exception("could not create connection");

	con->open_connection();

	return con;
}