#ifndef ACCOUNTMANAGEMENTVIEW_H
#define ACCOUNTMANAGEMENTVIEW_H

#include <Wt/WContainerWidget.h>
#include <Wt/WPushButton.h>
#include <Wt/WText.h>

using namespace Wt;

class accountManagementView : public WContainerWidget {
public:
    explicit accountManagementView();
private:
    void listUsers();  // Display a table of users
    void addStudent(); // Button to add student
    void addFaculty(); // Button to add faculty
    void editUser();   // Button to edit user
    void deleteUser(); // Button to delete user
};

#endif /* ACCOUNTMANAGEMENTVIEW_H */