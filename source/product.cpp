#include <iostream>
#include "product.h"

void product::read() const
{
    std::cout << "Name: " << name << "\nPrice: " << price << "\nRating: " << rating << '\n';
}

void product::read_only_names(int i) const
{

    std::cout << i << ". " << name << '\n';
}

void product::set_name()
{
    rewind(stdin);
    std::cout << "Enter product name: ";
    std::getline(std::cin, name);
}

void product::rate_the_course()
{
    int temp;
    std::cout << "Rate this course from 1 to 5: ";
    std::cin >> temp;
    rating = (rating * number_of_votes + temp) / (number_of_votes + 1);
    number_of_votes++;
}

void product::reset_name()
{
    rewind(stdin);
    name.clear();
    std::cout << "Enter product name: ";
    std::getline(std::cin, name);
}

float product::set_price()
{
    std::cout << "Enter product price: ";
    std::cin >> price;
    return price;
}

void product::increase(product* courses, int& amount)
{
    product* temp;
    temp = new product[amount];
    for (int i = 0; i < amount; i++)
        temp[i] = courses[i];
    delete[] courses;
    courses = new product[++amount];
    for (int i = 0; i < amount - 1; i++)
        courses[i] = temp[i];
    delete[] temp;
}

void product::remove_course(product* courses, int& amount, int order)
{
    int k = 0;
    product* temp;
    temp = new product[--amount];
    for (int i = 0; i <= amount; i++)
    {
        if (order != i)
            temp[k++] = courses[i];
    }
    delete[] courses;
    courses = new product[amount];
    for (int i = 0; i < amount; i++)
        courses[i] = temp[i];
    delete[] temp;
}