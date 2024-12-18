#include "database.h"
#include <string>

int Database::getNrows(const std::string& tableName, const std::string* fieldNames, const int length) const
{
    PGconn* conn = PQconnectdb(this->conninfo.c_str());

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
            temp_fnames = temp_fnames + fieldNames[i] + ", ";
        else
            temp_fnames += fieldNames[i];
    }

    std::string sql = "SELECT " + temp_fnames + " FROM " + tableName + ";";

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

int Database::getNfields(const std::string& table_name, const std::string* field_names, const int length) const
{
    PGconn* conn = PQconnectdb(this->conninfo.c_str());

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

void Database::insertData(const std::string& table_name, const std::string& field_names, const std::string& values) const
{
    PGconn* conn = PQconnectdb(this->conninfo.c_str());

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

void Database::updateField(const std::string& table_name, const std::string& field_name, const std::string& value, const std::string& id) const
{
    PGconn* conn = PQconnectdb(this->conninfo.c_str());

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

void Database::deleteData(const std::string& table_name, const std::string& id) const
{
    PGconn* conn = PQconnectdb(this->conninfo.c_str());

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

std::string* Database::selectFromPostgres(const std::string& table_name, const std::string* field_names, std::string* values, const int length)
{
    PGconn* conn = PQconnectdb(this->conninfo.c_str());

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

void Database::getInfo(std::string& field)
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
