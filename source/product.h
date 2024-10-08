#include <iostream>
#include <string>

class Product
{
    std::string name = " ";
    float price = 0;
    float rating = 0;
    int number_of_votes = 0;
public:
    Product(std::string name = " ", float price = 0, float rating = 0, int number_of_votes = 0)
    {
        this->name = name;
        this->price = price;
        this->rating = rating;
        this->number_of_votes = number_of_votes;
    }
    void read() const;
    void read_only_names(unsigned int) const;
    void set_name();
    float set_price();
    void rate_the_course();
};