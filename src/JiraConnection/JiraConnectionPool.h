#pragma once
#include "../pch.h"

#include <deque>

#include "JiraConnection.h"

namespace Jira
{
	class JiraConnectionWrapper;



	class JiraConnectionPool
	{
	public:
		JiraConnectionPool(std::string host_, short port_, std::string basicAuthToken_, short maxConnections_) : _host(host_), _port(port_), _basicAuthToken(basicAuthToken_), _maxConnections(maxConnections_)
		{
			
		}

		boost::beast::http::response<boost::beast::http::dynamic_body> send_request(boost::beast::http::verb verb_, std::string target_, std::vector<std::tuple<boost::beast::http::field, boost::string_view>> additionalHeaderFields, std::string body_);
		void release_connection(Jira::JiraConnection* connection_);
		void destroy_connection(Jira::JiraConnection* connection_);
		std::unique_ptr<JiraConnectionWrapper> recreate_connection(Jira::JiraConnection* connection_);

		std::string get_host() { return _host; }
		short get_port() { return _port; }
	private:
		bool _useSecureConnection = true;
		std::string _host;
		short _port;
		std::string _basicAuthToken;
		short _maxConnections;


		std::recursive_mutex _connection_mutex;
		std::deque<JiraConnection*> _availableConnections;
		short _currentConnections;

		Jira::JiraConnection* get_or_create_connection();
		Jira::JiraConnection* create_new_connection();

		std::unique_ptr<JiraConnectionWrapper> request_connection();
	};



	class JiraConnectionWrapper
	{
	public:
		JiraConnectionWrapper(Jira::JiraConnection* const conn_, Jira::JiraConnectionPool *const pool_, int id_) : _connection(conn_), _id(id_), _pool(pool_) {}
		Jira::JiraConnection* const get_connection() { return _connection; }

		~JiraConnectionWrapper()
		{
			if (!_released && !_destroyed)
			{
				_pool->release_connection(_connection);
			}
		}

		bool _destroyed = false;
	private:
		Jira::JiraConnection* const _connection;
		bool _released = false;
		int _id;
		Jira::JiraConnectionPool *const _pool;	
	};
}