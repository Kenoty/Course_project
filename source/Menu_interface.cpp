#include <iostream>
#include "menu_interface.h"

void IMenu::routine()
{
    std::cout << "\nPress enter to continue";
    rewind(stdin);
    getchar();
}

void IMenu::choose_option()
{
    std::cout << "Something goes wrong. Try again later";
}