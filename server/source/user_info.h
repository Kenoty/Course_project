#pragma once

#include <string>
#include "id.h"
#include "wallet.h"


class UserInfo: public Id, public Wallet
{
    std::string firstName;
    std::string secondName;
    std::string lastName;
    std::string phoneNumber;
	std::string email;
    std::string userPassword;
	std::string role;
public:
    UserInfo(std::string fName = "", std::string sName = "", std::string lName = "", std::string phNum = "", std::string email = "", std::string userPassword = "", std::string role = ""): Id(), Wallet()
	{
        this->firstName = fName;
        this->secondName = sName;
        this->lastName = lName;
        this->phoneNumber = phNum;
		this->email = email;
        this->userPassword = userPassword;
		this->role = role;
	}
    void setFname(const std::string_view);
    void setSname(const std::string_view);
    void setLname(const std::string_view);
    void setPhoneNumber(const std::string_view);
    void setEmail(const std::string_view);
    void setUserPassword(const std::string_view);
    void setRole(const std::string_view);
    std::string getRole();
};
