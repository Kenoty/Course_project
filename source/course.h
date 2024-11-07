#include <iostream>
#include <string>
#include "id.h"
//#include "product_interface.h"

class Course: public Id//, public IProduct_database
{
    std::string name = " ";
    float price = 0;
    float rating = 0;
    int number_of_votes = 0;
public:
    void set_name(const std::string_view);
    std::string get_name() const;
    void set_price(float);
    float get_price() const;
    void set_rating(float);
    float get_rating() const;
    void set_number_of_votes(int);
    int get_number_of_votes() const;
    void read_only_names(unsigned int) const;
    friend void rate_the_course(Course&);
    bool operator == (const Course& course) const = default;
    friend std::ostream& operator << (std::ostream&, const Course&);
};