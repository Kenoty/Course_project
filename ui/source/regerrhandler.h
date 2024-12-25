#ifndef REGERRHANDLER_H
#define REGERRHANDLER_H

#include <string>
#include <QLineEdit>

#include "regerrexception.h"

class RegErrHandler: public RegErrException
{
public:
    RegErrHandler();
    RegErrHandler(std::string message);
    void checkLine(QLineEdit*, const char*);
    bool handleException(QLineEdit*, const char*);
};

#endif
