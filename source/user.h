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
	std::string role;
public:
	void set_fname(const std::string_view);
	void set_sname(const std::string_view);
	void set_lname(const std::string_view);
	void set_phone_number(const std::string_view);
	void set_email(const std::string_view);
	void set_user_password(const std::string_view);
	void set_role(const std::string_view);
};