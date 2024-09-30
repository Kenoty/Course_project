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
    getline(cin, name);
}

void product::reset_name()
{
    rewind(stdin);
    name.clear();
    std::cout << "Enter product name: ";
    getline(cin, name);
}

float product::set_price()
{
    std::cout << "Enter product price: ";
    std::cin >> price;
    return price;
}

void product::rate_the_course()
{
    int temp;
    std::cout << "Rate this course from 1 to 5: ";
    std::cin >> temp;
    rating = (rating * number_of_votes + temp) / (number_of_votes + 1);
    number_of_votes++;
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
    if(amount != 0)
        courses = new product[amount];
    else
        courses = new product[1];
    for (int i = 0; i < amount; i++)
        courses[i] = temp[i];
    delete[] temp;
}

void routine()
{
    std::cout << "\nPress enter to continue";
    rewind(stdin);
    getchar();
}

int main()
{
    int action = 0;
    int amount = 0;
    int order;
    int token;
    product* courses;
    courses = new product[1];

    while (action != 6)
    {
        switch (action)
        {
        case 0:
            system("cls");
            std::cout << "Select the action you want to do and print the number\n";
            std::cout << "1. Create the product\n";
            std::cout << "2. Output information about the product\n";
            std::cout << "3. Rate the product\n";
            std::cout << "4. Update information about the product\n";
            std::cout << "5. Delete the product\n";
            std::cout << "6. Exit the program\n";
            std::cin >> action;
            break;
        case 1:
            if (amount < 1)
            {
                courses[0].set_name();
                courses[0].set_price();
                amount++;
            }
            else
            {
                courses->increase(courses, amount);
                courses[amount - 1].set_name();
                courses[amount - 1].set_price();

            }
            routine();
            action = 0;
            break;
        case 2:
             for (int i = 0; i < amount; i++)
            {
                std::cout << "Product number " << i + 1 << '\n';
                courses[i].read();
            }
            routine();
            action = 0;
            break;
        case 3:
            std::cout << "\vWhat product you want to rate:\n";
            for (int i = 0; i < amount; i++)
                courses[i].read_only_names(i + 1);
            std::cin >> order;
            order--;
            courses[order].rate_the_course();
            routine();
            action = 0;
            break;
        case 4:
            std::cout << "\vWhat product you want to update:\n";
            for (int i = 0; i < amount; i++)
                courses[i].read_only_names(i + 1);
            std::cin >> order;
            order--;
            std::cout << "What you want to update:\n";
            std::cout << "1. Name of the product:\n";
            std::cout << "2. Price of the product:\n";
            std::cin >> token;
            if (token == 1)
            {
                courses[order].reset_name();
            }
            else
                courses[order].set_price();
            routine();
            action = 0;
            break;
        case 5:
            if (amount != 0)
            {
                std::cout << "\vWhat product you want to delete:\n";
                for (int i = 0; i < amount; i++)
                    courses[i].read_only_names(i + 1);
                std::cin >> order;
                order--;
                courses->remove_course(courses, amount, order);
            }
            else
                std::cout << "Courses are already do not exist\n";
            routine();
            action = 0;
            break;
        default:
            std::cout << "Input error, try again: ";
            std::cin >> action;
            break;
        }
    }
    delete[] courses;
}