#include "product.h"

void Product::read_only_names(unsigned int i) const
{

    std::cout << i << ". " << name << '\n';
}

void Product::set_name(const std::string& value)
{
    this->name = value;
}

std::string Product::get_name() const
{
    return this->name;
}

void rate_the_course(Product& course)
{
    int temp;
    std::cout << "Rate this course from 0 to 5: ";
    std::cin >> temp;
    course.rating = (course.rating * course.number_of_votes + temp) / (course.number_of_votes + 1);
    course.number_of_votes++;
}

void Product::set_price(float value)
{
    this->price = value;
}

float Product::get_price() const
{
    return price;
}

void Product::set_rating(float value)
{
    this->rating = value;
}

float Product::get_rating() const
{
    return rating;
}

void Product::set_number_of_votes(int value)
{
    this->number_of_votes = value;
}

int Product::get_number_of_votes() const
{
    return number_of_votes;
}

std::ostream& operator << (std::ostream& os, const Product& product)
{
    return os << "Name: " << product.name << "\nPrice: " << product.price << "\nRating: " << product.rating << '\n';
}