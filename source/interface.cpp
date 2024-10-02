#include "interface.h"

void routine()
{
    std::cout << "\nPress enter to continue";
    rewind(stdin);
    getchar();
}

void create_the_product(product* courses,unsigned int& amount)
{
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
}

void output_product_info(const product* courses, unsigned int amount)
{
    for (unsigned int i = 0; i < amount; i++)
    {
        std::cout << "Product number " << i + 1 << '\n';
        courses[i].read();
    }
    routine();
}

void rate_product(product* courses, unsigned int amount)
{
    int order;
    std::cout << "\vWhat product you want to rate:\n";
    for (unsigned int i = 0; i < amount; i++)
        courses[i].read_only_names(i + 1);
    std::cin >> order;
    order--;
    courses[order].rate_the_course();
    routine();
}

void update_info(product* courses, unsigned int amount)
{
    int order;
    int token;
    std::cout << "\vWhat product you want to update:\n";
    for (unsigned int i = 0; i < amount; i++)
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
}

void delete_product(product* courses, unsigned int& amount)
{
    int order;
    if (amount != 0)
    {
        std::cout << "\vWhat product you want to delete:\n";
        for (unsigned int i = 0; i < amount; i++)
            courses[i].read_only_names(i + 1);
        std::cin >> order;
        order--;
        courses->remove_course(courses, amount, order);
    }
    else
        std::cout << "Courses are already do not exist\n";
    routine();
}
