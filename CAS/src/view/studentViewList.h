/*
 * ClassMate Attendance Tracker
 * Copyright (c) 2024 South Software Solutions
 *
 * View - Student List View
 * vikuma
 */
#include <Wt/WText.h>
#include <Wt/WLineEdit.h>
#include <Wt/WComboBox.h>
#include <Wt/WString.h>
#include <Wt/WTable.h>

#ifndef STUDENTVIEWLIST_H
#define STUDENTVIEWLIST_H

using namespace Wt;

class studentViewList : public WContainerWidget
{
	public:
		explicit studentViewList();
	
	private:
		void listStudents();
		void comboBoxButton();
		void clearTable();

		WPushButton* backButton;
			
		WText* lineHeader;
		WComboBox *comboBox;	
		WString selectedCourse;
		WTable *table; 
};

#endif /*STUDENTVIEWLIST_H */

