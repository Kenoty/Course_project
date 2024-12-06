#include "authorizationwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    AuthorizationWindow auth;

    auth.show();
    return app.exec();
}
