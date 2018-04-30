#include <string>
#include "mainview.h"
#include "ui_mainview.h"
#include <QMessageBox> 
#include "TcpClient.h" 
#include "DataModel.h" 


namespace Cute {

	

	MainView::MainView(QWidget *parent) :
		QMainWindow(parent),
		ui(new Ui::MainView)
	{
		ui->setupUi(this);
		model = new QStringListModel(this); 
		ui->listView->setModel(model); 
	}

	MainView::~MainView()
	{
		delete ui; 
		delete model;
	}

	//Create the query
	void MainView::on_searchBtn_clicked()
	{
		Search(GetInput());
	}

	void MainView::updateList(QueryData result)
	{
		QStringList list;

		if (result.IsValid())
		{
			for (auto i : result.QueryResult)
			{
				list << QString::fromStdString(i.AsString());
			}
		} 
		else
		{
			QMessageBox::information(this, "Not found", "No matching result found");
		}
		list.sort();
		model->setStringList(list); 
	}

	// Open a connection to the server, send and retrieve query
	void MainView::Search(SearchModel query)
	{
		using boost::asio::ip::tcp;
		
		boost::asio::io_service io_service;
		tcp::resolver m_resolver(io_service);
		tcpclient::client m_client(io_service);

		m_client.start(m_resolver.resolve(tcp::resolver::query("127.0.0.1", "80")), query);
		io_service.run();

		QueryData retrieved = m_client.RetrieveData();
		updateList(retrieved);
	}

	SearchModel MainView::GetInput()
	{
		SearchModel query;
		query.Date = ui->dateFilter->text().toStdString();
		query.Id = ui->idFilter->text().toStdString();
		query.Number = ui->numberFilter->text().toStdString();
		query.Constant = ui->constantFilter->text().toStdString();
		query.Digits = ui->digitsFilter->text().toStdString();
		query.Decimals = ui->decimalsFilter->text().toStdString();

		return query;
	}

}