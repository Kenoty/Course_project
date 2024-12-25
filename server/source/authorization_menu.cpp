#include "authorization_menu.h"
#include <string>

void AuthorizationMenu::registration(std::string* values)
{
    Database postgres;
    const std::string fieldNames[] = { "first_name", "second_name", "last_name", "email", "phone_number", "user_password", "role" };

    std::string tempFnames = "";
    std::string tempValues = "'";
    for (int i = 0; i < std::size(fieldNames); i++)
    {
        if (values[i] != "")
        {
            if (i != std::size(fieldNames) - 1)
            {
                tempFnames = tempFnames + fieldNames[i] + ", ";
                tempValues = tempValues + values[i] + "', '";
            }
            else
            {
                tempFnames += fieldNames[i];
                tempValues += values[i] + "'";
            }
        }
    }

    postgres.insertData("users", tempFnames, tempValues);

    std::cout << "Registration was successful!" << std::endl;
}

void AuthorizationMenu::login(UserInfo& currentUser, std::string *ptr_values)
{
    Database postgres;
    const std::string fieldNames[] = {"email", "user_password"};

    std::string temp[] = { "*" };
    std::string userData[8];
    postgres.selectFromPostgres("users WHERE email = '" + ptr_values[0] + "'", temp, userData, 1);
    currentUser.setId(std::stoi(userData[0]));
    currentUser.setFname(userData[1]);
    currentUser.setSname(userData[2]);
    currentUser.setLname(userData[3]);
    currentUser.setEmail(userData[4]);
    currentUser.setPhoneNumber(userData[5]);
    currentUser.setUserPassword(userData[6]);
    currentUser.setRole(userData[7]);
}

int AuthorizationMenu::validation(const std::string* values, const int length) const
{
    const std::string fieldNames[] = {"email", "user_password"};

    PGconn* conn = PQconnectdb(this->conninfo.c_str());

    if (PQstatus(conn) != CONNECTION_OK)
    {
        std::cerr << "Connection to database failed: " << PQerrorMessage(conn) << std::endl;
        PQfinish(conn);
        return -1;
    }

    std::string tempFnames = "";
    for (int i = 0; i < length; i++)
    {
        if (i != length - 1)
            tempFnames = tempFnames + fieldNames[i] + ", ";
        else
            tempFnames += fieldNames[i];
    }

    std::string sql = "SELECT " + tempFnames + " FROM " + this->tableName + ";";

    PGresult* res = PQexec(conn, sql.c_str());

    if (PQresultStatus(res) != PGRES_TUPLES_OK)
    {
        std::cerr << "SELECT FAILED: " << PQerrorMessage(conn) << std::endl;
        PQclear(res);
        PQfinish(conn);
        return -1;
    }

    int nrows = PQntuples(res);
    for (int i = 0; i < nrows; i++)
        if (values[0] == PQgetvalue(res, i, 0) && values[1] == PQgetvalue(res, i, 1))
        {
            PQclear(res);
            PQfinish(conn);
            return 1;
        }

    PQclear(res);
    PQfinish(conn);
    return 0;
}

void  AuthorizationMenu::outputMenu()
{
    system("cls");
    std::cout << "Welcome to the learning management system\n";
    std::cout << "Select the number of the action you want to perform:\n";
    std::cout << "1. Login\n";
    std::cout << "2. Registration\n";
    std::cout << "3. Exit\n";
}

void AuthorizationMenu::chooseOption()
{
    return IMenu::chooseOption();
}
