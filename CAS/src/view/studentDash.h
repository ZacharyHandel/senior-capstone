#ifndef STUDENTDASH_H
#define STUDENTDASH_H

#include <Wt/WContainerWidget.h>
#include <Wt/WPushButton.h>
#include <Wt/WVBoxLayout.h>
#include <Wt/WText.h>
using namespace Wt;

class studentDash : public WContainerWidget {
public:
    explicit studentDash();
private:

    void loadCourses(); // Function to load the enrolled courses
    void profileSettings(); // Function for profile settings
    void loadName(); // Function to load the student's name
	WPushButton* settingsButton;
	WPushButton* courseButton;
	WContainerWidget* courseContainer;
	WVBoxLayout* courseLayout;
	WText* nameText;
	WText* lineHeader;
};

#endif /* STUDENTDASH_H */

