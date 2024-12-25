#include "authorizationwindow.h"

#include <QApplication>
#include "coursesearchcard.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    std::string arr = "asd";

    AuthorizationWindow auth;
    auth.show();

    return app.exec();
}
