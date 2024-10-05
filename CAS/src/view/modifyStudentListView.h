#ifndef MODIFYSTUDENTLISTVIEW_H
#define MODIFYSTUDENTLISTVIEW_H

#include <Wt/WContainerWidget.h>
#include <Wt/WText.h>
#include <Wt/WTable.h>
#include <Wt/WPushButton.h>

using namespace Wt;

class modifyStudentListView : public WContainerWidget {
public:
	explicit modifyStudentListView();
private:
	void populateStudentsTable();
	void editProfile();
	void removeStudent();

	WText* 		header;
	WTable* 	studentsTable;

};

#endif // MODIFYSTUDENTLISTVIEW_H
