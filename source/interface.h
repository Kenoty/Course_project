#include "product.h"
#include "list.h"
#include "user.h"

//Authorization
void registration();
void login(User&);
void get_info(std::string&);

//Course management
void routine();
void create_the_product(List<Product>&, User& user);
void output_product_info(List<Product>&);
void rate_product(List<Product>&);
void update_info(List<Product>&);
void delete_product(List<Product>&);
void get_product_info(List<Product>&, User&);