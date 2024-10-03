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

void Product::reset_name()
{
    rewind(stdin);
    name.clear();
    std::cout << "Enter product name: ";
    std::getline(std::cin, name);
}

float Product::set_price()
{
    std::cout << "Enter product price: ";
    std::cin >> price;
    return price;
}

void Product::add_product(Product* courses, unsigned int& amount)
{
    Product* temp;
    temp = new Product[amount];
    for (int i = 0; i < amount; i++)
        temp[i] = courses[i];
    delete[] courses;
    courses = new Product[++amount];
    for (int i = 0; i < amount - 1; i++)
        courses[i] = temp[i];
    delete[] temp;
}

void Product::remove_course(Product* courses, unsigned int& amount, int order)
{
    --amount;
    if (amount != 0)
    {
        int k = 0;
        Product* temp;
        temp = new Product[amount];
        for (int i = 0; i <= amount; i++)
        {
            if (order != i)
                temp[k++] = courses[i];
        }
        delete[] courses;
        courses = new Product[amount];
        for (int i = 0; i < amount; i++)
            courses[i] = temp[i];
        delete[] temp;
    }
    else delete[] courses;
}