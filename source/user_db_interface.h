#include <iostream>

class user_db_interface
{
public:
	void insert_data(const std::string& table_name, const std::string& field_names, const std::string& values) const;
	int validation(const std::string& table_name, const std::string* field_names, const std::string* values, const int length) const;
	void update_field(const std::string& table_name, const std::string& field_name, const std::string& value, const std::string& id) const;
	void delete_data(const std::string& table_name, const std::string& id) const;
	std::string* select_from_postgres(const std::string& table_name, const std::string* field_names, std::string* values, const int length);
};