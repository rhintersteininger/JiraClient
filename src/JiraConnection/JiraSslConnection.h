#pragma once

#include "JiraConnection.h"

#include <boost/beast/core.hpp>
#include <boost/beast/http.hpp>
#include <boost/beast/ssl.hpp>
#include <boost/beast/version.hpp>
#include <boost/asio/connect.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <iostream>
#include <string>
#include <boost/bind.hpp>

namespace beast = boost::beast; // from <boost/beast.hpp>
namespace http = beast::http;   // from <boost/beast/http.hpp>
namespace net = boost::asio;    // from <boost/asio.hpp>
namespace ssl = net::ssl;       // from <boost/asio/ssl.hpp>
using tcp = net::ip::tcp;       // from <boost/asio/ip/tcp.hpp>

namespace Jira
{
	class JiraSslConnection : public Jira::JiraConnection
	{
	public:

		JiraSslConnection(std::string basicAuthToken_, std::string host_, short port_) : JiraConnection(basicAuthToken_, host_, port_) {}

		void open_connection();
		void close_connection();
		boost::beast::http::response<boost::beast::http::dynamic_body> send_request(boost::beast::http::request<boost::beast::http::string_body> req_);
	private:
		beast::ssl_stream<beast::tcp_stream>*  _stream = nullptr;
		bool verify_certificate(bool preverified, boost::asio::ssl::verify_context& ctx);
	};
}