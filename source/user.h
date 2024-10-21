#include <string>

class User
{
	int id = 0;
	std::string first_name;
	std::string second_name;
	std::string last_name;
	std::string phone_number;
	std::string email;
	std::string user_password;
public:
	void set_id(int);
	int friend get_user_id(User user);
	void set_fname(std::string&);
	void set_sname(std::string&);
	void set_lname(std::string&);
	void set_phone_number(std::string&);
	void set_email(std::string&);
	void set_user_password(std::string&);
};