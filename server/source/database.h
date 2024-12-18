#pragma once
#include <iostream>
#include <libpq-fe.h>

class Database
{
protected:
	const std::string conninfo;
public:
	Database(std::string info = "dbname = course_project_db user = postgres password = 200kv14R6200 port = 5432"): conninfo(info){}
    int getNrows(const std::string& tableName, const std::string* fieldNames, const int length) const;
    int getNfields(const std::string& tableName, const std::string* fieldNames, const int length) const;
    void insertData(const std::string& tableName, const std::string& fieldNames, const std::string& values) const;
    void updateField(const std::string& tableName, const std::string& fieldName, const std::string& value, const std::string& id) const;
    void deleteData(const std::string& tableName, const std::string& id) const;
    std::string* selectFromPostgres(const std::string& tableName, const std::string* fieldNames, std::string* values, const int length);
    void getInfo(std::string&);
};
