#include "authorization_menu.h"
#include <string>
#include <algorithm>

void AuthorizationMenu::registration()
{
    Database postgres;
    const std::string field_names[] = { "first_name", "second_name", "last_name", "email", "phone_number", "user_password", "role" };
    std::string values[] = { "first name", "second name", "last name", "email", "phone number", "password", "role" };

    for (int i = 0; i < size(values); i++)
        postgres.get_info(values[i]);

    std::string temp_fnames = "";
    std::string temp_values = "'";
    for (int i = 0; i < std::size(values); i++)
    {
        if (values[i] != "")
        {
            if (i != std::size(values) - 1)
            {
                temp_fnames = temp_fnames + field_names[i] + ", ";
                temp_values = temp_values + values[i] + "', '";
            }
            else
            {
                temp_fnames += field_names[i];
                temp_values += values[i] + "'";
            }
        }
    }

    postgres.insert_data(this->table_name, temp_fnames, temp_values);

    std::cout << "Registration was successful!" << std::endl << "Press enter to continue ";
    getchar();
}

void AuthorizationMenu::login(UserInfo& current_user)
{
    Database postgres;
    const std::string field_names[] = { "email", "user_password" };
    std::string values[] = { "email", "password" };

    for (int i = 0; i < size(values); i++)
        postgres.get_info(values[i]);

    while (!validation(field_names, values, std::size(values)))
    {
        std::cout << "Login fail. Try again" << std::endl;
        values[0] = "email";
        values[1] = "password";

        for (int i = 0; i < size(values); i++)
            postgres.get_info(values[i]);
    }
    std::string temp[] = { "*" };
    std::string user_data[8];
    postgres.select_from_postgres("users WHERE email = '" + values[0] + "'", temp, user_data, 1);
    current_user.set_id(std::stoi(user_data[0]));
    current_user.set_fname(user_data[1]);
    current_user.set_sname(user_data[2]);
    current_user.set_lname(user_data[3]);
    current_user.set_email(user_data[4]);
    current_user.set_phone_number(user_data[5]);
    current_user.set_user_password(user_data[6]);
    current_user.set_role(user_data[7]);
}

int AuthorizationMenu::validation(const std::string* field_names, const std::string* values, const int length) const
{
    PGconn* conn = PQconnectdb(this->conninfo.c_str());

    if (PQstatus(conn) != CONNECTION_OK)
    {
        std::cerr << "Connection to database failed: " << PQerrorMessage(conn) << std::endl;
        PQfinish(conn);
        return -1;
    }

    std::string temp_fnames = "";
    for (int i = 0; i < length; i++)
    {
        if (i != length - 1)
            temp_fnames = temp_fnames + field_names[i] + ", ";
        else
            temp_fnames += field_names[i];
    }

    std::string sql = "SELECT " + temp_fnames + " FROM " + this->table_name + ";";

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

void  AuthorizationMenu::output_menu()
{
    system("cls");
    std::cout << "Welcome to the learning management system\n";
    std::cout << "Select the number of the action you want to perform:\n";
    std::cout << "1. Login\n";
    std::cout << "2. Registration\n";
    std::cout << "3. Exit\n";
}

//void Authorization_menu::choose_option(User_info& guest)
//{
//    int action = 0;
//    while (action != 3)
//    {
//        switch (action)
//        {
//        case 0:
//            output_menu();
//            std::cin >> action;
//            break;
//        case 1:
//            login(guest);
//            action = 3;
//            break;
//        case 2:
//            registration();
//            action = 0;
//            break;
//        default:
//            std::cout << "Input error, try again: ";
//            std::cin >> action;
//        }
//    }
//}

void AuthorizationMenu::choose_option()
{
    return IMenu::choose_option();
}