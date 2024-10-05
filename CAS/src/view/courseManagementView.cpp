#include <memory>
#include <string>
#include <Wt/WBreak.h>
#include <Wt/WPushButton.h>
#include <Wt/WContainerWidget.h>
#include <Wt/WTable.h>
#include <Wt/WTableCell.h>
#include "courseManagementView.h"

using namespace Wt;

courseManagementView::courseManagementView()
{
    lineHeader = addWidget(std::make_unique<WText>("Course Management"));
    lineHeader->setMargin(WLength("45%"), Side::Left | Side::Right);
    this->addWidget(std::make_unique<WBreak>());

    search = addWidget(std::make_unique<WText>("Search Course: "));
    searchEdit = addWidget(std::make_unique<WLineEdit>());

    this->addWidget(std::make_unique<WBreak>());

    loadCourseList();
}

void courseManagementView::loadCourseList()
{
    /* DUMMY DATA FOR COURSES   */
    /* This WILL NOT be present */ 
    /* during implementation.   */
    std::string courses[] = 
    {
        "CS 155",
        "CS 255",
        "CS 355",
        "CS 455",
        "CS 310"
    };

    auto table = std::make_unique<Wt::WTable>();
    
    for (int i = 0; i < 5; ++i)
    {
        int row = i + 1;

        table->elementAt(row, 0)->addNew<Wt::WText>(courses[i]);
        
        // Add buttons to each row for the action
        table->elementAt(row, 1)
        ->addWidget(std::make_unique<Wt::WPushButton>("View Student List"));

        table->elementAt(row, 2)
        ->addWidget(std::make_unique<Wt::WPushButton>("Modify Students"));

        table->elementAt(row, 3)
        ->addWidget(std::make_unique<Wt::WPushButton>("Upload File"));
    }
    this->addWidget(std::move(table));
}

/* Method to change the view on button click */
void courseManagementView::viewStudentList()
{

}

/* Method to change the view on button click */
void courseManagementView::modifyStudents()
{

}

/* Method to change the view on button click */
void courseManagementView::bulkOnboardStudents()
{

}








