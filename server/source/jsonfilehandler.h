#include <iostream>
#include <fstream>
#include <nlohmann/json.hpp>

class JsonFileHandler
{
public:
    void writeJson(const std::string& filename, std::string *values, const int &size);
};
