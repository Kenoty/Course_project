#include "database.h"

class ICourse: public Database
{
public:
	virtual void create_course() = 0;
	virtual void output_course_info() = 0;
	virtual void update_course_info() = 0;
	virtual void delete_course() = 0;
	virtual void get_course_info() = 0;
};