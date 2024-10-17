#include <iostream>
#include <string>

class Product
{
    int id;
    std::string name = " ";
    float price = 0;
    float rating = 0;
    int number_of_votes = 0;
public:
    void set_id(int);
    int get_id();
    void read() const;
    void read_only_names(unsigned int) const;
    void set_name(std::string&);
    std::string& get_name();
    void set_price(float);
    float get_price();
    void set_rating(float);
    float get_rating();
    void set_number_of_votes(int);
    int get_number_of_votes();
    void rate_the_course();
    bool operator == (const Product& product) const = default;
    friend std::ostream& operator << (std::ostream&, const Product&);
};