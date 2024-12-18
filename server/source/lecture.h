#pragma once

#include <string>

#include "id.h"

class Lecture: public Id
{
    std::string lectureName;
	std::string material;
public:
    Lecture(std::string text = "", std::string link = "");
    void setLectureName(std::string_view);
    std::string getLectureName();
    void setMaterial(std::string_view);
    std::string getMaterial();
};
