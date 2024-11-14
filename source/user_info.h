#pragma once

#include <string>
#include "id.h"
#include "wallet.h"


class UserInfo: public Id, public Wallet
{
	std::string first_name;
	std::string second_name;
	std::string last_name;
	std::string phone_number;
	std::string email;
	std::string user_password;
	std::string role;
public:
	UserInfo(std::string f_name = "", std::string s_name = "", std::string l_name = "", std::string ph_num = "", std::string email = "", std::string user_password = "", std::string role = ""): Id(), Wallet()
	{
		this->first_name = f_name;
		this->second_name = s_name;
		this->last_name = l_name;
		this->phone_number = ph_num;
		this->email = email;
		this->user_password = user_password;
		this->role = role;
	}
	void set_fname(const std::string_view);
	void set_sname(const std::string_view);
	void set_lname(const std::string_view);
	void set_phone_number(const std::string_view);
	void set_email(const std::string_view);
	void set_user_password(const std::string_view);
	void set_role(const std::string_view);
	std::string get_role();
};