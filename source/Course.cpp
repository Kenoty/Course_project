#include "course.h"

void Course::read_only_names(unsigned int i) const
{

    std::cout << i << ". " << name << '\n';
}

void Course::set_name(const std::string_view value)
{
    this->name = value;
}

std::string Course::get_name() const
{
    return this->name;
}

void rate_the_course(Course& course)
{
    int temp;
    std::cout << "Rate this course from 0 to 5: ";
    std::cin >> temp;
    course.rating = (course.rating * course.number_of_votes + temp) / (course.number_of_votes + 1);
    course.number_of_votes++;
}

void Course::set_price(float value)
{
    this->price = value;
}

float Course::get_price() const
{
    return price;
}

void Course::set_rating(float value)
{
    this->rating = value;
}

float Course::get_rating() const
{
    return rating;
}

void Course::set_number_of_votes(int value)
{
    this->number_of_votes = value;
}

int Course::get_number_of_votes() const
{
    return number_of_votes;
}

std::ostream& operator << (std::ostream& os, const Course& course)
{
    return os << "Name: " << course.name << "\nPrice: " << course.price << "\nRating: " << course.rating << '\n';
}