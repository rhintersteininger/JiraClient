// JiraClient.cpp : Defines the functions for the static library.
//



#include "pch.h"
#include "framework.h"
#include "../include/JiraClient.h"
#include <iostream>
#include <boost/beast/core/detail/base64.hpp>
#include <cstdlib>
#include <cstdlib>
#include <iostream>
#include <string>

#define JIRA_HTTP_VERSION 11


std::string Jira::JiraHttpClient::createBasicAuthToken(std::string username_, std::string password_)
{
	std::string basicAuthToken = std::string();
	basicAuthToken += username_ + ":" + password_;
	//maximum rest of 4 byte
	int estimatedOutLength = ((basicAuthToken.size() * 2 * 6) / (float)8) + 4;
	char* base64 = static_cast<char*>(std::malloc(estimatedOutLength));
	try
	{
		size_t outLength = boost::beast::detail::base64::encode(base64, basicAuthToken.c_str(), basicAuthToken.size());
		std::string base64Str = std::string(base64);
		base64Str.resize(outLength);
		std::free(base64);
		return base64Str;
	}
	catch (std::exception e)
	{
#if _DEBUG
		std::cerr << "Could not Create BasicAuthToken: " << e.what();
#else
		std::cerr << "Could not Create BasicAuthToken";
#endif
		std::free(base64);
	}

	return std::string();
}

void Jira::JiraHttpClient::prepareConnection(std::string host_, short port_)
{
	_connectionPool = new Jira::JiraConnectionPool(host_, port_, _basicAuthToken, 10);
}

boost::beast::http::response<boost::beast::http::dynamic_body> Jira::JiraHttpClient::get(std::string target_)
{
	boost::beast::http::request<boost::beast::http::string_body> req{ boost::beast::http::verb::get, target_.c_str(), JIRA_HTTP_VERSION };
	req.set(boost::beast::http::field::host, _connectionPool->get_host());
	req.set(boost::beast::http::field::user_agent, BOOST_BEAST_VERSION_STRING);

	return _connectionPool->request_connection()->get_connection()->send_request(req);
}


