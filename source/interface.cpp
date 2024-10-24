#include "interface.h"
#include "database.h"

void get_info(std::string& field)
{
    std::cout << "Enter your " + field + ": ";
    rewind(stdin);
    if (field != "last name")
    {
        std::getline(std::cin, field);
        while (field == "")
        {
            std::cout << "It cannot be empty. Try again: ";
            rewind(stdin);
            std::getline(std::cin, field);
        }
    }
    else
        std::getline(std::cin, field);
}

void registration()
{
    Database postgres;
    const std::string field_names[] = {"first_name", "second_name", "last_name", "email", "phone_number", "user_password"};
    std::string values[] = {"first name", "second name", "last name", "email", "phone number", "password"};

    for (int i = 0; i < std::size(values); i++)
        get_info(values[i]);

    std::string temp_fnames = "";
    std::string temp_values = "'";
    for (int i = 0; i < std::size(values); i++)
    {
        if (values[i] != "")
        {
            if (i != std::size(values) - 1)
            {
                temp_fnames = temp_fnames + field_names[i] + ", ";
                temp_values = temp_values + values[i] + "', '";
            }
            else
            {
                temp_fnames += field_names[i];
                temp_values += values[i] + "'";
            }
        }
    }

    postgres.insert_data("users", temp_fnames, temp_values);

    std::cout << "Registration was successful!" << std::endl << "Press enter to continue ";
    getchar();
}

void login(User& current_user)
{
    Database postgres;
    const std::string field_names[] = {"email", "user_password"};
    std::string values[] = {"email", "password"};

    for (int i = 0; i < std::size(values); i++)
        get_info(values[i]);

    while (!postgres.validation("users", field_names, values, std::size(values)))
    {
        std::cout << "Login fail. Try again" << std::endl;
        values[0] = "email";
        values[1] = "password";
        for (int i = 0; i < std::size(values); i++)
            get_info(values[i]);
    }
    std::string temp[] = {"*"};
    std::string user_data[7];
    postgres.select_from_postgres("users WHERE email = '" + values[0] + "'", temp, user_data, 1);
    current_user.set_id(std::stoi(user_data[0]));
    current_user.set_fname(user_data[1]);
    current_user.set_sname(user_data[2]);
    current_user.set_lname(user_data[3]);
    current_user.set_email(user_data[4]);
    current_user.set_phone_number(user_data[5]);
    current_user.set_user_password(user_data[6]);
}

void routine()
{
    std::cout << "\nPress enter to continue";
    rewind(stdin);
    getchar();
}

void create_the_product(const User& user)
{
    Database postgres;
    const std::string field_names = {"name, price, user_id"};
    std::string values[] = {"course name", "course price", std::to_string(user.get_id())};

    for (int i = 0; i < std::size(values) - 1; i++)
        get_info(values[i]);
    std::string temp = "'" + values[0] + "', '" + values[1] + "', " + values[2];
    postgres.insert_data("courses", field_names, temp);
    routine();
}

void get_product_info(List<Product>& courses, User& user)
{
    Database postgres;
    const std::string field_names[] = { "name", "price", "rating", "number_of_votes", "id" };

    const int nrows = postgres.get_nrows("courses WHERE user_id = " + std::to_string(user.get_id()), field_names, std::size(field_names));
    const int nfields = postgres.get_nfields("courses WHERE user_id = " + std::to_string(user.get_id()), field_names, std::size(field_names));

    std::string* temp = new std::string[nrows * nfields];

    temp = postgres.select_from_postgres("courses WHERE user_id = " + std::to_string(user.get_id()), field_names, temp, std::size(field_names));

    if (courses.get_size() != 0)
        courses.clear();
    int count = 0;
    for (int i = 0; i < nrows; i++)
    {
        courses.push_back();
        courses[i].set_name(temp[count++]);
        courses[i].set_price(std::stof(temp[count++]) / 100);
        courses[i].set_rating(std::stof(temp[count++]) / 100);
        courses[i].set_number_of_votes(std::stoi(temp[count++]));
        courses[i].set_id(std::stoi(temp[count++]));
    }

    delete[] temp;
}

void output_product_info(List<Product>& courses)
{
    for (int i = 0; i < courses.get_size(); i++)
    {
        std::cout << "Product number " << i + 1 << '\n';
        std::cout << courses[i];
    }
    routine();
}

void rate_product(List<Product>& courses)
{
    Database postgres;
    int order;
    std::cout << "\vWhat product you want to rate:\n";
    for (int i = 0; i < courses.get_size(); i++)
        courses[i].read_only_names(i + 1);
    std::cin >> order;
    order--;
    rate_the_course(courses[order]);

    const std::string field_names[] = {"rating", "number_of_votes"};

    postgres.update_field("courses", field_names[0], std::to_string(courses[order].get_rating() * 100), std::to_string(courses[order].get_id()));
    postgres.update_field("courses", field_names[1], std::to_string(courses[order].get_number_of_votes()), std::to_string(courses[order].get_id()));
    routine();
}

void update_info(List<Product>& courses)
{
    Database postgres;
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

    const std::string field_names[] = {"name", "price"};
    if (token == 1)
    {
        std::cout << "Enter new name: ";
        std::string temp;
        rewind(stdin);
        getline(std::cin, temp);
        courses[order].set_name(temp);
        postgres.update_field("courses", field_names[0], "'" + courses[order].get_name() + "'", std::to_string(courses[order].get_id()));
    }
    else
    {
        std::cout << "Enter new price: ";
        float temp;
        std::cin >> temp;
        courses[order].set_price(temp);
        postgres.update_field("courses", field_names[1], std::to_string(courses[order].get_price() * 100), std::to_string(courses[order].get_id()));
    }
    routine();
}

void delete_product(List<Product>& courses)
{
    Database postgres;
    int order;
    if (courses.get_size() != 0)
    {
        std::cout << "\vWhat product you want to delete:\n";
        for (int i = 0; i < courses.get_size(); i++)
            courses[i].read_only_names(i + 1);
        std::cin >> order;
        order--;
        postgres.delete_data("courses", std::to_string(courses[order].get_id()));
        courses.remove_object(order);
    }
    else
        std::cout << "Courses are already do not exist\n";
    routine();
}