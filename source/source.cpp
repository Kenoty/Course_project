#include "interface.h"

int main()
{
    int action = 0;
    List<Product> courses;

    while (action != 7)
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
            std::cout << "6. Check list on copies\n";
            std::cout << "7. Exit the program\n";
            std::cin >> action;
            break;
        case 1:
            create_the_product(courses);
            action = 0;
            break;
        case 2:
            output_product_info(courses);
            action = 0;
            break;
        case 3:
            rate_product(courses);
            action = 0;
            break;
        case 4:
            update_info(courses);
            action = 0;
            break;
        case 5:
            delete_product(courses);
            action = 0;
            break;
        case 6:
            check_on_copies(courses);
            action = 0;
            break;
        default:
            std::cout << "Input error, try again: ";
            std::cin >> action;
            break;
        }
    }
}