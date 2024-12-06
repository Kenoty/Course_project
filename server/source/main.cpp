//#include "authorization_menu.h"
//#include "mentor.h"
//
//int main()
//{
//    int action = 0;
//    UserInfo guest;
//    IMenu* menu;
//    AuthorizationMenu auth_menu;
//
//    menu = &auth_menu;
//
// /*   menu->choose_option();*/
//    while (action != 3)
//    {
//        switch (action)
//        {
//        case 0:
//            menu->output_menu();
//            std::cin >> action;
//            break;
//        case 1:
//            //auth_menu.login(guest);
//            action = 3;
//            break;
//        case 2:
//            auth_menu.registration();
//            action = 0;
//            break;
//        default:
//            std::cout << "Input error, try again: ";
//            std::cin >> action;
//        }
//    }
//
//    if (!guest.get_id())
//        return 0;
//
//    Mentor current_user(0, 0, guest);
//
//    menu = &current_user;
//    action = 0;
//    //menu->choose_option();
//    while (action != 5)
//    {
//        switch (action)
//        {
//        case 0:
//            menu->output_menu();
//            std::cin >> action;
//            break;
//        case 1:
//            current_user.create_course();
//            menu->routine();
//            action = 0;
//            break;
//        case 2:
//            current_user.get_course_info();
//            current_user.output_course_info();
//            menu->routine();
//            action = 0;
//            break;
//        case 3:
//            current_user.update_course_info();
//            menu->routine();
//            action = 0;
//            break;
//        case 4:
//            current_user.delete_course();
//            menu->routine();
//            action = 0;
//            break;
//        default:
//            std::cout << "Input error, try again: ";
//            std::cin >> action;
//            break;
//        }
//    }
//    return 0;
//}
