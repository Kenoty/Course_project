#include "product.h"

void Product::set_id(int id)
{
    this->id = id;
}

int Product::get_id()
{
    return this->id;
}

void Product::read() const
{
    std::cout << "Name: " << name << "\nPrice: " << price << "\nRating: " << rating << '\n';
}

void Product::read_only_names(unsigned int i) const
{

    std::cout << i << ". " << name << '\n';
}

void Product::set_name(std::string& name)
{
    this->name = name;
}

std::string& Product::get_name()
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

void Product::set_price(float price)
{
    this->price = price;
}

float Product::get_price()
{
    return price;
}

void Product::set_rating(float rating)
{
    this->rating = rating;
}

float Product::get_rating()
{
    return rating;
}

void Product::set_number_of_votes(int number_of_votes)
{
    this->number_of_votes = number_of_votes;
}

int Product::get_number_of_votes()
{
    return number_of_votes;
}

std::ostream& operator << (std::ostream& os, const Product& product)
{
    return os << "Name: " << product.name << "\nPrice: " << product.price << "\nRating: " << product.rating << '\n';
}