#ifndef ATTENDANCEMANAGEMENTVIEW_H
#define ATTENDANCEMANAGEMENTVIEW_H

#include <Wt/WContainerWidget.h>
#include <Wt/WText.h>
#include <Wt/WTable.h>
#include <Wt/WPushButton.h>

using namespace Wt;

class attendanceManagementView : public WContainerWidget {

public:
    explicit attendanceManagementView();
private:
    void populateCoursesTable();
    void displayRecords();
    void addRecord();
	void editRecords();
	void printReport();

	WText* header;
	WTable* coursesTable;
	WPushButton* backButton;
};

#endif /* ATTENDANCEMANAGEMENTVIEW_H  */
