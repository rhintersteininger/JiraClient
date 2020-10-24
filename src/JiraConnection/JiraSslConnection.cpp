#include "..\pch.h"

#include "JiraSslConnection.h"
#include <iomanip>

#define HTTP_VERSION 11

namespace beast = boost::beast; // from <boost/beast.hpp>
namespace http = beast::http;   // from <boost/beast/http.hpp>
namespace net = boost::asio;    // from <boost/asio.hpp>
namespace ssl = net::ssl;       // from <boost/asio/ssl.hpp>
using tcp = net::ip::tcp;       // from <boost/asio/ip/tcp.hpp>


void Jira::JiraSslConnection::open_connection(bool keepAlive_)
{
	try
	{
		_keepAliveConnection = keepAlive_;
		auto const host = Jira::JiraConnection::_host;
		auto const port = _port;

		ioc = new net::io_context();
		ctx = new ssl::context(ssl::context::tlsv12_client);
		
		ctx->set_verify_mode(ssl::verify_peer);
		ctx->set_verify_callback(boost::bind(&Jira::JiraSslConnection::verify_certificate, this, _1, _2));

		tcp::resolver resolver(*ioc);
		_stream = new beast::ssl_stream<beast::tcp_stream>(*ioc, *ctx);

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

	delete _stream;
	delete ioc;
	delete ctx;
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

std::string url_encode(const std::string& value) {
	std::ostringstream escaped;
	escaped.fill('0');
	escaped << std::hex;

	for (std::string::const_iterator i = value.begin(), n = value.end(); i != n; ++i) {
		std::string::value_type c = (*i);

		// Keep alphanumeric and other accepted characters intact
		if (isalnum(c) || c == '-' || c == '_' || c == '.' || c == '~') {
			escaped << c;
			continue;
		}
	
		// Any other characters are percent-encoded
		escaped << std::uppercase;
		escaped << '%' << std::setw(2) << int((unsigned char)c);
		escaped << std::nouppercase;
	}

	return escaped.str();
}

boost::beast::http::response<boost::beast::http::dynamic_body> Jira::JiraSslConnection::send_request(boost::beast::http::verb verb_, std::string target_, std::vector<std::tuple<boost::beast::http::field, boost::string_view>> additionalHeaderFields, std::string body_)
{
	boost::beast::http::request<boost::beast::http::string_body> req{ verb_, target_.c_str(), JIRA_HTTP_VERSION };
	req.set(boost::beast::http::field::host, _host);
	req.set(boost::beast::http::field::user_agent, BOOST_BEAST_VERSION_STRING);
	req.set(boost::beast::http::field::authorization, "Basic " + _basicAuthToken);
	
	if (_keepAliveConnection)
		req.set(boost::beast::http::field::connection, "keep-alive");

	for (auto field : additionalHeaderFields)
	{
		req.set(std::get<0>(field), std::get<1>(field));
	}

	if (!body_.empty())
	{
		req.body() = body_;
		req.prepare_payload();
	}

	return Jira::JiraSslConnection::send_request(req);
}

Jira::JiraSslConnection::~JiraSslConnection()
{

}
