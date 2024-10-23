#include "user.h"

void User::set_fname(std::string& value)
{
	this->first_name = value;
}

void User::set_sname(std::string& value)
{
	this->second_name = value;
}

void User::set_lname(std::string& value)
{
	this->last_name = value;
}

void User::set_email(std::string& value)
{
	this->email = value;
}

void User::set_phone_number(std::string& value)
{
	this->phone_number = value;
}

void User::set_user_password(std::string& value)
{
	this->user_password = value;
}