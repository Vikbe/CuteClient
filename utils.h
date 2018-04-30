#pragma  once

#include<QWidget>
#include <QString>
#include <QDebug>

namespace Cute {

    class Utils
    {
    public:
        static void DestructorMsg(const QObject * const object);
        static void DestructorMsg(const QString& value);
    };

}

