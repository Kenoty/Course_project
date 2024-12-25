#include <iostream>
#include <QRegularExpression>
#include <QRegularExpressionValidator>
#include <QMessageBox>

#include "regerrhandler.h"

RegErrHandler::RegErrHandler(): RegErrException() {}

RegErrHandler::RegErrHandler(std::string message): RegErrException(message) {}

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
        throw RegErrException("Invalid input");
    }
}

bool RegErrHandler::handleException(QLineEdit* line, const char* expression)
{
    try
    {
        checkLine(line, expression);
        return true;
    }
    catch (const RegErrException& exception)
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
            warningMessage = "Проверьте введенное поле. Возможно оно не содержит символа @: " + line->text();
        }

        QMessageBox::warning(nullptr, "Ошибка формата ввода", warningMessage);
        line->clear();
        line->setFocus();

        return false;
    }
}
