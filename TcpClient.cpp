#pragma once

#include "TcpClient.h"
#include <QDebug> 
#include <QMessageBox> 
#include <iostream> 
#include <boost/asio.hpp> 
#include <boost/bind.hpp> 
#include "DataModel.h"

namespace tcpclient {

	client::client(boost::asio::io_service& io_service) : stopped(false),
		socket(io_service),
		deadline(io_service)
	{
	}

	void client::start(tcp::resolver::iterator endpoint_iter, SearchModel search)
	{
		start_connect(endpoint_iter, search);
		deadline.async_wait(boost::bind(&client::check_deadline, this));
	}

	QueryData client::RetrieveData()
	{
		return queryData;
	}

	void client::stop()
	{
		stopped = true;
		socket.close();
		deadline.cancel();
	}

	void client::start_connect(tcp::resolver::iterator endpoint_iter, SearchModel search)
	{
		if (endpoint_iter != tcp::resolver::iterator())
		{
			// Set a deadline 
			deadline.expires_from_now(boost::posix_time::seconds(20));
			// Start connect
			socket.async_connect(endpoint_iter->endpoint(),
				boost::bind(&client::handle_connect,
					this, _1, endpoint_iter, search));
		}
		else
		{
			// There are no more endpoints to try. Shut down the client.
			stop();
			QMessageBox::warning(NULL, ("Connection failed"), ("Could not establish a connection with the server"));
		}
	}

	void client::handle_connect(const boost::system::error_code& err, tcp::resolver::iterator endpoint_iter, SearchModel search)
	{
		if (stopped)
			return;

		if (!socket.is_open())
		{
			QMessageBox::warning(NULL, ("Timed out"), ("Request to the server timed out!")); 
			qDebug() << "Connection timed out";
			// Try the next available endpoint.
			start_connect(++endpoint_iter, search);
		}
		else if (err)
		{
			qDebug() << "Connection error" << QString::fromStdString(err.message()) << "\n";
			QMessageBox::warning(NULL, ("Connection error"), (QString::fromStdString(err.message())));
			socket.close();

			// Try the next available endpoint.
			start_connect(++endpoint_iter, search);
		}
		else
		{
			start_write(search);
		}
	}

	void client::start_write(SearchModel search)
	{
		if (stopped)
			return;

		// Serialize
		boost::asio::streambuf buf;
		std::ostream os(&buf);
		boost::archive::text_oarchive ar(os);
		ar & search;

		const size_t header = buf.size();
		
		// Send data using scatter
		std::vector<boost::asio::const_buffer> buffers;
		buffers.push_back(boost::asio::buffer(&header, sizeof(header)));
		buffers.push_back(buf.data());

		boost::asio::async_write(socket, buffers,
			boost::bind(&client::handle_write, this, boost::asio::placeholders::error));
	}

	void client::handle_write(const boost::system::error_code& err)
	{
		if (stopped)
			return;

		if (!err)
		{
			start_read();
		}
		else
		{
			std::cout << "Error sending body: " << err.message() << "\n";
			QMessageBox::warning(NULL, ("Error sending body"), (QString::fromStdString(err.message())));
			qDebug() << "Error sending body:" << QString::fromStdString(err.message()) << "\n";
			stop();
		}
	}

	void client::start_read()
	{
		// Set a deadline for the read operation.
		deadline.expires_from_now(boost::posix_time::seconds(30));

		boost::asio::async_read(socket, boost::asio::buffer(&readHeader, sizeof(readHeader)),
			boost::bind(&client::handle_read, this, boost::asio::placeholders::error));
	}

	void client::handle_read(const boost::system::error_code& err)
	{
		if (stopped)
			return;

		if (!err)
		{
			
			boost::asio::read(socket, read_buffer.prepare(readHeader));
			read_buffer.commit(readHeader);

			// Deserialize
			std::istream is(&read_buffer);
			boost::archive::text_iarchive ar(is);
			ar & queryData;

			//Close connection
			stop();
		}
		else
		{
			std::cout << "Error on receive: " << err.message() << "\n";
			QMessageBox::warning(NULL, ("Error reading data"), (QString::fromStdString(err.message())));
			qDebug() << "Error on receive:" << QString::fromStdString(err.message()) << "\n";
			stop();
		}
	}

	void client::check_deadline()
	{
		if (stopped)
			return;

		if (deadline.expires_at() <= deadline_timer::traits_type::now())
		{
			socket.close();

			deadline.expires_at(boost::posix_time::pos_infin);
		}
		deadline.async_wait(boost::bind(&client::check_deadline, this));
	}

}