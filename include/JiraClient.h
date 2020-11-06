#pragma once
#include <string>
#include "../src/JiraConnection/JiraConnectionPool.h"
#include "JiraData.h"

namespace Jira
{
	class JiraHttpClient
	{
	public:
		JiraHttpClient(std::string username_, std::string password_, std::string host_, short port_)
		{
			_basicAuthToken = createBasicAuthToken(username_, password_);
			prepareConnection(host_, port_);
		}


		Jira::Data::SearchResults search(std::string jql_);
		Jira::Data::GetIssue get_issue(std::string issueKeyOrId_);
		bool add_worklog_to_issue(Jira::Data::AddWorklog worklogEntry);
		Jira::Data::GetUser get_current_user();


		boost::beast::http::response<boost::beast::http::dynamic_body> get(std::string target_);
		boost::beast::http::response<boost::beast::http::dynamic_body> post(std::string target_, std::vector<std::tuple<boost::beast::http::field, boost::string_view>> additionalHeaderFields_, std::string body_);

		~JiraHttpClient()
		{
			if (_connectionPool != nullptr)
				delete _connectionPool;
		}

	private:
		std::string _basicAuthToken;
		Jira::JiraConnectionPool* _connectionPool;

		std::string createBasicAuthToken(std::string username_, std::string password);
		void prepareConnection(std::string host_, short port_);


		
	};
}