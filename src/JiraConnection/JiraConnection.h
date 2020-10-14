#pragma once

#define JIRA_HTTP_VERSION 11

#include <string>
#include <boost/asio/ssl/error.hpp>
#include <boost/asio/ssl/stream.hpp>
#include <boost/beast.hpp>
#include <boost/beast/ssl.hpp>
#include <vector>


namespace Jira
{
	class JiraConnection
	{
	public:

		JiraConnection(std::string basicAuthToken_, std::string host_, short port_) 
		{
			_basicAuthToken = basicAuthToken_;
			_host = host_;
			_port = port_;
		}

		virtual void open_connection(bool keepAlive_) = 0;
		virtual void close_connection() = 0;

		virtual boost::beast::http::response<boost::beast::http::dynamic_body> send_request(boost::beast::http::verb verb_, std::string target_, std::vector<std::tuple<boost::beast::http::field, boost::string_view>> additionalHeaderFields) = 0;

	protected:

		std::string _basicAuthToken;
		std::string _host;
		short _port;
		bool _keepAliveConnection;

		virtual boost::beast::http::response<boost::beast::http::dynamic_body> send_request(boost::beast::http::request<boost::beast::http::string_body> req_) = 0;
	private:
	};
}