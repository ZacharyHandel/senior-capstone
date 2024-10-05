#ifndef ADMIN_MANAGEMENT_H
#define ADMIN_MANAGEMENT_H

#include <Wt/WContainerWidget.h>
#include <Wt/WLineEdit.h>
#include <Wt/WPushButton.h>
#include <Wt/WText.h>
#include <Wt/WComboBox.h>

class admin_management : public Wt::WContainerWidget {
public:
    admin_management();

private:
    void createAdminForm();     // Method to create the admin registration form
    void createFacultyForm();   // Method to create the faculty registration form
    void createStudentForm();   // Method to create the student registration form
    void createCourseForm();    // Method to create the course registration form
    void submitAdminForm();     // Method to handle submission of admin registration form
    void submitFacultyForm();   // Method to handle submission of faculty registration form
    void submitStudentForm();   // Method to handle submission of student registration form
    void submitCourseForm();    // Method to handle submission of course registration form
    void addBackToDashboardButton(); // Declare the method
    void backToDashboard();
    void navigateBack();
   
    Wt::WLineEdit* adminUsernameEdit;
    Wt::WLineEdit* adminPasswordEdit;
    Wt::WLineEdit* facultyNameEdit;
    Wt::WLineEdit* studentNameEdit;
    Wt::WLineEdit* courseNameEdit;
    Wt::WPushButton *backButton_;
};

#endif // ADMIN_MANAGEMENT_H

