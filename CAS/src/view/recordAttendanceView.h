#ifndef RECORDATTENDANCEVIEW_H
#define RECORDATTENDANCEVIEW_H

#include <Wt/WContainerWidget.h>
#include <Wt/WText.h>
#include <Wt/WLineEdit.h>
#include <Wt/WPushButton.h>

	
using namespace Wt;

class recordAttendanceView : public WContainerWidget {
public:
	explicit recordAttendanceView();
private:
	void 		addAttendanceRecord();
	void 		displayRecordStatus();

	WText* 		lineHeader;
	WText* 		attendanceCodeInputLabel;
	WLineEdit* 	attendanceCodeInput;
	WPushButton* 	submitButton;
	WPushButton* 	backButton;
	WText* 		statusMessage;

};

#endif // RECORDATTENDANCEVIEW_H
