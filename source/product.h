#include <iostream>
#include <string>

class Product
{
    std::string name = " ";
    float price = 0;
    float rating = 0;
    int number_of_votes = 0;
public:
    void read() const;
    void read_only_names(unsigned int) const;
    void set_name();
    float set_price();
    void rate_the_course();
};