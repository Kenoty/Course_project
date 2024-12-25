#include "student.h"
#include <format>

//void Student::rate_course()
//{
//    Database postgres;
//    int order;
//    std::cout << "\vWhat course you want to rate:\n";
//    for (int i = 0; i < couget_size(); i++)
//        courses[i].read_only_names(i + 1);
//    std::cin >> order;
//    order--;
//    rate_the_course(courses[order]);
//
//    const std::string field_names[] = { "rating", "number_of_votes" };
//
//    postgres.update_field("courses", field_names[0], std::to_string(courses[order].get_rating() * 100), std::to_string(courses[order].get_id()));
//    postgres.update_field("courses", field_names[1], std::to_string(courses[order].get_number_of_votes()), std::to_string(courses[order].get_id()));
//    routine();
//}

std::vector<std::string> Student::findCourses(std::string_view text)
{
    std::string fieldNames[] = {"name", "id"};
    std::vector<std::string> vector = selectFromPostgre(std::format("courses WHERE name ILIKE '{}%'", text), fieldNames, std::size(fieldNames));

    return vector;
}
