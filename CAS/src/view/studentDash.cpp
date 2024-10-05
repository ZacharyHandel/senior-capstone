#include <memory>
#include <string>

#include "studentDash.h"
#include <Wt/WApplication.h>
#include <Wt/WBreak.h>
#include <Wt/WContainerWidget.h>
#include <Wt/WPushButton.h>
#include <Wt/WVBoxLayout.h>

using namespace Wt;

studentDash::studentDash() {
    // Constructor implementation
    lineHeader = addWidget(std::make_unique<WText>("Student Dashboard"));
    lineHeader->setTextAlignment(AlignmentFlag::Center);
    lineHeader->setMargin(WLength("45%"), Side::Left | Side::Right);
    this->addWidget(std::make_unique<WBreak>());

    loadName();
    loadCourses();

    this->addWidget(std::make_unique<WBreak>());
    profileSettings();
}

void studentDash::loadCourses() {
    // Container widget to hold the course list
    courseContainer = addWidget(std::make_unique<WContainerWidget>());
    courseLayout = courseContainer->setLayout(std::make_unique<WVBoxLayout>());

    // Sample coures
    std::vector<std::string> courses = {"Course 1", "Course 2", "Course 3"};

    // Create button for each course
    for (const auto& course : courses) {
        courseButton = addWidget(std::make_unique<WPushButton>(course));
        courseButton->clicked().connect([=] {
		//course->redirect("/Course 1", true);
        });
    }

}
void studentDash::profileSettings() {

    // Profile settings button.
    settingsButton = addWidget(std::make_unique<WPushButton>("Profile Settings"));
    settingsButton->clicked().connect([=] {
	//settingsButton->disable();	    
        //Will redirect to profile settings page.
    });
}

void studentDash::loadName() {
    // Load student's name
    nameText = addWidget(std::make_unique<WText>("Student Name"));
    nameText->setTextAlignment(AlignmentFlag::Center);
    nameText->setMargin(WLength("45%"), Side::Left | Side::Right);  

}








