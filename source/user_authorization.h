#include <iostream>
#include "user.h"

class user_authorization
{
public:
	void registration();
	void login(User&);
	void get_info(std::string&);
};