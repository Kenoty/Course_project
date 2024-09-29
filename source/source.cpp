﻿#include <iostream>

class product
{
    char* name;
    float price;
public:
    void read() const;
    void read_only_names(int) const;
    char* set_name();
    char* reset_name();
    float set_price();
    product* renew(product*, int&);
    product* remove(product*, int&, int);
};

void product::read() const
{
    std::cout << "Name: " << name << "\nPrice: " << price << '\n';
}

void product::read_only_names(int i) const
{

    std::cout << i << ". " << name << '\n';
}

char* product::set_name()
{
    int i = 1;
    rewind(stdin);
    std::cout << "Enter product name: ";
    name = new char[1];
    char* temp;
    while ((name[i - 1] = getchar()) != '\n')
    {
        temp = new char[i];
        for (int k = 0; k < i; k++)
            temp[k] = name[k];
        delete[] name;
        i++;
        name = new char[i];
        for (int k = 0; k < i - 1; k++)
            name[k] = temp[k];
        delete[] temp;
    }
    name[i - 1] = '\0';
    return name;
}

char* product::reset_name()
{
    int i = 1;
    rewind(stdin);
    delete[] name;
    std::cout << "Enter product name: ";
    name = new char[1];
    char* temp;
    while ((name[i - 1] = getchar()) != '\n')
    {
        temp = new char[i];
        for (int k = 0; k < i; k++)
            temp[k] = name[k];
        delete[] name;
        i++;
        name = new char[i];
        for (int k = 0; k < i - 1; k++)
            name[k] = temp[k];
        delete[] temp;
    }
    name[i - 1] = '\0';
    return name;
}

float product::set_price()
{
    std::cout << "Enter product price: ";
    std::cin >> price;
    return price;
}

product* renew(product* courses, int& amount)
{
    product* temp;
    temp = new product[amount + 1];
    for (int i = 0; i < amount; i++)
        temp[i] = courses[i];
    delete[] courses;
    courses = new product[++amount];
    for (int i = 0; i < amount; i++)
        courses[i] = temp[i];
    delete[] temp;
    return courses;
}

product* remove(product* courses, int& amount, int order)
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
    return courses;
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

    while (action != 5)
    {
        switch (action)
        {
        case 0:
            system("cls");
            std::cout << "Select the action you want to do and print the number\n";
            std::cout << "1. Create the product\n";
            std::cout << "2. Output information about the product\n";
            std::cout << "3. Update information about the product\n";
            std::cout << "4. Delete the product\n";
            std::cout << "5. Exit the program\n";
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
                courses = renew(courses, amount);
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
        case 4:
            std::cout << "\vWhat product you want to delete:\n";
            for (int i = 0; i < amount; i++)
                courses[i].read_only_names(i + 1);
            std::cin >> order;
            order--;
            courses = remove(courses, amount, order);
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