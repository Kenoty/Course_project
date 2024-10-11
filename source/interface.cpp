#include "interface.h"

void routine()
{
    std::cout << "\nPress enter to continue";
    rewind(stdin);
    getchar();
}

void create_the_product(List<Product>& courses)
{
    courses.push_back();
    courses[courses.get_size() - 1].set_name();
    courses[courses.get_size() - 1].set_price();
    routine();
}

void output_product_info(List<Product> courses)
{
    for (int i = 0; i < courses.get_size(); i++)
    {
        std::cout << "Product number " << i + 1 << '\n';
        //courses[i].read();
        std::cout << courses[i];
    }
    routine();
}

void rate_product(List<Product>& courses)
{
    int order;
    std::cout << "\vWhat product you want to rate:\n";
    for (int i = 0; i < courses.get_size(); i++)
        courses[i].read_only_names(i + 1);
    std::cin >> order;
    order--;
    courses[order].rate_the_course();
    routine();
}

void update_info(List<Product>& courses)
{
    int order;
    int token;
    std::cout << "\vWhat product you want to update:\n";
    for (int i = 0; i < courses.get_size(); i++)
        courses[i].read_only_names(i + 1);
    std::cin >> order;
    order--;
    std::cout << "What you want to update:\n";
    std::cout << "1. Name of the product:\n";
    std::cout << "2. Price of the product:\n";
    std::cin >> token;
    if (token == 1)
    {
        courses[order].set_name();
    }
    else
        courses[order].set_price();
    routine();
}

void delete_product(List<Product>& courses)
{
    int order;
    if (courses.get_size() != 0)
    {
        std::cout << "\vWhat product you want to delete:\n";
        for (int i = 0; i < courses.get_size(); i++)
            courses[i].read_only_names(i + 1);
        std::cin >> order;
        order--;
        courses.remove_object(order);
    }
    else
        std::cout << "Courses are already do not exist\n";
    routine();
}

void check_on_copies(List<Product> courses)
{
    for (int i = 0; i < courses.get_size(); i++)
        for (int j = i + 1; j < courses.get_size(); j++)
            if (courses[i] == courses[j])
            {
                std::cout << "There is copy of the product in list";
                routine();
                return;
            }
    std::cout << "There is no copies of the products in list";
    routine();
}