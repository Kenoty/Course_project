#include "user_info.h"

void UserInfo::set_fname(const std::string_view value)
{
	this->first_name = value;
}

void UserInfo::set_sname(const std::string_view value)
{
	this->second_name = value;
}

void UserInfo::set_lname(const std::string_view value)
{
	this->last_name = value;
}

void UserInfo::set_email(const std::string_view value)
{
	this->email = value;
}

void UserInfo::set_phone_number(const std::string_view value)
{
	this->phone_number = value;
}

void UserInfo::set_user_password(const std::string_view value)
{
	this->user_password = value;
}

void UserInfo::set_role(const std::string_view value)
{
	this->role = value;
}

std::string UserInfo::get_role()
{
	return this->role;
}