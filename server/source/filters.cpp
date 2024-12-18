#include "filters.h"

void Filters::setFname(std::string text)
{
    this->fname = text;
}

void Filters::setSname(std::string text)
{
    this->sname = text;
}

void Filters::setLname(std::string text)
{
    this->lname = text;
}

void Filters::setEmail(std::string text)
{
    this->email = text;
}

void Filters::setPhone(std::string text)
{
    this->phone = text;
}

std::string Filters::createFiltersKit()
{
    std::string query = "";

    if(!fname.empty())
        query += " AND first_name LIKE '" + fname +"%'";

    if(!sname.empty())
        query += " AND second_name LIKE '" + sname +"%'";

    if(!lname.empty())
        query += " AND last_name LIKE '" + lname +"%'";

    if(!email.empty())
        query += " AND email = '" + email + "'";

    if(!phone.empty())
        query += " AND phone_number = '" + phone + "'";

    return query;
}
