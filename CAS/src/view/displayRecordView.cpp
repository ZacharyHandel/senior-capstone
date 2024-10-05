/*
*   Name:           Thomas Johnson
*   Course-Section: CS-455-01
*   Assignment:     CAS
*   Date Due:       5/7/2024
*   Collaborators:  
*   Resources:
*   Description:    Window for displaying a selected class's attendance records
*/

#include "displayRecordView.h"

displayRecordView::displayRecordView()
	: WContainerWidget()
{
    //database = &db;

    lineHeader = addWidget(std::make_unique<WText>("Display Records"));
	lineHeader->setMargin(WLength("45%"), Side::Left | Side::Right);

    this->addWidget(std::make_unique<WBreak>());

    classBox = addWidget(std::make_unique<WComboBox>());
    /* EXAMPLE DATA */
    classBox->addItem("CS-455-01");
    classBox->addItem("CS-440-01");
    classBox->addItem("CS-410W-01");
    /****************/
    classBox->activated().connect(this, &displayRecordView::onSelectionChanged);

    this->addWidget(std::make_unique<WBreak>());
    this->addWidget(std::make_unique<WBreak>());

    classTxt = addWidget(std::make_unique<WText>());
    this->addWidget(std::make_unique<WBreak>());

    numStudTxt = addWidget(std::make_unique<WText>());
    this->addWidget(std::make_unique<WBreak>());

    numDaysTxt = addWidget(std::make_unique<WText>());
    this->addWidget(std::make_unique<WBreak>());

    attTxt = addWidget(std::make_unique<WText>());
}

void displayRecordView::onSelectionChanged()
{
    int numStudents = 0;//db->getNumStudents(currClass);
    int numDays = 0;//db->getCourse(currClass).duration;
    float avgAtt = 0;
    std::string currClass = (classBox->currentText()).toUTF8();

    std::string text = "Class:\t" + currClass;
        //"\nSTUDENT CLASS RECORDS HERE\n";
    classTxt->setText(text);

    text = "\nNumber of Students:\t" +  std::to_string(numStudents);
    numStudTxt->setText(text);

    text = "\nDay:\t" + std::to_string(numDays);
    numDaysTxt->setText(text);

    text = "\nAverage Attendance:\t"+ std::to_string(avgAtt);
    attTxt->setText(text);

}