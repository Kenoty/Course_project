#include "user_info.h"
#include "wallet.h"
#include "database.h"
#include "menu_interface.h"

class Student: public UserInfo, public Database, public IMenu
{
public:
	Student(): UserInfo(), Database(){}
	void find_course();
	void buy_course();
	void rate_course();
	void find_mentor();
	void rate_mentor();
	void get_access();
	void top_up_wallet();
};