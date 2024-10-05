#include "viewStudentView.h"
#include <Wt/WTable.h>
#include <Wt/WTableCell.h>
#include <Wt/WPushButton.h>

using namespace Wt;

viewStudentView::viewStudentView() {
    addStyleClass("add-faculty-view");
    setContentAlignment(AlignmentFlag::Center); // Align content to the center

    // Adding the search input and button
    addWidget(std::make_unique<WText>("Enter Student ID:"));
    searchInput = addWidget(std::make_unique<WLineEdit>());
    searchInput->setFocus();

    auto* searchButton = addWidget(std::make_unique<WPushButton>("Search"));
    searchButton->clicked().connect(this, &viewStudentView::searchStudent);
    searchButton->addStyleClass("submitBtn");

    addWidget(std::make_unique<WText>("Example IDs: 100, 101, 102, 103, 104"));

    // Table to display details
    auto table = addWidget(std::make_unique<WTable>());
    table->addStyleClass("table table-striped table-hover"); // Assuming Bootstrap styles for table

    table->elementAt(0, 0)->addWidget(std::make_unique<WText>("First Name"));
    table->elementAt(0, 1)->addWidget(std::make_unique<WText>(""));
    table->elementAt(1, 0)->addWidget(std::make_unique<WText>("Last Name"));
    table->elementAt(1, 1)->addWidget(std::make_unique<WText>(""));
    table->elementAt(2, 0)->addWidget(std::make_unique<WText>("Email Address"));
    table->elementAt(2, 1)->addWidget(std::make_unique<WText>(""));
    table->elementAt(3, 0)->addWidget(std::make_unique<WText>("Department"));
    table->elementAt(3, 1)->addWidget(std::make_unique<WText>(""));
    table->elementAt(4, 0)->addWidget(std::make_unique<WText>("Attendance Record"));
    table->elementAt(4, 1)->addWidget(std::make_unique<WText>(""));

    details = table; // Storing the table as the 'details' widget
}

void viewStudentView::searchStudent() {
    const std::string studentId = searchInput->text().toUTF8();
    std::string studentInfo;

    // Clear existing details in the table
    for (int i = 0; i < 5; i++) {
        details->elementAt(i, 1)->clear();
    }

    // Simulated database lookup based on student ID
    if (studentId == "100") {
        details->elementAt(0, 1)->addWidget(std::make_unique<WText>("John"));
        details->elementAt(1, 1)->addWidget(std::make_unique<WText>("Doe"));
        details->elementAt(2, 1)->addWidget(std::make_unique<WText>("john.doe@example.com"));
        details->elementAt(3, 1)->addWidget(std::make_unique<WText>("Computer Science"));
        details->elementAt(4, 1)->addWidget(std::make_unique<WText>("95%"));
    }else if (studentId == "101") {
        details->elementAt(0, 1)->addWidget(std::make_unique<WText>("Jane"));
        details->elementAt(1, 1)->addWidget(std::make_unique<WText>("Smith"));
        details->elementAt(2, 1)->addWidget(std::make_unique<WText>("jane.smith@example.com"));
        details->elementAt(3, 1)->addWidget(std::make_unique<WText>("Biology"));
        details->elementAt(4, 1)->addWidget(std::make_unique<WText>("89%"));
    }else if (studentId == "102") {
        details->elementAt(0, 1)->addWidget(std::make_unique<WText>("Mike"));
        details->elementAt(1, 1)->addWidget(std::make_unique<WText>("Brown"));
        details->elementAt(2, 1)->addWidget(std::make_unique<WText>("mike.brown@example.com"));
        details->elementAt(3, 1)->addWidget(std::make_unique<WText>("Chemistry"));
        details->elementAt(4, 1)->addWidget(std::make_unique<WText>("92%"));
    }else if (studentId == "103") {
        details->elementAt(0, 1)->addWidget(std::make_unique<WText>("Sarah"));
        details->elementAt(1, 1)->addWidget(std::make_unique<WText>("Williams"));
        details->elementAt(2, 1)->addWidget(std::make_unique<WText>("sarah.williams@example.com"));
        details->elementAt(3, 1)->addWidget(std::make_unique<WText>("Physics"));
        details->elementAt(4, 1)->addWidget(std::make_unique<WText>("98%"));
    }else if (studentId == "104") {
        details->elementAt(0, 1)->addWidget(std::make_unique<WText>("David"));
        details->elementAt(1, 1)->addWidget(std::make_unique<WText>("Miller"));
        details->elementAt(2, 1)->addWidget(std::make_unique<WText>("david.miller@example.com"));
        details->elementAt(3, 1)->addWidget(std::make_unique<WText>("Mathematics"));
        details->elementAt(4, 1)->addWidget(std::make_unique<WText>("90%"));
    }else {
        for (int i = 0; i < 5; i++) {
            details->elementAt(i, 1)->addWidget(std::make_unique<WText>("Not found"));
        }
    }
}


