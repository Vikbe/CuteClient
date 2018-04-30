#pragma once

#include <QMainWindow>
#include <QStringListModel>
#include "DataModel.h" 




namespace Ui {
    class MainView;
}

namespace Cute {

    class MainView : public QMainWindow
    {
        Q_OBJECT

    public:
        explicit MainView(QWidget *parent = 0);
        ~MainView();

		

    private slots:
        void on_searchBtn_clicked();

    private:
        
		void updateList(QueryData updatedlist);
		
		void Search(SearchModel query);
		
		SearchModel GetInput();
		
		Ui::MainView *ui;
		QStringListModel *model;
	};
}

