#pragma  once
#include <QObject> 
#include <iostream>


namespace Cute {

    class MainView;

    class Startup : public QObject
    {
        Q_OBJECT

		

        MainView& m_mainView; 

		

    public:
        explicit Startup();

        void Show() const;

		

        ~Startup();
    signals:

    public slots:
    };
}


