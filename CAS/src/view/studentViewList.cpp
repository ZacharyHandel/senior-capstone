/*
 * ClassMate Attendance Tracker
 * Copyright (c) 2024 South Software Solutions
 *
 * View - Student List View
 * vikuma,
 */
#include <memory>
#include <string>

#include <Wt/WBreak.h>
#include <Wt/WPushButton.h>
#include <Wt/WComboBox.h>
#include <Wt/WTable.h>
#include <Wt/WString.h>

#include "studentViewList.h"

using namespace Wt;

studentViewList::studentViewList()
{
	this->setContentAlignment(AlignmentFlag::Center);
	
	lineHeader = addWidget(std::make_unique<WText>("Students View List"));
	lineHeader->setInline(false);
	lineHeader->setPadding(WLength("0.5em"), Side::Bottom);

	this->addWidget(std::make_unique<WBreak>());	

	backButton = addWidget(std::make_unique<WPushButton>("<- Go Back"));
	backButton->setStyleClass("secondaryNavBtn");
	backButton->setFloatSide(Side::Left);
	backButton->setLink(*std::make_unique<WLink>("javascript:history.back()"));

	backButton->clicked().connect([=] { });

	comboBoxButton();
	
}


void studentViewList::comboBoxButton(){

	comboBox = addWidget(std::make_unique<Wt::WComboBox>());

/**************************** DUMMY COURSES **********************************/
	comboBox -> addItem("CS 155");
	comboBox -> addItem("CS 255");
	comboBox -> addItem("CS 355");
	comboBox -> addItem("CS 455");
/*****************************************************************************/


	auto enterButton = std::make_unique<WPushButton>("Enter");
	enterButton->setStyleClass("submitBtn");
	enterButton->setMargin(WLength("2em"), Side::Top);

	enterButton->clicked().connect(this, &studentViewList::listStudents);
	
	this->addWidget(std::move(enterButton));
}

// USES DUMMY DATA
void studentViewList::listStudents(){

        selectedCourse = comboBox->currentText();
	
	if (table !=nullptr) {
		removeWidget(table);
		table = nullptr;
	} 

	table = addWidget(std::make_unique<WTable>());
	table->setWidth(WLength("50%"));
	table->setStyleClass("dataTable");


/*********************** DUMMY DATA FOR STUDENTS AND ATTENDANCE *********************************/
	std::vector<std::pair<std::string, std::string>> dummyData;

	if(selectedCourse == "CS 155"){
		dummyData = {
			{"April Moore", "Present"},
			{"John Smith", "Absent"},
			{"Allison Lee", "Present"}
		};
	}
	else if(selectedCourse == "CS 255"){
		dummyData = {
			{"Hilary Fort", "Present"},
			{"Ethan Jones", "Present"},
			{"David Moore", "Absent"}
		};
	}
	else if(selectedCourse == "CS 355"){
		dummyData = {
			{"Conner M", "Absent"},
			{"Andrew O", "Present"},
			{"Michael I", "Absent"}
		};
	}
	else{
		dummyData = {{"No data available", ""}};

	}
/*****************************************************************************************************/


	WText* nameLabel1 = table->elementAt(0,0)->addWidget(std::make_unique<WText>("Students"));
	nameLabel1->setStyleClass("inputLb1");
	WText* nameLabel2 = table->elementAt(0,1)->addWidget(std::make_unique<WText>("Attendence"));
	nameLabel2->setStyleClass("inputLb1");

	for (int i = 0; i < dummyData.size(); ++i){
		table->elementAt(i + 1, 0)->addWidget(std::make_unique<Wt::WText>(dummyData[i].first));
		table->elementAt(i + 1, 1)->addWidget(std::make_unique<Wt::WText>(dummyData[i].second));
	}
	
}

