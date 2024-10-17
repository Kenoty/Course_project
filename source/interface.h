#include "product.h"
#include "list.h"
#include <libpq-fe.h>
#include "user.h"

//Authorization
void registration();
void login(User&);
void get_info(std::string&);

//Course management
void routine();
void create_the_product(List<Product>&, User& user);
void output_product_info(List<Product>&, User& user);
void rate_product(List<Product>&);
void update_info(List<Product>&);
void delete_product(List<Product>&);
void check_on_copies(List<Product>);
void get_product_info(List<Product>&, User&);

//PostgreSQL interfaces
void insert_data(const std::string& conninfo, const std::string& table_name, const std::string& field_names, const std::string& values);
int check_credentials(const std::string& conninfo, const std::string& table_name, const std::string* field_names, const std::string* values, const int length);
void update_field(const std::string& conninfo, const std::string& table_name, const std::string& field_name, const std::string& value, const std::string& id);
void delete_data(const std::string& conninfo, const std::string& table_name, const std::string& id);
std::string* select_from_postgres(const std::string& conninfo, const std::string& table_name, const std::string* field_names, std::string* values, const int length);