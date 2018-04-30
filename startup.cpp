#include "startup.h"
#include "View/mainview.h"
#include "utils.h"
#include <boost/bind.hpp>
#include <iostream>



namespace Cute {

    Startup::Startup() :
        QObject(nullptr),
        m_mainView(*new MainView(nullptr)) 
	{
	
	}

    Startup::~Startup()
    {
        Utils::DestructorMsg(this);
        delete &m_mainView;
    }

    void Startup::Show() const
    {
        m_mainView.show();
    } 

}



