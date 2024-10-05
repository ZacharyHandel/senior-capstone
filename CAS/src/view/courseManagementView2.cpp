#include "courseManagementView2.h"
#include <Wt/WApplication.h> // Include this to use WApplication
#include <Wt/WContainerWidget.h>
#include <Wt/WPushButton.h>
#include <Wt/WText.h>

using namespace Wt;

courseManagementView2::courseManagementView2() {
    setContentAlignment(AlignmentFlag::Center);
    addWidget(std::make_unique<WText>("Course Management"));
    addWidget(std::make_unique<WBreak>()); // Add a line break after the header

    backButton = addWidget(std::make_unique<WPushButton>("<- Go Back"));
    backButton->setStyleClass("secondaryNavBtn");
    backButton->setFloatSide(Side::Left);
    backButton->setLink(WLink("javascript:history.back()"));

    listCourses();
    viewStudents();
    assignFaculty();
    deleteCourse();
}

void courseManagementView2::listCourses() {
    // Placeholder for course listing table
    addWidget(std::make_unique<WText>("List of Courses Placeholder"));
}

void courseManagementView2::viewStudents() {
    // Button to view students
    auto viewStudentsButton = addWidget(std::make_unique<WPushButton>("View Students"));
    viewStudentsButton->setStyleClass("primaryNavBtn");
    /*viewStudentsButton->clicked().connect([] {
        // Redirect to view students page
        WApplication::instance()->setInternalPath("/viewStudents", true);
    });*/
}

void courseManagementView2::assignFaculty() {
    // Button to assign faculty
    auto assignFacultyButton = addWidget(std::make_unique<WPushButton>("Assign Faculty"));
    assignFacultyButton->setStyleClass("primaryNavBtn");
    /*assignFacultyButton->clicked().connect([] {
        // Redirect to view students page
        WApplication::instance()->setInternalPath("/assignFaculty", true);
    });*/
}

void courseManagementView2::deleteCourse() {
    // Button to delete a course
    auto deleteCourseButton = addWidget(std::make_unique<WPushButton>("Delete Course"));
    deleteCourseButton->setStyleClass("removalBtn");
    deleteCourseButton->clicked().connect([] {
        // Perform deletion logic or confirmation dialog
        Wt::log("info") << "Course deleted!";
    });
}