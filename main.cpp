#include <QApplication>
#include <QtWidgets/QTableView>
#include <iostream>
#include "startup.h"
#include "TcpClient.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

	Cute::Startup startUp;
    startUp.Show();

	
	


	return a.exec();
}
