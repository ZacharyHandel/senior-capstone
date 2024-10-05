//----------------------------------------------------------------------------
// South Software Solutions
// Austin Odom
// CAS_45: Course Management View
// To view all courses, student list, modify students and bulk onboard
//----------------------------------------------------------------------------

#include <Wt/WText.h>
#include <Wt/WLineEdit.h>

#ifndef COURSEMANAGEMENTVIEW_H
#define COURSEMANAGEMENTVIEW_H

using namespace Wt;

class courseManagementView : public WContainerWidget
{
    public:
        explicit courseManagementView();
    
    private:
        void loadCourseList();
        void viewStudentList();
        void modifyStudents();
        void bulkOnboardStudents();

        WText* lineHeader;
        WText* search;
        WLineEdit* searchEdit;
};

#endif /*COURSEMANAGEMENTVIEW_H */

