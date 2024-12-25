#include "mentorscoursestab.h"
#include "coursecard.h"

MentorsCoursesTab::MentorsCoursesTab(Mentor* account, QWidget* parent): QScrollArea(parent)
{
    this->setStyleSheet("background-color: #212121");
    this->setWidgetResizable(true);

    listOfCoursesContent = new QWidget();
    this->setWidget(listOfCoursesContent);

    listOfCoursesLayout = new QVBoxLayout(listOfCoursesContent);
    listOfCoursesLayout->setSpacing(5);

    CourseCard *temp;
    for (int i = 0; i < account->getCoursesList().getSize(); i++)
    {
        temp = new CourseCard(account->getCoursesList()[i]);
        listOfCoursesLayout->addWidget(temp);
        connect(temp, &CourseCard::courseClicked, this, [this](LecturesListTab* tab){onCourseClicked(tab);});
        connect(temp, &CourseCard::lectureClicked, this, [this](LectureTab* tab){onLectureClicked(tab);});
    }

    listOfCoursesLayout->addStretch();

    createCourseButton = new QPushButton("Создать курс");
    listOfCoursesLayout->addWidget(createCourseButton);
}

QPushButton *MentorsCoursesTab::getCreateCourseButtonPtr()
{
    return this->createCourseButton;
}

void MentorsCoursesTab::onCourseClicked(LecturesListTab *tab)
{
    emit courseClicked(tab);
}

void MentorsCoursesTab::onLectureClicked(LectureTab *tab)
{
    emit lectureClicked(tab);
}
