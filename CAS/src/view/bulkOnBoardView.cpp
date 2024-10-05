#include <fstream>
#include <memory>
#include <ostream>
#include <sstream>
#include <string>

#include <Wt/WBreak.h>
#include <Wt/WContainerWidget.h>
#include <Wt/WProgressBar.h>
#include <Wt/WWidget.h>

#include "bulkOnBoardView.h"

using namespace Wt;

bulkOnBoardView::bulkOnBoardView()
{
	this->setContentAlignment(AlignmentFlag::Center);
	lineHeader = addWidget(std::make_unique<WText>("Bulk On-Board Students"));
	this->addWidget(std::make_unique<WBreak>());

	selectFile();
	this->addWidget(std::make_unique<WBreak>());

	submitFile();
	submitButton->disable();
	this->addWidget(std::make_unique<WBreak>());

	formatGuidelines();
	this->addWidget(std::make_unique<WBreak>());

	backButton = addWidget(std::make_unique<WPushButton>("<- Go Back"));
	backButton->setStyleClass("secondaryNavBtn");
	backButton->setFloatSide(Side::Left);
	backButton->setLink(*std::make_unique<WLink>("javascript:history.back()"));

	backButton->clicked().connect([=] { });
}

void
bulkOnBoardView::selectFile()
{
	// Upload widget
	upload = addWidget(std::make_unique<WFileUpload>());
	upload->setFilters(".csv");
	
	// Create progress bar
	auto uploadBar = addWidget(std::make_unique<WProgressBar>());
	uploadBar->setHidden(true);
	uploadBar->setFormat(WString("%0.f%%"));
	uploadBar->setMargin(10, Side::Right);

	// Assign progress bar to upload widget
	upload->setProgressBar(uploadBar);

	// Upload status line
	status = addWidget(std::make_unique<WText>());

	// Upload button
	uploadButton = addWidget(std::make_unique<WPushButton>("Upload file"));
	uploadButton->setStyleClass("submitBtn");
	uploadButton->setMargin(10, Side::Left | Side::Right);

	// Upload file when upload button is clicked
	uploadButton->clicked().connect([=] {
		upload->upload();
		uploadButton->disable();
		submitButton->enable();
		uploadBar->setHidden(false);
	});

	// React to file upload finish
	upload->uploaded().connect([=] {
		fileName = upload->spoolFileName();
		clientName = upload->clientFileName().toUTF8();
		upload->stealSpooledFile();
		status->setText("File upload finished.");
		displayFile();
	});

	// React to file too large
	upload->fileTooLarge().connect([=] {
		status->setText("File is too large.");
	});
}

void
bulkOnBoardView::displayFile()
{
	/*displayedFile->addWidget(std::make_unique<WContainerWidget>());

	// Read in from file
	std::ifstream inFile(fileName);
	std::stringstream buffer;
	buffer << inFile.rdbuf();
	std::string inStr = buffer.str();

	// Create widgets
	wFileName = addWidget(std::make_unique<WText>(clientName));
	wFileDesc = addWidget(std::make_unique<WText>(inStr));

	// Move widgets into display container
	displayedFile->addWidget(std::move(wFileName));
	displayedFile->addWidget(std::make_unique<WBreak>());
	displayedFile->addWidget(std::move(wFileDesc));*/
}

void
bulkOnBoardView::submitFile()
{
	// Create submit button
	submitButton = addWidget(std::make_unique<WPushButton>("Submit file"));
	submitButton->setStyleClass("submitBtn");
	submitButton->setMargin(10, Side::Left | Side::Right);
	
	submitButton->clicked().connect([=] {
		this->clear();
		//send to backend

		//if success
		this->addWidget(std::make_unique<WText>("Students successfully added!"));
		this->addWidget(std::make_unique<WBreak>());

		// Go back to course
		backButton = addWidget(std::make_unique<WPushButton>("<- Go Back to Course"));
		backButton->setStyleClass("secondaryNavBtn");
		backButton->setFloatSide(Side::Left);
		//backButton->setLink(*std::make_unique<WLink>("javascript:history.back()"));

		//backButton->clicked().connect([=] { });
		
		//else deny
	});
}

void
bulkOnBoardView::formatGuidelines()
{
	// Create format guide
	formatGuide = addWidget(std::make_unique<WText>("Below is a formatted example."));
	this->addWidget(std::make_unique<WBreak>());

	// Put entire format into one string
	std::stringstream example;
	example << "<courseID>,<termID>,<instructor>,<studentEmail>,<studentFirstName>,<studentLastName>";
	example << std::endl << "20226,1,James Jerkins,erice3@una.edu,Ethan,Rice";
	example << std::endl << "20226,1,James Jerkins,zahandel@una.edu,Zachary,Handel";
	example << std::endl << "20226,1,James Jerkins,jogray7@una.edu,Joseph,Gray";
	std::string exStr = example.str();
	
	// Print string
	WText* exampleText = addWidget(std::make_unique<WText>(exStr));
	exampleText->setTextAlignment(AlignmentFlag::Justify);
}
