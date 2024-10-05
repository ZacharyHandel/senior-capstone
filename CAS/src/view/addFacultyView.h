#ifndef ADDFACULTYVIEW_H
#define ADDFACULTYVIEW_H

#include <Wt/WContainerWidget.h>
#include <Wt/WLineEdit.h>
#include <Wt/WPushButton.h>
#include <Wt/WText.h>
#include <Wt/WComboBox.h>

class addFacultyView : public Wt::WContainerWidget {
public:
    addFacultyView();

private:
    void createForm();  // Method to create the form fields
    void submitButtonSetup();  // Method to setup the submit button
    Wt::WPushButton* backButton;
};

#endif // ADDFACULTYVIEW_H