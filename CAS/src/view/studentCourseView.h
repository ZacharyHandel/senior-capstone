#ifndef STUDENT_COURSE_VIEW_H
#define STUDENT_COURSE_VIEW_H

#include <Wt/WContainerWidget.h>
#include <Wt/WText.h>
#include <Wt/WTable.h>
#include <Wt/WPushButton.h>

class studentCourseView : public Wt::WContainerWidget {
public:
    studentCourseView(Wt::WContainerWidget *parent = nullptr);
private:
    Wt::WText *title_;
    Wt::WText *instructor_;
    Wt::WTable *attendanceTable_;
    Wt::WPushButton *backButton_;
    void loadCourseDetails();
    void loadAttendanceData();
    void navigateBack();
};

#endif // STUDENT_COURSE_VIEW_H
