#include "product.h"

void Product::read() const
{
    std::cout << "Name: " << name << "\nPrice: " << price << "\nRating: " << rating << '\n';
}

void Product::read_only_names(unsigned int i) const
{

    std::cout << i << ". " << name << '\n';
}

void Product::set_name()
{
    std::cout << "Enter product name: ";
    rewind(stdin);
    std::getline(std::cin, name);
}

void Product::rate_the_course()
{
    int temp;
    std::cout << "Rate this course from 0 to 5: ";
    std::cin >> temp;
    rating = (rating * number_of_votes + temp) / (number_of_votes + 1);
    number_of_votes++;
}

float Product::set_price()
{
    std::cout << "Enter product price: ";
    std::cin >> price;
    return price;
}

std::ostream& operator << (std::ostream& os, const Product product)
{
    return os << "Name: " << product.name << "\nPrice: " << product.price << "\nRating: " << product.rating << '\n';
}