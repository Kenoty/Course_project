#pragma once
#include <iostream>
#include <libpq-fe.h>

class Database
{
protected:
	const std::string conninfo;
public:
	Database(std::string info = "dbname = course_project_db user = postgres password = 200kv14R6200 port = 5432"): conninfo(info){}
	int get_nrows(const std::string& table_name, const std::string* field_names, const int length) const;
	int get_nfields(const std::string& table_name, const std::string* field_names, const int length) const;
	void insert_data(const std::string& table_name, const std::string& field_names, const std::string& values) const;
	void update_field(const std::string& table_name, const std::string& field_name, const std::string& value, const std::string& id) const;
	void delete_data(const std::string& table_name, const std::string& id) const;
	std::string* select_from_postgres(const std::string& table_name, const std::string* field_names, std::string* values, const int length);
	void get_info(std::string&);
};