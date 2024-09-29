class product
{
    char* name;
    float price;
public:
   /* product()
    {
        name = new char[1];
        price = 0;
    };*/
   /* ~product()
    {
        delete[] name;
    }*/
    void read() const;
    void read_only_names(int) const;
    char* set_name();
    char* reset_name();
    float set_price();
    product* renew(product*, int&);
    product* remove(product*, int&, int);
};