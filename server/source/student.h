#pragma once

#include "user_info.h"
#include "database.h"

#include <string>
#include <vector>

class Student: public UserInfo, public Database
{
public:
    Student(const UserInfo& currentUser = UserInfo()): UserInfo(), Database(){}
    std::vector<std::string> findCourses(std::string_view);
    void buyCourse();
    void rateCourse();
    void findMentor();
    void rateMentor();
    void getAccess();
    void topUpWallet();
};
