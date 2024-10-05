/*
 *  Attendance Tracker
 * 
 * View - Faculty Dashboard view
 *
 * archhi (Aryaman Chhikara), 05/04/2024
 */



#include "FacultyDashboardView.h"
#include <Wt/WText.h>
#include <Wt/WBreak.h>
#include <Wt/WPushButton.h>
#include <Wt/WContainerWidget.h>
#include <memory>

using namespace Wt;

FacultyDashboardView::FacultyDashboardView()
{
  
    WApplication::instance()->useStyleSheet("styles.css");

    // Setting the page header 
    PageHeader = addWidget(std::make_unique<WText>("Teacher's Dashboard"));
    PageHeader->setMargin(WLength("45%"), Side::Left | Side::Right);
    PageHeader->setStyleClass(".body");
    this->addWidget(std::make_unique<WBreak>());

    // Adding the name of the course the teacher is teaching
    CourseName = addWidget(std::make_unique<WText>("Course Name:"));
    this->addWidget(std::make_unique<WBreak>());
    CourseName->setStyleClass("body");
    this->addWidget(std::make_unique<WBreak>());

    loadCourseID();
    loadStudents();

    // Link to Profile Settings
    ProfileSettings = addWidget(std::make_unique<Wt::WPushButton>("Profile Settings"));
    //ProfileSettings->setLink(Wt::WLink(Wt::LinkType::InternalPath, "/ProfileSettings"));
    ProfileSettings->setStyleClass("primaryNavBtn");
    ProfileSettings->setMargin(WLength("85%"), Side::Right | Side::Left);
    this->addWidget(std::make_unique<WBreak>());


    // Link to Track Attendance page
    TrackAttendance = addWidget(std::make_unique<Wt::WPushButton>("Track Attendance"));
    
    //TrackAttendance->setLink(Wt::WLink(Wt::LinkType::InternalPath, "/TrackAttendance"));
   
    TrackAttendance->setStyleClass("primaryNavBtn");
    TrackAttendance->setMargin(WLength("85%"), Side::Right | Side::Left);
   
    this->addWidget(std::make_unique<WBreak>());

    // Link to Manage Courses page
    
    ManageCourses = addWidget(std::make_unique<Wt::WPushButton>("Manage Courses"));
    //ManageCourses->setLink(Wt::WLink(Wt::LinkType::InternalPath, "/courseManagementView"));
    ManageCourses->setStyleClass("primaryNavBtn");
    ManageCourses->setMargin(WLength("1%"), Side::Left | Side::Right);
    this->addWidget(std::make_unique<WBreak>());

    // Link to Notifications page
   
    DisplayCode = addWidget(std::make_unique<Wt::WPushButton>("Display Code"));
    //DisplayCode->setLink(Wt::WLink(Wt::LinkType::InternalPath, "/DisplayCode"));
    DisplayCode->setStyleClass("secondaryNavBtn");
    DisplayCode->setMargin(WLength("1%"), Side::Left | Side::Right);

    this->addWidget(std::make_unique<WBreak>());

}

void FacultyDashboardView::loadCourseID(){

	courseID =  addWidget(std::make_unique<WText>("CS 455"));
        courseID->setStyleClass("body");


}

void FacultyDashboardView::loadStudents() {

	studentContainer = addWidget(std::make_unique<WContainerWidget>());
	studentLayout= studentContainer->setLayout(std::make_unique<WVBoxLayout>());
	
	students=addWidget(std::make_unique<WText>("First Name"));

	students->setStyleClass("body");		
}
