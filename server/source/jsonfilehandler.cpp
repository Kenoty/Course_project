#include "jsonfilehandler.h"

void JsonFileHandler::writeJson(const std::string &fileName, std::string *values, const int &size)
{
    std::ofstream outputFile(fileName);
    if (outputFile.is_open())
    {
        int counter = 0;
        for(int i = 0; i < size; i++)
        {
            nlohmann::json jsonData;
            jsonData["first_name"] = values[counter++];
            jsonData["second_name"] = values[counter++];
            jsonData["last_name"] = values[counter++];
            jsonData["email"] = values[counter++];
            jsonData["phone_number"] = values[counter++];
            outputFile << jsonData.dump(4);
        }
        outputFile.close();
    }
    else
    {
        std::cerr << "Failed to open file for writing: " << fileName << std::endl;
    }
}
