#pragma once

#include <iostream>
#include <string>

#include "id.h"
#include "list.h"
#include "lecture.h"

class Course: public Id
{
    std::string name = " ";
    float price = 0;
    float rating = 0;
    int numberOfVotes = 0;
    List<Lecture> lectures;
public:
    void setName(const std::string_view);
    std::string getName() const;
    void setPrice(float);
    float getPrice() const;
    void setRating(float);
    float getRating() const;
    void setNumberOfVotes(int);
    int getNumberOfVotes() const;
    void readOnlyNames(unsigned int) const;
    friend void rateTheCourse(Course&);
    bool operator == (const Course& course) const = default;
    friend std::ostream& operator << (std::ostream&, const Course&);
    List<Lecture>& getLecturesList();
};
