#include <iostream>
#include <QRegularExpression>
#include <QRegularExpressionValidator>
#include <QMessageBox>

#include "regerrhandler.h"

RegErrHandler::RegErrHandler() {}

RegErrHandler::RegErrHandler(std::string message): message(message) {}

void RegErrHandler::checkLine(QLineEdit* line, const char* expression)
{
    QRegularExpression regExp(expression);
    QRegularExpressionValidator* validator = new QRegularExpressionValidator(regExp);

    line->setValidator(validator);

    if(line->hasAcceptableInput())
    {
        delete validator;
    }
    else
    {
        delete validator;
        throw RegErrHandler("Invalid input");
    }
}

bool RegErrHandler::handleException(QLineEdit* line, const char* expression)
{
    try
    {
        checkLine(line, expression);
        return true;
    }
    catch (const RegErrHandler& exception)
    {
        std::cout << exception.getMessage() << std::endl;
        QString warningMessage;

        if (expression == getNameExp())
        {
            warningMessage = "Проверьте введенное поле. Оно может содержать только символы русского и английского алфавита: " + line->text();
        }
        else if(expression == getPhoneNumExp())
        {
            warningMessage = "Проверьте введенное поле. Оно может содержать только цифры и знак '+': " + line->text();
        }
        else
        {
            warningMessage = "Проверьте введенное поле. Dозможно оно не содержить символа @: " + line->text();
        }

        QMessageBox::warning(line, "Ошибка формата ввода", warningMessage);
        line->clear();
        line->setFocus();

        return false;
    }
}

const char* RegErrHandler::getEmailExp()
{
    return this->emailRegExp;
}

const char* RegErrHandler::getPhoneNumExp()
{
    return this->phoneNumRegExp;
}

const char* RegErrHandler::getNameExp()
{
    return this->nameRegExp;
}

std::string RegErrHandler::getMessage() const
{
    return this->message;
}
