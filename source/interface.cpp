#include "interface.h"

void get_info(std::string& field)
{
    std::cout << "Enter your " + field + ": ";
    rewind(stdin);
    if (field != "last name")
    {
        std::getline(std::cin, field);
        while (field == "")
        {
            std::cout << "It cannot be empty. Try again: ";
            rewind(stdin);
            std::getline(std::cin, field);
        }
    }
    else
        std::getline(std::cin, field);

}

void registration()
{
    const std::string conninfo = "dbname = course_project_db user = postgres password = 200kv14R6200 port = 5432";
    const std::string field_names[] = {"first_name", "second_name", "last_name", "email", "phone_number", "user_password"};
    std::string values[] = {"first name", "second name", "last name", "email", "phone number", "password"};

    for (int i = 0; i < std::size(values); i++)
        get_info(values[i]);

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

    insert_data(conninfo, "users", temp_fnames, temp_values);

    std::cout << "Registration was successful!" << std::endl << "Press enter to continue ";
    getchar();
}

void login(User& current_user)
{
    const std::string conninfo = "dbname = course_project_db user = postgres password = 200kv14R6200 port = 5432";
    const std::string field_names[] = {"email", "user_password"};
    std::string values[] = {"email", "password"};

    for (int i = 0; i < std::size(values); i++)
        get_info(values[i]);

    while (!check_credentials(conninfo, "users", field_names, values, std::size(values)))
    {
        std::cout << "Login fail. Try again" << std::endl;
        values[0] = "email";
        values[1] = "password";
        for (int i = 0; i < std::size(values); i++)
            get_info(values[i]);
    }
    std::cout << "Login was succesful!";
    std::string temp[] = {"*"};
    std::string user_data[7];
    select_from_postgres(conninfo, "users WHERE email = '" + values[0] + "'", temp, user_data, 1);
    current_user.set_id((std::stoi(user_data[0])));
    current_user.set_fname(user_data[1]);
    current_user.set_sname(user_data[2]);
    current_user.set_lname(user_data[3]);
    current_user.set_email(user_data[4]);
    current_user.set_phone_number(user_data[5]);
    current_user.set_user_password(user_data[6]);
}

void insert_data(const std::string& conninfo, const std::string& table_name, const std::string& field_names, const std::string& values)
{
    PGconn* conn = PQconnectdb(conninfo.c_str());

    if (PQstatus(conn) != CONNECTION_OK)
    {
        std::cerr << "Connection to database failed: " << PQerrorMessage(conn) << std::endl;
        PQfinish(conn);
        return;
    }

    std::string sql = "INSERT INTO " + table_name + " (" + field_names + ") VALUES (" + values + ");";

    PGresult* res = PQexec(conn, sql.c_str());

    if (PQresultStatus(res) != PGRES_COMMAND_OK)
        std::cerr << "Insert failed: " << PQerrorMessage(conn) << std::endl;
    else
        std::cout << "Insert succesful" << std::endl;

    PQclear(res);
    PQfinish(conn);
}

int check_credentials(const std::string& conninfo, const std::string& table_name, const std::string* field_names, const std::string* values, const int length)
{
    PGconn* conn = PQconnectdb(conninfo.c_str());

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

    std::string sql = "SELECT " + temp_fnames + " FROM " + table_name + ";";

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

std::string* select_from_postgres(const std::string& conninfo, const std::string& table_name, const std::string* field_names, std::string* values, const int length)
{
    PGconn* conn = PQconnectdb(conninfo.c_str());

    if (PQstatus(conn) != CONNECTION_OK)
    {
        std::cerr << "Connection to database failed: " << PQerrorMessage(conn) << std::endl;
        PQfinish(conn);
        return nullptr;
    }

    std::cout << "Connection to the database succesfully! " << std::endl;

    std::string temp_fnames = "";
    for (int i = 0; i < length; i++)
    {
        if (i != length - 1)
            temp_fnames = temp_fnames + field_names[i] + ", ";
        else
            temp_fnames += field_names[i];
    }

    std::string sql = "SELECT " + temp_fnames + " FROM " + table_name + ";";

    PGresult* res = PQexec(conn, sql.c_str());

    if (PQresultStatus(res) != PGRES_TUPLES_OK)
    {
        std::cerr << "SELECT FAILED: " << PQerrorMessage(conn) << std::endl;
        PQclear(res);
        PQfinish(conn);
        return nullptr;
    }

    int nrows = PQntuples(res);
    int nfields = PQnfields(res);
    int count = 0;
    for (int i = 0; i < nrows; i++)
    {
        for (int j = 0; j < nfields; j++)
            values[count++] = PQgetvalue(res, i, j);
    }

    PQclear(res);
    PQfinish(conn);
    return values;
}

int get_nrows(const std::string& conninfo, const std::string& table_name, const std::string* field_names, const int length)
{
    PGconn* conn = PQconnectdb(conninfo.c_str());

    if (PQstatus(conn) != CONNECTION_OK)
    {
        std::cerr << "Connection to database failed: " << PQerrorMessage(conn) << std::endl;
        PQfinish(conn);
        return 0;
    }

    std::cout << "Connection to the database succesfully! " << std::endl;

    std::string temp_fnames = "";
    for (int i = 0; i < length; i++)
    {
        if (i != length - 1)
            temp_fnames = temp_fnames + field_names[i] + ", ";
        else
            temp_fnames += field_names[i];
    }

    std::string sql = "SELECT " + temp_fnames + " FROM " + table_name + ";";

    PGresult* res = PQexec(conn, sql.c_str());

    if (PQresultStatus(res) != PGRES_TUPLES_OK)
    {
        std::cerr << "SELECT FAILED: " << PQerrorMessage(conn) << std::endl;
        PQclear(res);
        PQfinish(conn);
        return 0;
    }

    int nrows = PQntuples(res);
    PQclear(res);
    PQfinish(conn);
    return nrows;
}

int get_nfields(const std::string& conninfo, const std::string& table_name, const std::string* field_names, const int length)
{
    PGconn* conn = PQconnectdb(conninfo.c_str());

    if (PQstatus(conn) != CONNECTION_OK)
    {
        std::cerr << "Connection to database failed: " << PQerrorMessage(conn) << std::endl;
        PQfinish(conn);
        return 0;
    }

    std::cout << "Connection to the database succesfully! " << std::endl;

    std::string temp_fnames = "";
    for (int i = 0; i < length; i++)
    {
        if (i != length - 1)
            temp_fnames = temp_fnames + field_names[i] + ", ";
        else
            temp_fnames += field_names[i];
    }

    std::string sql = "SELECT " + temp_fnames + " FROM " + table_name + ";";

    PGresult* res = PQexec(conn, sql.c_str());

    if (PQresultStatus(res) != PGRES_TUPLES_OK)
    {
        std::cerr << "SELECT FAILED: " << PQerrorMessage(conn) << std::endl;
        PQclear(res);
        PQfinish(conn);
        return 0;
    }

    int nfields = PQnfields(res);
    PQclear(res);
    PQfinish(conn);
    return nfields;
}

void update_field(const std::string& conninfo, const std::string& table_name, const std::string& field_name, const std:: string& value, const std::string& id)
{
    PGconn* conn = PQconnectdb(conninfo.c_str());

    if (PQstatus(conn) != CONNECTION_OK)
    {
        std::cerr << "Connection to database failed: " << PQerrorMessage(conn) << std::endl;
        PQfinish(conn);
        return;
    }

    std::string sql = "UPDATE " + table_name + " SET " + field_name + " = " + value + " WHERE id = " + id + ";";

    PGresult* res = PQexec(conn, sql.c_str());

    if (PQresultStatus(res) != PGRES_COMMAND_OK)
        std::cerr << "Update failed: " << PQerrorMessage(conn) << std::endl;
    else
        std::cout << "Update succesful" << std::endl;

    PQclear(res);
    PQfinish(conn);
}

void delete_data(const std::string& conninfo, const std::string& table_name, const std::string& id)
{
    PGconn* conn = PQconnectdb(conninfo.c_str());

    if (PQstatus(conn) != CONNECTION_OK)
    {
        std::cerr << "Connection to database failed: " << PQerrorMessage(conn) << std::endl;
        PQfinish(conn);
        return;
    }

    std::string sql = "DELETE FROM " + table_name + " WHERE id = " + id + ";";

    PGresult* res = PQexec(conn, sql.c_str());

    if (PQresultStatus(res) != PGRES_COMMAND_OK)
        std::cerr << "Delete failed: " << PQerrorMessage(conn) << std::endl;
    else
        std::cout << "Delete succesful" << std::endl;

    PQclear(res);
    PQfinish(conn);
}

void routine()
{
    std::cout << "\nPress enter to continue";
    rewind(stdin);
    getchar();
}

void create_the_product(List<Product>& courses, User& user)
{
    const std::string conninfo = "dbname = course_project_db user = postgres password = 200kv14R6200 port = 5432";
    const std::string field_names = {"name, price, user_id"};
    std::string values[] = {"course name", "course price", std::to_string(get_user_id(user))};

    for (int i = 0; i < std::size(values) - 1; i++)
        get_info(values[i]);
    std::string temp = "'" + values[0] + "', '" + values[1] + "', " + values[2];
    insert_data(conninfo, "courses", field_names, temp);
    routine();
}

void get_product_info(List<Product>& courses, User& user)
{
    const std::string conninfo = "dbname = course_project_db user = postgres password = 200kv14R6200 port = 5432";
    const std::string field_names[] = { "name", "price", "rating", "number_of_votes", "id" };

    const int nrows = get_nrows(conninfo, "courses WHERE user_id = " + std::to_string(get_user_id(user)), field_names, std::size(field_names));
    const int nfields = get_nfields(conninfo, "courses WHERE user_id = " + std::to_string(get_user_id(user)), field_names, std::size(field_names));

    std::string* temp = new std::string[nrows * nfields];

    temp = select_from_postgres(conninfo, "courses WHERE user_id = " + std::to_string(get_user_id(user)), field_names, temp, std::size(field_names));

    if (courses.get_size() != 0)
        courses.clear();
    int count = 0;
    for (int i = 0; i < nrows; i++)
    {
        courses.push_back();
        courses[i].set_name(temp[count++]);
        courses[i].set_price(std::stof(temp[count++]) / 100);
        courses[i].set_rating(std::stof(temp[count++]) / 100);
        courses[i].set_number_of_votes(std::stoi(temp[count++]));
        courses[i].set_id(std::stoi(temp[count++]));
    }

    delete[] temp;
}

void output_product_info(List<Product>& courses, User& user)
{
    for (int i = 0; i < courses.get_size(); i++)
    {
        std::cout << "Product number " << i + 1 << '\n';
        std::cout << courses[i];
    }
    routine();
}

void rate_product(List<Product>& courses)
{
    int order;
    std::cout << "\vWhat product you want to rate:\n";
    for (int i = 0; i < courses.get_size(); i++)
        courses[i].read_only_names(i + 1);
    std::cin >> order;
    order--;
    rate_the_course(courses[order]);

    const std::string conninfo = "dbname = course_project_db user = postgres password = 200kv14R6200 port = 5432";
    const std::string field_names[] = {"rating", "number_of_votes"};

    update_field(conninfo, "courses", field_names[0], std::to_string(courses[order].get_rating() * 100), std::to_string(courses[order].get_id()));
    update_field(conninfo, "courses", field_names[1], std::to_string(courses[order].get_number_of_votes()), std::to_string(courses[order].get_id()));
    routine();
}

void update_info(List<Product>& courses)
{
    int order;
    int token;
    std::cout << "\vWhat product you want to update:\n";
    for (int i = 0; i < courses.get_size(); i++)
        courses[i].read_only_names(i + 1);
    std::cin >> order;
    order--;
    std::cout << "What you want to update:\n";
    std::cout << "1. Name of the product:\n";
    std::cout << "2. Price of the product:\n";
    std::cin >> token;

    const std::string conninfo = "dbname = course_project_db user = postgres password = 200kv14R6200 port = 5432";
    const std::string field_names[] = {"name", "price"};
    if (token == 1)
    {
        std::cout << "Enter new name: ";
        std::string temp;
        rewind(stdin);
        getline(std::cin, temp);
        courses[order].set_name(temp);
        update_field(conninfo, "courses", field_names[0], "'" + courses[order].get_name() + "'", std::to_string(courses[order].get_id()));
    }
    else
    {
        std::cout << "Enter new price: ";
        float temp;
        std::cin >> temp;
        courses[order].set_price(temp);
        update_field(conninfo, "courses", field_names[1], std::to_string(courses[order].get_price() * 100), std::to_string(courses[order].get_id()));
    }
    routine();
}

void delete_product(List<Product>& courses)
{
    int order;
    const std::string conninfo = "dbname = course_project_db user = postgres password = 200kv14R6200 port = 5432";
    if (courses.get_size() != 0)
    {
        std::cout << "\vWhat product you want to delete:\n";
        for (int i = 0; i < courses.get_size(); i++)
            courses[i].read_only_names(i + 1);
        std::cin >> order;
        order--;
        delete_data(conninfo, "courses", std::to_string(courses[order].get_id()));
        courses.remove_object(order);
    }
    else
        std::cout << "Courses are already do not exist\n";
    routine();
}

void check_on_copies(List<Product> courses)
{
    for (int i = 0; i < courses.get_size(); i++)
        for (int j = i + 1; j < courses.get_size(); j++)
            if (courses[i] == courses[j])
            {
                std::cout << "There is copy of the product in list";
                routine();
                return;
            }
    std::cout << "There is no copies of the products in list";
    routine();
}