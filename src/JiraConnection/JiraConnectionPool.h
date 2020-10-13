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

		std::unique_ptr<JiraConnectionWrapper> request_connection();
		void release_connection(int id_);

		std::string get_host() { return _host; }
		short get_port() { return _port; }
	private:
		bool _useSecureConnection = true;
		std::string _host;
		short _port;
		std::string _basicAuthToken;
		short _maxConnections;


		std::mutex _connection_mutex;
		std::deque<JiraConnection> _availableConnections;
		short _currentConnections;

		Jira::JiraConnection* get_or_create_connection();
		Jira::JiraConnection* create_new_connection();
	};



	class JiraConnectionWrapper
	{
	public:
		JiraConnectionWrapper(Jira::JiraConnection* const conn_, Jira::JiraConnectionPool *const pool_, int id_) : _connection(conn_), _id(id_), _pool(pool_) {}
		Jira::JiraConnection* const get_connection() { return _connection; }

		~JiraConnectionWrapper()
		{
			if (!_released)
			{
				_pool->release_connection(_id);
			}
		}

	private:
		Jira::JiraConnection* const _connection;
		bool _released = false;
		int _id;
		Jira::JiraConnectionPool *const _pool;	
	};
}