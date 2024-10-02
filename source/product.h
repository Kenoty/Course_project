#include <iostream>
#include <string>

class product
{
    std::string name;
    float price;
    float rating = 0;
    int number_of_votes = 0;
public:
    void read() const;
    void read_only_names(unsigned int) const;
    void set_name();
    void reset_name();
    float set_price();
    void rate_the_course();
    void increase(product* courses, unsigned int& amount);
    void remove_course(product* courses, unsigned int& amount, int order);
};