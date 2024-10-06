#include <iostream>
#include <string>

class Product
{
    std::string name;
    float price;
    float rating;
    int number_of_votes;
public:
    Product()
    {
        name = " ";
        price = 0;
        rating = 0;
        number_of_votes = 0;
    }
    void read() const;
    void read_only_names(unsigned int) const;
    void set_name();
    float set_price();
    void rate_the_course();
};