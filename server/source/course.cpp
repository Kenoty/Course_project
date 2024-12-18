#include "course.h"

void Course::readOnlyNames(unsigned int i) const
{

    std::cout << i << ". " << name << '\n';
}

List<Lecture>& Course::getLecturesList()
{
    return lectures;
}

void Course::setName(const std::string_view value)
{
    this->name = value;
}

std::string Course::getName() const
{
    return this->name;
}

void rateTheCourse(Course& course)
{
    int temp;
    std::cout << "Rate this course from 0 to 5: ";
    std::cin >> temp;
    course.rating = (course.rating * course.numberOfVotes + temp) / (course.numberOfVotes + 1);
    course.numberOfVotes++;
}

void Course::setPrice(float value)
{
    this->price = value;
}

float Course::getPrice() const
{
    return price;
}

void Course::setRating(float value)
{
    this->rating = value;
}

float Course::getRating() const
{
    return rating;
}

void Course::setNumberOfVotes(int value)
{
    this->numberOfVotes = value;
}

int Course::getNumberOfVotes() const
{
    return numberOfVotes;
}

std::ostream& operator << (std::ostream& os, const Course& course)
{
    return os << "Name: " << course.name << "\nPrice: " << course.price << "\nRating: " << course.rating << '\n';
}
