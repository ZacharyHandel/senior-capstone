/*
*   Name:           Thomas Johnson
*   Course-Section: CS-455-01
*   Assignment:     CAS
*   Date Due:       5/7/2024
*   Collaborators:  
*   Resources:
*   Description:    Window for displaying a selected class's attendance records
*/

#ifndef DISPLAY_RECORD
#define DISPLAY_RECORD

#include <Wt/WContainerWidget.h>
#include <Wt/Dbo/Dbo.h>
#include <Wt/WBreak.h>
#include <Wt/WComboBox.h>
#include <Wt/WText.h>
#include <string>

//#include "../model/casDatabase.h"

using namespace Wt;

class displayRecordView : public WContainerWidget {
	public:
		explicit displayRecordView();
		
	private:
		void onSelectionChanged();

		WComboBox* classBox;
        WText* lineHeader;
		WText* classTxt;
		WText* numStudTxt;
		WText* numDaysTxt;
		WText* attTxt;

		//Database* database;
};

#endif /* DISPLAY_RECORD */

