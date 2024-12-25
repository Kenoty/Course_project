#include "regerrexception.h"

RegErrException::RegErrException(std::string message): message(message) {}

const char* RegErrException::getEmailExp() const
{
    return this->emailRegExp;
}

const char* RegErrException::getPhoneNumExp() const
{
    return this->phoneNumRegExp;
}

const char* RegErrException::getNameExp() const
{
    return this->nameRegExp;
}

std::string RegErrException::getMessage() const
{
    return this->message;
}
