// courseManagementView2.h
#ifndef COURSEMANAGEMENTVIEW2_H
#define COURSEMANAGEMENTVIEW2_H

#include <Wt/WContainerWidget.h>
#include <Wt/WPushButton.h>
#include <Wt/WText.h>

using namespace Wt;

class courseManagementView2 : public WContainerWidget {
public:
    explicit courseManagementView2();
private:
    WPushButton* backButton;
    void listCourses();
    void viewStudents();
    void assignFaculty();
    void deleteCourse();
};

#endif /* COURSEMANAGEMENTVIEW2_H */