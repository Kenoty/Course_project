#ifndef REGERREXCEPTION_H
#define REGERREXCEPTION_H

#include <string>

class RegErrException
{
public:
    RegErrException(){};
    RegErrException(std::string message);
    const char* getEmailExp() const;
    const char* getPhoneNumExp() const;
    const char* getNameExp() const;
    std::string getMessage() const;
private:
    const char* emailRegExp = "^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\\.[a-zA-Z]{2,}$";
    const char* phoneNumRegExp = "\\+?[0-9]{1,3}?[-\\s]?\\(?[0-9]{1,4}?\\)?[-\\s]?[0-9]{1,4}[-\\s]?[0-9]{1,7}$";
    const char* nameRegExp = "^[a-zA-Zа-яА-Я\\s]+$|^$";
    std::string message;
};

#endif
