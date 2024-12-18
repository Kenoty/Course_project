#include "database.h"
#include "menu_interface.h"
#include "user_info.h"

class AuthorizationMenu: public IMenu, public Database
{
    const std::string tableName = "users";
public:
    static void registration(std::string*);
    void login(UserInfo&, std::string *ptrValues);
    int validation(const std::string* values, const int length) const;
    void outputMenu();
    void chooseOption();
};
