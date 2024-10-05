#include <memory>
#include <string>

#include <Wt/WBreak.h>
#include <Wt/WContainerWidget.h>
#include <Wt/WProgressBar.h>
#include <Wt/WLineEdit.h>
#include <Wt/WPushButton.h>
#include <Wt/WText.h>
#include <Wt/WApplication.h>

#include "recordAttendanceView.h"

using namespace Wt;

recordAttendanceView::recordAttendanceView()
{
	this->setContentAlignment(AlignmentFlag::Center);

	lineHeader = addWidget(std::make_unique<WText>("Record Attendance"));
	lineHeader->setInline(false);
	lineHeader->setPadding(WLength("0.5em"), Side::Bottom);
	this->addWidget(std::make_unique<WBreak>());

	addAttendanceRecord();	

	this->addWidget(std::make_unique<WBreak>());
	backButton = addWidget(std::make_unique<WPushButton>("<- Go Back"));
	backButton->setStyleClass("secondaryNavBtn");
	backButton->setFloatSide(Side::Left);
	backButton->setLink(*std::make_unique<WLink>("javascript:history.back()"));

	backButton->clicked().connect([=] { });
}

void
recordAttendanceView::addAttendanceRecord() {
	attendanceCodeInputLabel = addWidget(std::make_unique<WText>("Code: "));
	attendanceCodeInputLabel->setStyleClass("inputLbl");

	attendanceCodeInput = addWidget(std::make_unique<WLineEdit>());
	attendanceCodeInput->setMargin(WLength("1em"), Side::Right);
	attendanceCodeInput->setPlaceholderText("XXXXXX");

	this->addWidget(std::make_unique<WBreak>());

	submitButton = addWidget(std::make_unique<WPushButton>("Submit"));
	submitButton->setStyleClass("submitBtn");
	submitButton->setMargin(WLength("2em"), Side::Top);

	submitButton->clicked().connect([=] {
		this->clear();
		
		std::wstring attendanceCodeValue = attendanceCodeInput->text().value();
		//handle click
		bool isValidInput = (attendanceCodeInput->text().toUTF8().size() == 6) &&
					std::all_of(std::begin(attendanceCodeValue), 
							std::end(attendanceCodeValue),
							[](char c) {
								return std::iswalnum(static_cast<unsigned char>(c));
							});

		if (isValidInput) {
			lineHeader = addWidget(std::make_unique<WText>("Attendance Recorded. Welcome to Class!"));
			lineHeader->setInline(false);
			lineHeader->setPadding(WLength("0.5em"), Side::Bottom);
			this->addWidget(std::make_unique<WBreak>());
		} else {
			lineHeader = addWidget(std::make_unique<WText>("Something went wrong... Contact your instructor for more information"));
			lineHeader->setInline(false);
			this->addWidget(std::make_unique<WBreak>());
			this->addWidget(std::make_unique<WText>("<h3>(._.)</h3>"));
		}

		backButton = addWidget(std::make_unique<WPushButton>("<- Go Back"));
		backButton->setStyleClass("secondaryNavBtn");
		backButton->setFloatSide(Side::Left);
		backButton->clicked().connect([=] {
			this->clear();
			this->addWidget(std::make_unique<recordAttendanceView>());
			});
	
	

	});
}
