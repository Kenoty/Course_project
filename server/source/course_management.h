#include "database.h"
#include "course.h"

class ICourse: public Database
{
public:
    virtual void createCourse(std::string *values) = 0;
    virtual void outputCourseInfo() = 0;
    virtual void updateCourseInfo() = 0;
    virtual void deleteCourse() = 0;
    virtual void getCourseInfo() = 0;
    virtual void getLecturesInfo(Course& course) = 0;
};
