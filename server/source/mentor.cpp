#include "mentor.h"
#include <format>

void Mentor::create_course()
{
    const std::string field_names = {"name, price, user_id"};
    std::string values[] = {"course name", "course price", std::to_string(get_id())};

    for (int i = 0; i < size(values) - 1; i++)
        get_info(values[i]);
    std::string temp = "'" + values[0] + "', '" + values[1] + "', " + values[2];
    insert_data("courses", field_names, temp);
}

void Mentor::output_course_info()
{
    for (int i = 0; i < this->courses.get_size(); i++)
    {
        std::cout << "Course number " << i + 1 << '\n';
        std::cout << this->courses[i];
    }
}

void Mentor::update_course_info()
{
    int order;
    int token;
    std::cout << "\vWhat course you want to update:\n";
    for (int i = 0; i < this->courses.get_size(); i++)
        this->courses[i].read_only_names(i + 1);
    std::cin >> order;
    order--;
    std::cout << "What you want to update:\n";
    std::cout << "1. Name of the course:\n";
    std::cout << "2. Price of the course:\n";
    std::cin >> token;

    const std::string field_names[] = {"name", "price"};
    if (token == 1)
    {
        std::cout << "Enter new name: ";
        std::string temp;
        rewind(stdin);
        getline(std::cin, temp);
        this->courses[order].set_name(temp);
        update_field("courses", field_names[0], "'" + this->courses[order].get_name() + "'", std::to_string(this->courses[order].get_id()));
    }
    else
    {
        std::cout << "Enter new price: ";
        float temp;
        std::cin >> temp;
        this->courses[order].set_price(temp);
        update_field("courses", field_names[1], std::to_string(this->courses[order].get_price() * 100), std::to_string(this->courses[order].get_id()));
    }
}

void Mentor::delete_course()
{
    int order;
    if (this->courses.get_size() != 0)
    {
        std::cout << "\vWhat course you want to delete:\n";
        for (int i = 0; i < this->courses.get_size(); i++)
            this->courses[i].read_only_names(i + 1);
        std::cin >> order;
        order--;
        delete_data("courses", std::to_string(this->courses[order].get_id()));
        this->courses.remove_object(order);
    }
    else
        std::cout << "Courses are already do not exist\n";
}

void Mentor::get_course_info()
{
    const std::string field_names[] = {"name", "price", "rating", "number_of_votes", "id"};

    const int nrows = get_nrows(std::format("courses WHERE user_id = {}", get_id()), field_names, std::size(field_names));
    const int nfields = get_nfields(std::format("courses WHERE user_id = {}", get_id()), field_names, std::size(field_names));

    std::string* temp = new std::string[nrows * nfields];

    temp = select_from_postgres(std::format("courses WHERE user_id = {}", get_id()), field_names, temp, std::size(field_names));

    if (this->courses.get_size() != 0)
        this->courses.clear();
    int count = 0;
    for (int i = 0; i < nrows; i++)
    {
        this->courses.push_back();
        this->courses[i].set_name(temp[count++]);
        this->courses[i].set_price(std::stof(temp[count++]) / 100);
        this->courses[i].set_rating(std::stof(temp[count++]) / 100);
        this->courses[i].set_number_of_votes(std::stoi(temp[count++]));
        this->courses[i].set_id(std::stoi(temp[count++]));
    }

    delete[] temp;
}

void Mentor::output_menu()
{
    system("cls");
    std::cout << "Select the action you want to do and print the number\n";
    std::cout << "1. Create the product\n";
    std::cout << "2. Output information about the product\n";
    std::cout << "3. Update information about the product\n";
    std::cout << "4. Delete the product\n";
    std::cout << "5. Exit the program\n";
}

void Mentor::choose_option()
{
    int action = 0;

    while (action != 5)
    {
        switch (action)
        {
        case 0:
            output_menu();
            std::cin >> action;
            break;
        case 1:
            create_course();
            routine();
            action = 0;
            break;
        case 2:
            get_course_info();
            output_course_info();
            routine();
            action = 0;
            break;
        case 3:
            update_course_info();
            routine();
            action = 0;
            break;
        case 4:
            delete_course();
            routine();
            action = 0;
            break;
        default:
            std::cout << "Input error, try again: ";
            std::cin >> action;
            break;
        }
    }
}