#include "database.h"
#include "menu_interface.h"
#include "user_info.h"

class AuthorizationMenu: public IMenu, public Database
{
	const std::string table_name = "users";
public:
    static void registration(std::string*);
    void login(UserInfo&, std::string *ptr_values);
    int validation(const std::string* values, const int length) const;
	void output_menu();
	void choose_option();
};
