#include "user_info.h"

void UserInfo::setFname(const std::string_view value)
{
	this->firstName = value;
}

void UserInfo::setSname(const std::string_view value)
{
	this->secondName = value;
}

void UserInfo::setLname(const std::string_view value)
{
	this->lastName = value;
}

void UserInfo::setEmail(const std::string_view value)
{
	this->email = value;
}

void UserInfo::setPhoneNumber(const std::string_view value)
{
	this->phoneNumber = value;
}

void UserInfo::setUserPassword(const std::string_view value)
{
	this->userPassword = value;
}

void UserInfo::setRole(const std::string_view value)
{
	this->role = value;
}

std::string UserInfo::getRole()
{
	return this->role;
}