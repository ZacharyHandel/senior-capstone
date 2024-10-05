/*
 *  Attendence Tracker 
 *
 * View - View for Fcaulty Dashboard
 *
 * archhi(Aryaman Chhikara), 05/04/2024
 */

#include <Wt/WApplication.h>
#include <Wt/WLineEdit.h>
#include <Wt/WText.h>
#include <Wt/WLink.h>
#include <Wt/WAnchor.h>
#include <Wt/WPushButton.h>
#include <Wt/WContainerWidget.h>
#include <Wt/WVBoxLayout.h>

#ifndef FacultyDashboardView_H
#define FacultyDashboardView_H

using namespace Wt;

class FacultyDashboardView: public WContainerWidget {
    public:
        explicit FacultyDashboardView();

    private:
    void loadCourseID();
    void loadStudents();


        WContainerWidget* studentContainer;


	WVBoxLayout* studentLayout;


	WText* PageHeader;
	WText* CourseName;
	WText* courseID;
	WText* students;

	WPushButton* ProfileSettings;
	WPushButton* TrackAttendance;
	WPushButton* ManageCourses;
	WPushButton* DisplayCode;

};

#endif /* FacultyDashboardView_H */





