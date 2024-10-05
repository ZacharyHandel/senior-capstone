/*
 * Attendance Tracker
 * Copyright (c) 2024 South Software Solutions
 *
 * View - Bulk add students to a course
 * etrice,
 */
#include <string>

#include <Wt/WFileUpload.h>
#include <Wt/WPushButton.h>
#include <Wt/WText.h>

#ifndef BULKONBOARD_H
#define BULKONBOARD_H

using namespace Wt;

class bulkOnBoardView : public WContainerWidget {
	public:
		explicit bulkOnBoardView();
		
	private:
		void formatGuidelines();
		void selectFile();
		void displayFile();
		void submitFile();

		std::string fileName;
		std::string clientName;
		//WContainerWidget* displayedFile;
		WFileUpload* upload;
		WPushButton* backButton;
		WPushButton* uploadButton;
		WPushButton* submitButton;
		//WText* wFileName;
		//WText* wFileDesc;
		WText* lineHeader;
		WText* formatGuide;
		WText* status;
};

#endif /* BULKONBOARDVIEW_H */

