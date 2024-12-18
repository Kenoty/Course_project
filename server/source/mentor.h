#pragma once

#include "user_info.h"
#include "course.h"
#include "course_management.h"
#include "list.h"

class Mentor: public UserInfo, public ICourse
{
	float rating;
    int numberOfVotes;
	List<Course> courses;
public:
    Mentor(const UserInfo& currentUser = UserInfo(), float rating = 0, int num = 0): UserInfo(currentUser), rating(rating), numberOfVotes(num), courses(List<Course>())
	{
		getCourseInfo();
	}
    void createCourse(std::string *values);
	void outputCourseInfo();
	void updateCourseInfo();
	void deleteCourse();
	void getCourseInfo();
    void getLecturesInfo(Course& course);
    List<Course>& getCoursesList();
    std::string *getStudents(std::string*);

};
