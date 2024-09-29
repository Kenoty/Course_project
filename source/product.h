#include <string>
using namespace std;

class product
{
    string name;
    float price;
public:
    void read() const;
    void read_only_names(int) const;
    void set_name();
    void reset_name();
    float set_price();
    product* renew(product*, int&);
    product* remove(product*, int&, int);
};