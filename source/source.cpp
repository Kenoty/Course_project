#include "interface.h"

int main()
{
    int action = 0;
    unsigned int amount = 0;
    Product* courses;
    courses = new Product[1];

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
            create_the_product(courses, amount);
            action = 0;
            break;
        case 2:
            output_product_info(courses, amount);
            action = 0;
            break;
        case 3:
            rate_product(courses, amount);
            action = 0;
            break;
        case 4:
            update_info(courses, amount);
            action = 0;
            break;
        case 5:
            delete_product(courses, amount);
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