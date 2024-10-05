#include <memory>
#include <string>

#include <Wt/WBreak.h>
#include <Wt/WContainerWidget.h>
#include <Wt/WPushButton.h>
#include <Wt/WTableCell.h>

#include "modifyStudentListView.h"

using namespace Wt;

modifyStudentListView::modifyStudentListView() {
	this->setContentAlignment(AlignmentFlag::Center);

	header = addWidget(std::make_unique<WText>("Modify Student List"));
	header->setInline(false);
	header->setPadding(WLength("0.5em"), Side::Bottom);
	this->addWidget(std::make_unique<WBreak>());

	populateStudentsTable();
}

void
modifyStudentListView::populateStudentsTable() {
	studentsTable = addWidget(std::make_unique<WTable>());
	studentsTable->setStyleClass("dataTable");


	WText* nameLabel = studentsTable->elementAt(0, 0)->addWidget(std::make_unique<WText>("Name"));
	nameLabel->setStyleClass("inputLbl");

	WText* actionsLabel = studentsTable->elementAt(0, 1)->addWidget(std::make_unique<WText>("Actions"));
	actionsLabel->setStyleClass("inputLbl");

	//dummy data (REMOVE IN BACKEND DEVELOPMENT)
	std::vector<std::string> studentNames = {
		"Emily Johnson", 
		"Michael Rodriguez", 
		"Sophia Martinez", 
		"Jacob Smith", 
		"Isabella Brown", 
		"Ethan Lee", 
		"Olivia Garcia", 
		"William Davis", 
		"Ava Hall", 
		"David McKinnon"};
	
	//Table Population
	for (size_t i = 0; i < studentNames.size(); i++) {
		studentsTable->elementAt(i + 1, 0)->addWidget(std::make_unique<WText>(studentNames[i]));

		WPushButton* editButton = studentsTable->elementAt(i + 1, 1)->addWidget(std::make_unique<WPushButton>("Edit Profile"));
		editButton->setStyleClass("primaryNavBtn");
		editButton->clicked().connect(this, &modifyStudentListView::editProfile);
		editButton->setMargin(WLength("0.5em"), Side::Right);
		editButton->setMargin(WLength("0.5em"), Side::Bottom);

		WPushButton* removeButton = studentsTable->elementAt(i+1, 1)->addWidget(std::make_unique<WPushButton>("Remove"));
		removeButton->setStyleClass("removalBtn");
		removeButton->clicked().connect(this, &modifyStudentListView::removeStudent);
		removeButton->setMargin(WLength("0.5em"), Side::Bottom);
	}
}

void
modifyStudentListView::editProfile() {
}

void
modifyStudentListView::removeStudent() {
}
