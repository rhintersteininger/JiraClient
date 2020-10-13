#include "..\pch.h"

#include "JiraSslConnection.h"

#define HTTP_VERSION 11

namespace beast = boost::beast; // from <boost/beast.hpp>
namespace http = beast::http;   // from <boost/beast/http.hpp>
namespace net = boost::asio;    // from <boost/asio.hpp>
namespace ssl = net::ssl;       // from <boost/asio/ssl.hpp>
using tcp = net::ip::tcp;       // from <boost/asio/ip/tcp.hpp>


void Jira::JiraSslConnection::open_connection()
{
	try
	{
		auto const host = Jira::JiraConnection::_host;
		auto const port = _port;

		net::io_context ioc;
		ssl::context ctx(ssl::context::tlsv12_client);
		ctx.set_verify_mode(ssl::verify_peer);
		ctx.set_verify_callback(boost::bind(&Jira::JiraSslConnection::verify_certificate, this, _1, _2));

		tcp::resolver resolver(ioc);
		_stream = new beast::ssl_stream<beast::tcp_stream>(ioc, ctx);

		if (_stream == nullptr)
			throw new std::exception("Could not create ssl_stream");

		auto const results = resolver.resolve(host, std::to_string(port));

		beast::get_lowest_layer(*_stream).connect(results);
		_stream->handshake(ssl::stream_base::client);
	}
	catch (boost::wrapexcept<std::runtime_error> ex)
	{
		std::cerr << ex.what() << std::endl;
	}
	catch (std::exception const& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
		//return EXIT_FAILURE;
	}
	//return EXIT_SUCCESS;
}

void Jira::JiraSslConnection::close_connection()
{
	// Gracefully close the stream
	beast::error_code ec;
	_stream->shutdown(ec);
	if (ec == net::error::eof)
	{
		// Rationale:
		// http://stackoverflow.com/questions/25587403/boost-asio-ssl-async-shutdown-always-finishes-with-an-error
		ec = {};
	}
	if (ec)
		throw beast::system_error{ ec };

}

boost::beast::http::response<boost::beast::http::dynamic_body> Jira::JiraSslConnection::send_request(boost::beast::http::request<boost::beast::http::string_body> req_)
{
	if (_stream == nullptr)
		throw new std::exception("connection not established");

	http::write(*_stream, req_);

	beast::flat_buffer buffer;
	http::response<http::dynamic_body> res;
	http::read(*_stream, buffer, res);
	return res;
}


bool Jira::JiraSslConnection::verify_certificate(bool preverified,
	boost::asio::ssl::verify_context& ctx)
{
	return true;
}