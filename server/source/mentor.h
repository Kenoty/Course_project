#include "user_info.h"
#include "course.h"
#include "course_management.h"
#include "list.h"
#include "menu_interface.h"

class Mentor: public UserInfo, public IMenu, public ICourse
{
	float rating;
	int number_of_votes;
	List<Course> courses;
public:
    Mentor(const UserInfo& current_user = UserInfo(), float rating = 0, int num = 0): UserInfo(current_user), rating(rating), number_of_votes(num), courses(List<Course>())
	{
		get_course_info();
	}
	void create_course();
	void output_course_info();
	void update_course_info();
	void delete_course();
	void get_course_info();
	void output_menu();
	void choose_option();
};
