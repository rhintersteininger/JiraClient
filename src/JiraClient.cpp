// JiraClient.cpp : Defines the functions for the static library.
//



#include "pch.h"
#include "framework.h"
#include "../include/JiraClient.h"
#include <iostream>
#include <boost/beast/core/detail/base64.hpp>
#include <cstdlib>
#include <iostream>
#include <string>
#include <boost/beast/core/buffers_to_string.hpp>

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
	return _connectionPool->request_connection()->get_connection()->send_request(boost::beast::http::verb::get, target_, std::vector<std::tuple<boost::beast::http::field, boost::string_view>>());
}

boost::beast::http::response<boost::beast::http::dynamic_body> Jira::JiraHttpClient::post(std::string target_)
{
	return _connectionPool->request_connection()->get_connection()->send_request(boost::beast::http::verb::post, target_, std::vector<std::tuple<boost::beast::http::field, boost::string_view>>());
}

Jira::Data::SearchResults Jira::JiraHttpClient::search(std::string jql_)
{
	boost::beast::http::response<boost::beast::http::dynamic_body> result = get("/rest/api/2/search?jql=" + jql_);

	std::cout << result << std::endl;

	auto body = result.body();
	std::string bodyStr;//bodyStr(boost::beast::buffers_to_string(body.data()), body.size());

	for (auto seq : body.data()) {
		auto* cbuf = boost::asio::buffer_cast<const char*>(seq);
		bodyStr.append(cbuf, boost::asio::buffer_size(seq));
	}
	Jira::Data::SearchResults data = nlohmann::json::parse(bodyStr);
	return data;
}


