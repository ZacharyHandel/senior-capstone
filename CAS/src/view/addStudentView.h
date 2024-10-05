/*
 * ClassMate Attendance Tracker
 * Copyright (c) 2024 South Software Solutions
 *
 * View - Add individual student to course
 * etrice,
 */
#include <Wt/WContainerWidget.h>
#include <Wt/WLineEdit.h>
#include <Wt/WPushButton.h>
#include <Wt/WText.h>

#ifndef ADDSTUDENT_H
#define ADDSTUDENT_H

using namespace Wt;

class addStudentView : public WContainerWidget {
	public:
		explicit addStudentView();
		// actual add to specific class later
	private:
		void addStudentEntry();
		void studentAdded();
		void studentNotAdded();

		WLineEdit* 		fNameInput;
		WLineEdit* 		lNameInput;
		WLineEdit* 		emailInput;
		WPushButton* 	backButton;
		WPushButton* 	submitButton;
		WText* 			lineHeader;
		WText* 			fNameLabel;
		WText* 			lNameLabel;
		WText* 			emailLabel;
};

#endif /* ADDSTUDENT_H */ 
