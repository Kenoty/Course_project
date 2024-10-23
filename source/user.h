#include <string>
#include "id.h"

class User: public Id
{
	std::string first_name;
	std::string second_name;
	std::string last_name;
	std::string phone_number;
	std::string email;
	std::string user_password;
public:
	void set_fname(std::string&);
	void set_sname(std::string&);
	void set_lname(std::string&);
	void set_phone_number(std::string&);
	void set_email(std::string&);
	void set_user_password(std::string&);
};