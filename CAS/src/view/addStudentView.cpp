/*
 * ClassMate Attendance Tracker
 * Copyright (c) 2024 South Software Solutions
 *
 * View - Add individual student to course
 * etrice,
 */
#include <memory>

#include <Wt/WBreak.h>

#include "addStudentView.h"

using namespace Wt;

addStudentView::addStudentView()
{
	this->setContentAlignment(AlignmentFlag::Center);

	lineHeader = addWidget(std::make_unique<WText>("Add Student to Course"));
	lineHeader->setInline(false);
	lineHeader->setPadding(WLength("0.5em"), Side::Bottom);
	this->addWidget(std::make_unique<WBreak>());

	addStudentEntry();
	
	this->addWidget(std::make_unique<WBreak>());
	backButton = addWidget(std::make_unique<WPushButton>("<- Go Back"));
	backButton->setStyleClass("secondaryNavBtn");
	backButton->setFloatSide(Side::Left);
	backButton->setLink(*std::make_unique<WLink>("javascript:history.back()"));

	backButton->clicked().connect([=] { });
}

void
addStudentView::addStudentEntry()
{
	fNameLabel = addWidget(std::make_unique<WText>("First Name:"));
	fNameLabel->setStyleClass("inputLbl");

	fNameInput = addWidget(std::make_unique<WLineEdit>());
	fNameInput->setMargin(WLength("1em"), Side::Right);

	lNameLabel = addWidget(std::make_unique<WText>("Last Name:"));
	lNameLabel->setStyleClass("inputLbl");

	lNameInput = addWidget(std::make_unique<WLineEdit>());
	lNameInput->setMargin(WLength("1em"), Side::Right);


	emailLabel = addWidget(std::make_unique<WText>("Email:"));
	emailLabel->setStyleClass("inputLbl");

	emailInput = addWidget(std::make_unique<WLineEdit>());

	this->addWidget(std::make_unique<WBreak>());

	submitButton = addWidget(std::make_unique<WPushButton>("Submit"));
	submitButton->setStyleClass("submitBtn");
	submitButton->setMargin(WLength("2em"), Side::Top);

	submitButton->clicked().connect([=] {
		// send student info to backend

		// if adding successful
		studentAdded();
		// else
		// studentNotAdded();
	});
}

void
addStudentView::studentAdded()
{
	this->clear();

	this->setContentAlignment(AlignmentFlag::Center);
	lineHeader = addWidget(std::make_unique<WText>("Student successfully added!"));
	lineHeader->setInline(false);
	lineHeader->setPadding(WLength("0.5em"), Side::Bottom);
	this->addWidget(std::make_unique<WBreak>());

	backButton = addWidget(std::make_unique<WPushButton>("<- Add Another"));
	backButton->setStyleClass("secondaryNavBtn");
	backButton->setMargin(WLength("1em"), Side::Left | Side::Right);
	//backButton->setLink(*std::make_unique<WLink>("add student to course link"));

	backButton->clicked().connect([=] { });

	WPushButton* backCourseButton = addWidget(std::make_unique<WPushButton>("Back to Course"));
	backCourseButton->setStyleClass("secondaryNavBtn");
	backCourseButton->setMargin(WLength("1em"), Side::Left | Side::Right);
	//backCourseButton->setLink(*std::make_unique<WLink>("course link here"));
	
	backCourseButton->clicked().connect([=] { });
}
