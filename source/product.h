#include <iostream>
#include <string>
#include "id.h"

class Product: public Id
{
    std::string name = " ";
    float price = 0;
    float rating = 0;
    int number_of_votes = 0;
public:
    void set_name(std::string&);
    std::string& get_name();
    void set_price(float);
    float get_price();
    void set_rating(float);
    float get_rating();
    void set_number_of_votes(int);
    int get_number_of_votes();
    void read_only_names(unsigned int) const;
    void friend rate_the_course(Product&);
    bool operator == (const Product& product) const = default;
    friend std::ostream& operator << (std::ostream&, const Product&);
};