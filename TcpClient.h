#pragma once

#include <boost/asio.hpp> 
#include <boost/bind.hpp>
#include "DataModel.h"

namespace tcpclient
{

	using boost::asio::deadline_timer;
	using boost::asio::ip::tcp;



	class client
	{
	public:
		client(boost::asio::io_service& io_service);


		void start(tcp::resolver::iterator endpoint_iter, SearchModel search); 

		QueryData RetrieveData();
		
		void stop();

	private:
		void start_connect(tcp::resolver::iterator endpoint_iter, SearchModel search);

		void handle_connect(const boost::system::error_code& err,
			tcp::resolver::iterator endpoint_iter, SearchModel search);

		void start_write(SearchModel search);

		void handle_write(const boost::system::error_code& err);

		void start_read();

		void handle_read(const boost::system::error_code& err);

		void check_deadline();

	private:
		
		QueryData queryData;
		bool stopped;
		tcp::socket socket;
		size_t readHeader;
		boost::asio::streambuf write_buffer;
		boost::asio::streambuf read_buffer;
		deadline_timer deadline;
	};
}