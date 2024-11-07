#include "user_info.h"
#include "database.h"
#include "course.h"
#include "list.h"
#include "menu_interface.h"

class Mentor: public User_info, public Database, public IMenu
{
	float rating;
	int number_of_votes;
	List<Course> courses;
public:
	Mentor(float rating = 0, int num = 0,const User_info& current_user = User_info()): User_info(current_user), Database(), rating(rating), number_of_votes(num), courses(List<Course>()){}
	void create_course();
	void output_course_info();
	void update_course_info();
	void delete_course();
	void get_course_info();
	void output_menu();
};