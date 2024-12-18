#include <string>

class Filters
{
private:
    std::string fname = "";
    std::string sname = "";
    std::string lname = "";
    std::string email = "";
    std::string phone = "";

public:
    void setFname(std::string);
    void setSname(std::string);
    void setLname(std::string);
    void setEmail(std::string);
    void setPhone(std::string);
    std::string createFiltersKit();
};
