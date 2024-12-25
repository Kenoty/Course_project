#include "mentor.h"
#include "filters.h"
#include "jsonfilehandler.h"
#include <format>


void Mentor::createCourse(std::string *values)
{
    const std::string fieldNames = {"name, price, user_id"};

    float tempPrice = std::stof(values[1]);
    int tempIntPrice = static_cast<int>(tempPrice * 100);
    values[1] = std::to_string(tempIntPrice);

    std::string temp = "'" + values[0] + "', '" + values[1] + "', " + values[2];
    insertData("courses", fieldNames, temp);
}

void Mentor::outputCourseInfo()
{
    for (int i = 0; i < this->courses.getSize(); i++)
    {
        std::cout << "Course number " << i + 1 << '\n';
        std::cout << this->courses[i];
    }
}

void Mentor::updateCourseInfo()
{
    int order;
    int token;
    std::cout << "\vWhat course you want to update:\n";
    for (int i = 0; i < this->courses.getSize(); i++)
        this->courses[i].readOnlyNames(i + 1);
    std::cin >> order;
    order--;
    std::cout << "What you want to update:\n";
    std::cout << "1. Name of the course:\n";
    std::cout << "2. Price of the course:\n";
    std::cin >> token;

    const std::string fieldNames[] = {"name", "price"};
    if (token == 1)
    {
        std::cout << "Enter new name: ";
        std::string temp;
        rewind(stdin);
        getline(std::cin, temp);
        this->courses[order].setName(temp);
        updateField("courses", fieldNames[0], "'" + this->courses[order].getName() + "'", std::to_string(this->courses[order].getId()));
    }
    else
    {
        std::cout << "Enter new price: ";
        float temp;
        std::cin >> temp;
        this->courses[order].setPrice(temp);
        updateField("courses", fieldNames[1], std::to_string(this->courses[order].getPrice() * 100), std::to_string(this->courses[order].getId()));
    }
}

void Mentor::deleteCourse(int id)
{
    deleteData("courses", std::to_string(id));
    // int order;
    // if (this->courses.getSize() != 0)
    // {
    //     std::cout << "\vWhat course you want to delete:\n";
    //     for (int i = 0; i < this->courses.getSize(); i++)
    //         this->courses[i].readOnlyNames(i + 1);
    //     std::cin >> order;
    //     order--;
    //     this->courses.removeObject(order);
    // }
    // else
    //     std::cout << "Courses are already do not exist\n";
}

void Mentor::getCourseInfo()
{
    const std::string fieldNames[] = {"name", "price", "rating", "number_of_votes", "id"};

    const int nrows = getNrows(std::format("courses WHERE user_id = {}", getId()), fieldNames, std::size(fieldNames));
    const int nfields = getNfields(std::format("courses WHERE user_id = {}", getId()), fieldNames, std::size(fieldNames));

    std::string* temp = new std::string[nrows * nfields];

    temp = selectFromPostgres(std::format("courses WHERE user_id = {}", getId()), fieldNames, temp, std::size(fieldNames));

    if (this->courses.getSize() != 0)
        this->courses.clear();

    for (int i = 0; i < nrows; i++)
    {
        this->courses.pushBack();
    }

    int count = 0;
    List<Course>::Iterator iterator = courses.begin();
    while(iterator != courses.end())
    {
        (*iterator).setName(temp[count++]);
        (*iterator).setPrice(std::stof(temp[count++]) / 100);
        (*iterator).setRating(std::stof(temp[count++]) / 100);
        (*iterator).setNumberOfVotes(std::stoi(temp[count++]));
        (*iterator).setId(std::stoi(temp[count++]));
        getLecturesInfo(*iterator);
        ++iterator;
    }

    delete[] temp;
}

void Mentor::getLecturesInfo(Course &course)
{
    std::string fieldNames[3] = {"id", "lecture_name", "text"};

    const int nrows = getNrows(std::format("lectures WHERE course_id = {}", course.getId()), fieldNames, std::size(fieldNames));
    const int nfields = getNfields(std::format("lectures WHERE course_id = {}", course.getId()), fieldNames, std::size(fieldNames));

    std::string* temp = new std::string[nrows * nfields];

    selectFromPostgres(std::format("lectures WHERE course_id = {}", course.getId()), fieldNames, temp, std::size(fieldNames));

    if (course.getLecturesList().getSize() != 0)
        course.getLecturesList().clear();
    for (int i = 0; i < nrows; i++)
    {
        course.getLecturesList().pushBack();
    }

    int count = 0;
    List<Lecture>::Iterator iterator = course.getLecturesList().begin();
    while(iterator != course.getLecturesList().end())
    {
        (*iterator).setId(std::stoi(temp[count++]));
        (*iterator).setLectureName(temp[count++]);
        (*iterator).setMaterial(temp[count++]);
        ++iterator;
    }

    delete[] temp;
}

List<Course>& Mentor::getCoursesList()
{
    return courses;
}

std::string *Mentor::getStudents(std::string *filters)
{
    Filters filter;

    filter.setFname(filters[0]);
    filter.setSname(filters[1]);
    filter.setLname(filters[2]);
    filter.setEmail(filters[3]);
    filter.setPhone(filters[4]);

    std::string query = " users WHERE role = 'STUDENT'" + filter.createFiltersKit();

    const std::string fieldNames[5] = {"first_name", "second_name", "last_name", "email", "phone_number"};
    const int nrows = getNrows(query, fieldNames, std::size(fieldNames));
    const int nfields = getNfields(query, fieldNames, std::size(fieldNames));

    std::string *result = new std::string[nrows * nfields];

    selectFromPostgres(query, fieldNames, result, std::size(fieldNames));

    JsonFileHandler handler;

    handler.writeJson("StudentsReport", result, nrows);

    return result;
}
