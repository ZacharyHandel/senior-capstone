#include "attendanceManagementView.h"
#include <Wt/WBreak.h>
#include <Wt/WContainerWidget.h>
#include <Wt/WPushButton.h>
#include <Wt/WTableCell.h>

using namespace Wt;

attendanceManagementView::attendanceManagementView() {
	setContentAlignment(AlignmentFlag::Center);

	header = addWidget(std::make_unique<WText>("Attendance Management"));
	header->setInline(false);
	header->setPadding(WLength("0.5em"), Side::Bottom);
	addWidget(std::make_unique<WBreak>());

	populateCoursesTable();

	backButton = addWidget(std::make_unique<WPushButton>("<- Go Back"));
	backButton->setStyleClass("secondaryNavBtn");
	backButton->setFloatSide(Side::Left);
	backButton->setLink(*std::make_unique<WLink>("javascript:history.back()"));
	backButton->clicked().connect([=]{ });
}

void attendanceManagementView::populateCoursesTable() {
	coursesTable = addWidget(std::make_unique<WTable>());
	coursesTable->setStyleClass("dataTable");

	// Add table headers
	WText* courseHeader = coursesTable->elementAt(0, 0)->addWidget(std::make_unique<WText>("Courses"));
	courseHeader->setStyleClass("dataTableHeader");

																	WText* actionsHeader = coursesTable->elementAt(0,1)->addWidget(std::make_unique<WText>("Actions"));
	actionsHeader->setStyleClass("dataTableHeader");

	// Example data 
	std::vector<std::string> courseNames = {"Course 1", "Course 2", "Course 3"};

	// Populate table with course names and action buttons
	for (size_t i = 0; i < courseNames.size(); ++i) {
		// Add course name
		coursesTable->elementAt(i + 1, 0)->addWidget(std::make_unique<WText>(courseNames[i]));

		// Add action buttons
		WPushButton* displayRecordsButton = coursesTable->elementAt(i + 1, 1)->addWidget(std::make_unique<WPushButton>("Display Records"));
		displayRecordsButton->setStyleClass("primaryNavBtn");
		displayRecordsButton->clicked().connect(this, &attendanceManagementView::displayRecords);

		WPushButton* addRecordButton = coursesTable->elementAt(i + 1, 1)->addWidget(std::make_unique<WPushButton>("Add Record"));
		addRecordButton->setStyleClass("primaryNavBtn");
		addRecordButton->clicked().connect(this, &attendanceManagementView::addRecord);
	
		WPushButton* editRecordsButton = coursesTable->elementAt(i + 1, 1)->addWidget(std::make_unique<WPushButton>("Edit/Delete Records"));
		editRecordsButton->setStyleClass("primaryNavBtn");
		editRecordsButton->clicked().connect(this, &attendanceManagementView::editRecords);

		WPushButton* printReportButton = coursesTable->elementAt(i + 1, 1)->addWidget(std::make_unique<WPushButton>("Print Report"));
		printReportButton->setStyleClass("primaryNavBtn");
		printReportButton->clicked().connect(this, &attendanceManagementView::printReport);
	}
}

void attendanceManagementView::displayRecords() {
	// Handle display records button click
}

void attendanceManagementView::addRecord() {
	// Handle add record button click
}

void attendanceManagementView::editRecords() {
	// Handle edit records button click
}

void attendanceManagementView::printReport() {
	// Handle print report button click
}
