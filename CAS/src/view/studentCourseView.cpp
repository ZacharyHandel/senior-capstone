#include "studentCourseView.h"
#include <Wt/WApplication.h>
#include <Wt/WBreak.h> // Include for adding line breaks

studentCourseView::studentCourseView(Wt::WContainerWidget *parent) : Wt::WContainerWidget() {
    // Title and instructor
    addWidget(std::make_unique<Wt::WText>("Student course View"));
    addWidget(std::make_unique<Wt::WBreak>());
    addWidget(std::make_unique<Wt::WText>("Course Title:  Software Programming"));
    addWidget(std::make_unique<Wt::WBreak>());
    addWidget(std::make_unique<Wt::WText>("Instructor:  Dr. Jerkins"));
    addWidget(std::make_unique<Wt::WBreak>());
    addWidget(std::make_unique<Wt::WBreak>());

    // Table
    attendanceTable_ = addWidget(std::make_unique<Wt::WTable>());
    attendanceTable_->addStyleClass("table table-striped table-bordered");

    // Table headers
    attendanceTable_->elementAt(0, 0)->addWidget(std::make_unique<Wt::WText>("Date"))->setStyleClass("inputLbl");
    attendanceTable_->elementAt(0, 1)->addWidget(std::make_unique<Wt::WText>("Attendance"))->setStyleClass("inputLbl");

    // Add CSS styling
    Wt::WApplication::instance()->styleSheet().addRule(".fixed-width", "font-family: monospace;");
    Wt::WApplication::instance()->styleSheet().addRule(".table-cell-padding", "padding-right: 20px;");

    // Table data
    auto dateText1 = std::make_unique<Wt::WText>("2024-05-04");
    auto attendanceText1 = std::make_unique<Wt::WText>("Present");
    dateText1->setInline(false); // Use block-level element
    attendanceText1->setInline(false); // Use block-level element
    dateText1->setStyleClass("fixed-width"); // Set style class for fixed-width font
    attendanceText1->setStyleClass("fixed-width"); // Set style class for fixed-width font
    attendanceTable_->elementAt(1, 0)->addWidget(std::move(dateText1))->setStyleClass("table-cell-padding");
    attendanceTable_->elementAt(1, 1)->addWidget(std::move(attendanceText1))->setStyleClass("table-cell-padding");

    auto dateText2 = std::make_unique<Wt::WText>("2024-05-05");
    auto attendanceText2 = std::make_unique<Wt::WText>("Absent");
    dateText2->setInline(false); // Use block-level element
    attendanceText2->setInline(false); // Use block-level element
    dateText2->setStyleClass("fixed-width"); // Set style class for fixed-width font
    attendanceText2->setStyleClass("fixed-width"); // Set style class for fixed-width font
    attendanceTable_->elementAt(2, 0)->addWidget(std::move(dateText2))->setStyleClass("table-cell-padding");
    attendanceTable_->elementAt(2, 1)->addWidget(std::move(attendanceText2))->setStyleClass("table-cell-padding");

    auto dateText3 = std::make_unique<Wt::WText>("2024-05-06");
    auto attendanceText3 = std::make_unique<Wt::WText>("Present");
    dateText3->setInline(false); // Use block-level element
    attendanceText3->setInline(false); // Use block-level element
    dateText3->setStyleClass("fixed-width"); // Set style class for fixed-width font
    attendanceText3->setStyleClass("fixed-width"); // Set style class for fixed-width font
    attendanceTable_->elementAt(3, 0)->addWidget(std::move(dateText3))->setStyleClass("table-cell-padding");
    attendanceTable_->elementAt(3, 1)->addWidget(std::move(attendanceText3))->setStyleClass("table-cell-padding");



    addWidget(std::make_unique<Wt::WBreak>());
    addWidget(std::make_unique<Wt::WBreak>());

    // Back to Dashboard button
    backButton_ = addWidget(std::make_unique<Wt::WPushButton>("Back to Dashboard"));
    backButton_->setStyleClass("primaryNavBtn");
    backButton_->clicked().connect(this, &studentCourseView::navigateBack);
}

void studentCourseView::navigateBack() {
    // Change the internal path to the dashboard
    Wt::WApplication::instance()->setInternalPath("/dashboard", true);
}

