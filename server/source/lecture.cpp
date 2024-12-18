#include "lecture.h"

Lecture::Lecture(std::string name, std::string text): Id(), lectureName(name), material(text){}

void Lecture::setMaterial(std::string_view text)
{
    this->material = text;
}

std::string Lecture::getMaterial()
{
    return material;
}

void Lecture::setLectureName(std::string_view link)
{
    this->lectureName = link;
}

std::string Lecture::getLectureName()
{
    return lectureName;
}
