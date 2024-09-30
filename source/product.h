#include <string>
using namespace std;

class product
{
    string name;
    float price;
    float rating = 0;
    int number_of_votes = 0;
public:
    void read() const;
    void read_only_names(int) const;
    void set_name();
    void reset_name();
    float set_price();
    void rate_the_course();
    void increase(product*, int&);
    void remove_course(product* courses, int& amount, int order);
};