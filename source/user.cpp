#include "user.h"

void User::set_fname(const std::string& value)
{
	this->first_name = value;
}

void User::set_sname(const std::string& value)
{
	this->second_name = value;
}

void User::set_lname(const std::string& value)
{
	this->last_name = value;
}

void User::set_email(const std::string& value)
{
	this->email = value;
}

void User::set_phone_number(const std::string& value)
{
	this->phone_number = value;
}

void User::set_user_password(const std::string& value)
{
	this->user_password = value;
}