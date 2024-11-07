#include "user_info.h"

void User_info::set_fname(const std::string_view value)
{
	this->first_name = value;
}

void User_info::set_sname(const std::string_view value)
{
	this->second_name = value;
}

void User_info::set_lname(const std::string_view value)
{
	this->last_name = value;
}

void User_info::set_email(const std::string_view value)
{
	this->email = value;
}

void User_info::set_phone_number(const std::string_view value)
{
	this->phone_number = value;
}

void User_info::set_user_password(const std::string_view value)
{
	this->user_password = value;
}

void User_info::set_role(const std::string_view value)
{
	this->role = value;
}

std::string User_info::get_role()
{
	return this->role;
}