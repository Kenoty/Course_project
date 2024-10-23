#include <iostream>
#include <libpq-fe.h>

class Database
{
	const std::string conninfo = "dbname = course_project_db user = postgres password = 200kv14R6200 port = 5432";
public:
	int get_nrows(const std::string& table_name, const std::string* field_names, const int length);
	int get_nfields(const std::string& table_name, const std::string* field_names, const int length);
	void insert_data(const std::string& table_name, const std::string& field_names, const std::string& values);
	int validation(const std::string& table_name, const std::string* field_names, const std::string* values, const int length);
	void update_field(const std::string& table_name, const std::string& field_name, const std::string& value, const std::string& id);
	void delete_data(const std::string& table_name, const std::string& id);
	std::string* select_from_postgres(const std::string& table_name, const std::string* field_names, std::string* values, const int length);
};