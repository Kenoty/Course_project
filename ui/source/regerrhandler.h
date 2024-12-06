#ifndef REGERRHANDLER_H
#define REGERRHANDLER_H

#include <string>
#include <QLineEdit>

class RegErrHandler
{
public:
    RegErrHandler();
    RegErrHandler(std::string message);
    void checkLine(QLineEdit*, const char*);
    bool handleException(QLineEdit*, const char*);
    const char* getEmailExp();
    const char* getPhoneNumExp();
    const char* getNameExp();
    std::string getMessage() const;
private:
    const char* emailRegExp = "^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\\.[a-zA-Z]{2,}$";
    const char* phoneNumRegExp = "\\+?[0-9]{1,3}?[-\\s]?\\(?[0-9]{1,4}?\\)?[-\\s]?[0-9]{1,4}[-\\s]?[0-9]{1,7}$";
    const char* nameRegExp = "^[a-zA-Zа-яА-Я]+$|^$";
    std::string message;
};

#endif // REGERRHANDLER_H
