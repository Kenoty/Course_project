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

    std::string tempFnames = "";
    for (int i = 0; i < length; i++)
    {
        if (i != length - 1)
            tempFnames = tempFnames + fieldNames[i] + ", ";
        else
            tempFnames += fieldNames[i];
    }

    std::string sql = "SELECT " + tempFnames + " FROM " + tableName + ";";

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

int Database::getNfields(const std::string& tableName, const std::string* fieldNames, const int length) const
{
    PGconn* conn = PQconnectdb(this->conninfo.c_str());

    if (PQstatus(conn) != CONNECTION_OK)
    {
        std::cerr << "Connection to database failed: " << PQerrorMessage(conn) << std::endl;
        PQfinish(conn);
        return 0;
    }

    std::string tempFnames = "";
    for (int i = 0; i < length; i++)
    {
        if (i != length - 1)
            tempFnames = tempFnames + fieldNames[i] + ", ";
        else
            tempFnames += fieldNames[i];
    }

    std::string sql = "SELECT " + tempFnames + " FROM " + tableName + ";";

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

void Database::insertData(const std::string& tableName, const std::string& fieldNames, const std::string& values) const
{
    PGconn* conn = PQconnectdb(this->conninfo.c_str());

    if (PQstatus(conn) != CONNECTION_OK)
    {
        std::cerr << "Connection to database failed: " << PQerrorMessage(conn) << std::endl;
        PQfinish(conn);
        return;
    }

    std::string sql = "INSERT INTO " + tableName + " (" + fieldNames + ") VALUES (" + values + ");";

    PGresult* res = PQexec(conn, sql.c_str());

    if (PQresultStatus(res) != PGRES_COMMAND_OK)
        std::cerr << "Insert failed: " << PQerrorMessage(conn) << std::endl;
    else
        std::cout << "Insert succesful" << std::endl;

    PQclear(res);
    PQfinish(conn);
}

void Database::updateField(const std::string& tableName, const std::string& field_name, const std::string& value, const std::string& id) const
{
    PGconn* conn = PQconnectdb(this->conninfo.c_str());

    if (PQstatus(conn) != CONNECTION_OK)
    {
        std::cerr << "Connection to database failed: " << PQerrorMessage(conn) << std::endl;
        PQfinish(conn);
        return;
    }

    std::string sql = "UPDATE " + tableName + " SET " + field_name + " = " + value + " WHERE id = " + id + ";";

    PGresult* res = PQexec(conn, sql.c_str());

    if (PQresultStatus(res) != PGRES_COMMAND_OK)
        std::cerr << "Update failed: " << PQerrorMessage(conn) << std::endl;
    else
        std::cout << "Update succesful" << std::endl;

    PQclear(res);
    PQfinish(conn);
}

void Database::deleteData(const std::string& tableName, const std::string& id) const
{
    PGconn* conn = PQconnectdb(this->conninfo.c_str());

    if (PQstatus(conn) != CONNECTION_OK)
    {
        std::cerr << "Connection to database failed: " << PQerrorMessage(conn) << std::endl;
        PQfinish(conn);
        return;
    }

    std::string sql = "DELETE FROM " + tableName + " WHERE id = " + id + ";";

    PGresult* res = PQexec(conn, sql.c_str());

    if (PQresultStatus(res) != PGRES_COMMAND_OK)
        std::cerr << "Delete failed: " << PQerrorMessage(conn) << std::endl;
    else
        std::cout << "Delete succesful" << std::endl;

    PQclear(res);
    PQfinish(conn);
}

std::string* Database::selectFromPostgres(const std::string& tableName, const std::string* fieldNames, std::string* values, const int length)
{
    PGconn* conn = PQconnectdb(this->conninfo.c_str());

    if (PQstatus(conn) != CONNECTION_OK)
    {
        std::cerr << "Connection to database failed: " << PQerrorMessage(conn) << std::endl;
        PQfinish(conn);
        return nullptr;
    }

    std::string tempFnames = "";
    for (int i = 0; i < length; i++)
    {
        if (i != length - 1)
            tempFnames = tempFnames + fieldNames[i] + ", ";
        else
            tempFnames += fieldNames[i];
    }

    std::string sql = "SELECT " + tempFnames + " FROM " + tableName + ";";

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

std::vector<std::string> Database::selectFromPostgre(const std::string &tableName, const std::string *fieldNames, const int length)
{
    PGconn* conn = PQconnectdb(this->conninfo.c_str());

    if (PQstatus(conn) != CONNECTION_OK)
    {
        std::cerr << "Connection to database failed: " << PQerrorMessage(conn) << std::endl;
        PQfinish(conn);
        return std::vector<std::string>();
    }

    std::string tempFnames = "";
    for (int i = 0; i < length; i++)
    {
        if (i != length - 1)
            tempFnames = tempFnames + fieldNames[i] + ", ";
        else
            tempFnames += fieldNames[i];
    }

    std::string sql = "SELECT " + tempFnames + " FROM " + tableName + ";";

    PGresult* res = PQexec(conn, sql.c_str());

    if (PQresultStatus(res) != PGRES_TUPLES_OK)
    {
        std::cerr << "SELECT FAILED: " << PQerrorMessage(conn) << std::endl;
        PQclear(res);
        PQfinish(conn);
        return std::vector<std::string>();
    }

    int nrows = PQntuples(res);
    int nfields = PQnfields(res);

    std::vector<std::string> vector;

    int count = 0;
    for (int i = 0; i < nrows; i++)
    {
        for (int j = 0; j < nfields; j++)
            vector.push_back(PQgetvalue(res, i, j));
    }

    PQclear(res);
    PQfinish(conn);
    return vector;
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
