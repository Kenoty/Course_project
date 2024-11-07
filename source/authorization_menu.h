#include "database.h"
#include "menu_interface.h"
#include "user_info.h"

class Authorization_menu: public IMenu, public Database
{
	const std::string table_name = "users";
public:
	void registration();
	void login(User_info&);
	int validation(const std::string* field_names, const std::string* values, const int length) const;
	void output_menu();
};