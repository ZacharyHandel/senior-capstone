#ifndef VIEWSTUDENTVIEW_H
#define VIEWSTUDENTVIEW_H

#include <Wt/WContainerWidget.h>
#include <Wt/WLineEdit.h>
#include <Wt/WPushButton.h>
#include <Wt/WText.h>
#include <Wt/WTable.h>

class viewStudentView : public Wt::WContainerWidget {
public:
    viewStudentView();

private:
    Wt::WLineEdit *searchInput;
    Wt::WTable *details; // Changed from Wt::WText to Wt::WTable

    void searchStudent();
};

#endif // VIEWSTUDENTVIEW_H

