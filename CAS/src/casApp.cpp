#include <memory>
#include <utility>

#include <Wt/WAnchor.h>
#include <Wt/WApplication.h>
#include <Wt/WBootstrap5Theme.h>
#include <Wt/WContainerWidget.h>
#include <Wt/WText.h>
#include <Wt/WBreak.h>

#include "casApp.h"

#include "model/casDatabase.h"

#include "view/bulkOnBoardView.h"
#include "view/studentDash.h"
#include "view/headerFooter.h"
#include "view/FacultyDashboardView.h"
#include "view/forgotPassword.h"
#include "view/studentCourseView.h"
#include "view/courseManagementView.h"
#include "view/studentViewList.h"
#include "view/adminDashboardView.h"
#include "view/accountManagementView.h"
#include "view/courseManagementView2.h"
#include "view/admin_management.h"
#include "view/attendanceManagementView.h"
#include "view/addFacultyView.h"
#include "view/displayRecordView.h"
#include "view/ProfileView.h"
#include "view/viewStudentView.h"
#include "view/addStudentView.h"
#include "view/modifyStudentListView.h"
#include "view/recordAttendanceView.h"



//INCLUDE VIEWS

using namespace Wt;

casApp::casApp(const WEnvironment& env)
	: WApplication(env), appName("ClassMate")
{
	//App Title
	setTitle(appName);

	//include styling
	useStyleSheet("styles.css");

	// Install path handler
	internalPathChanged().connect(this, &casApp::onInternalPathChange);

	// Create base UI
	//createHeaderContainer();
	createNavigationContainer();

        auto baseContainer = root()->addWidget(std::make_unique<Wt::WContainerWidget>());
        baseContainer->addWidget(std::make_unique<headerFooter>());

	auto contentContainer =  std::make_unique<WContainerWidget>();
	content = contentContainer.get();
	root()->addWidget(std::move(contentContainer));

	//RUN DB
	run();
}

void
casApp::createNavigationContainer()
{
	// create a container for a navigation bar and add menu items

	// CHANGE WHEN HEADER FUNCTIONALITY IS FIXED
	auto t = std::make_unique<WText>("<a href='#/studentDashboard'>Student Dashboard\\</a>");
	t->setInternalPathEncoding(true);
	root()->addWidget(std::move(t));

	t = std::make_unique<WText>("<a href='#/studentCourse'>Student Course\\</a>");
	t->setInternalPathEncoding(true);
	root()->addWidget(std::move(t));


	t = std::make_unique<WText>("<a href='#/recordAttendance'>Record Attendance\\</a>");
	t->setInternalPathEncoding(true);
	root()->addWidget(std::move(t));

	t = std::make_unique<WText>("<a href='#/facultyDashboard'>Faculty Dashboard\\</a>");
	t->setInternalPathEncoding(true);
	root()->addWidget(std::move(t));

	t = std::make_unique<WText>("<a href='#/adminDashboard'>Admin Dashboard\\</a>");
	t->setInternalPathEncoding(true);
	root()->addWidget(std::move(t));

	t = std::make_unique<WText>("<a href='#/bulkOnBoard'>Bulk On Board\\</a>");
	t->setInternalPathEncoding(true);
	root()->addWidget(std::move(t));

	t = std::make_unique<WText>("<a href='#/forgotPassword'>Forgot Password\\</a>");
	t->setInternalPathEncoding(true);
	root()->addWidget(std::move(t));

	t = std::make_unique<WText>("<a href='#/courseManagement'>Course Management\\</a>");
	t->setInternalPathEncoding(true);
	root()->addWidget(std::move(t));

	t = std::make_unique<WText>("<a href='#/studentList'>Student List\\</a>");
	t->setInternalPathEncoding(true);
	root()->addWidget(std::move(t));

	t = std::make_unique<WText>("<a href='#/adminManagement'>Admin Management\\</a>");
	t->setInternalPathEncoding(true);
	root()->addWidget(std::move(t));

	t = std::make_unique<WText>("<a href='#/attendanceManagement'>Attendance Management\\</a>");
	t->setInternalPathEncoding(true);
	root()->addWidget(std::move(t));


	t = std::make_unique<WText>("<a href='#/addFaculty'>Add Faculty</a>");
	t->setInternalPathEncoding(true);
	root()->addWidget(std::move(t));


	t = std::make_unique<WText>("<a href='#/displayRecord'>Display Record\\</a>");
	t->setInternalPathEncoding(true);
	root()->addWidget(std::move(t));


	t = std::make_unique<WText>("<a href='#/profile'>Profile\\</a>");
	t->setInternalPathEncoding(true);
	root()->addWidget(std::move(t));


	t = std::make_unique<WText>("<a href='#/viewStudent'>View Student\\</a>");
	t->setInternalPathEncoding(true);
	root()->addWidget(std::move(t));

	t = std::make_unique<WText>("<a href='#/modifyStudentList'>Modify Student List\\</a>");
	t->setInternalPathEncoding(true);
	root()->addWidget(std::move(t));

	t = std::make_unique<WText>("<a href='#/login'>Login</a>");
	t->setInternalPathEncoding(true);
	root()->addWidget(std::move(t));

}

void
casApp::onInternalPathChange()
{
	assert(content != nullptr);

	content->clear();

	// Add subsequent views in alphabetical order
	if (internalPath() == "/bulkOnBoard") {
		content->addWidget(std::make_unique<bulkOnBoardView>());
	} else if (internalPath() == "/facultyDashboard") {
		content->addWidget(std::make_unique<FacultyDashboardView>());
	} else if (internalPath() == "/forgotPassword") {
		content->addWidget(std::make_unique<ForgotPassword>());
	} else if (internalPath() == "/studentCourse") {
		content->addWidget(std::make_unique<studentCourseView>());
	} else if (internalPath() == "/courseManagement") {
		content->addWidget(std::make_unique<courseManagementView>());
	} else if (internalPath() == "/studentList") {
		content->addWidget(std::make_unique<studentViewList>());
	} else if (internalPath() == "/adminDashboard") {
		content->addWidget(std::make_unique<adminDashboardView>());
	} else if (internalPath() == "/accountManagement") {
		content->addWidget(std::make_unique<accountManagementView>());
	} else if (internalPath() == "/courseManagement2") {
		content->addWidget(std::make_unique<courseManagementView2>());
	} else if (internalPath() == "/adminManagement") {
		content->addWidget(std::make_unique<admin_management>());
	} else if (internalPath() == "/attendanceManagement") {
		content->addWidget(std::make_unique<attendanceManagementView>());
	} else if (internalPath() == "/addFaculty") {
		content->addWidget(std::make_unique<addFacultyView>());
	} else if (internalPath() == "/displayRecord") {
		content->addWidget(std::make_unique<displayRecordView>());
	} else if (internalPath() == "/profile") {
		content->addWidget(std::make_unique<ProfileView>());
	} else if (internalPath() == "/viewStudent") {
		content->addWidget(std::make_unique<viewStudentView>());
	} else if (internalPath() == "/login") {
		showLoginScreen();
	} else if (internalPath() == "/studentDashboard") {
		content->addWidget(std::make_unique<studentDash>());
	} else if (internalPath() == "/recordAttendance") {
		content->addWidget(std::make_unique<recordAttendanceView>());
	} else if (internalPath() == "/modifyStudentList") {
		content->addWidget(std::make_unique<modifyStudentListView>());
	} else {
		content->addWidget(std::make_unique<WText>("<h3><b>Something went wrong... (._.)</b></h3>"));
	}
 
}


void
casApp::showLoginScreen()
{
        // make all of the content appear in the center of the page
        root()->setContentAlignment(AlignmentFlag::Center);
        
        header = root()->addWidget(std::make_unique<WText>("CLASSMATE"));

	// 4 breaks for a bigger space
        root()->addWidget(std::make_unique<WBreak>());
        root()->addWidget(std::make_unique<WBreak>());
        root()->addWidget(std::make_unique<WBreak>());
        root()->addWidget(std::make_unique<WBreak>());

        emailLbl = root()->addWidget(std::make_unique<WText>("EMAIL:  "));
        emailLbl->setStyleClass("inputLbl");
        email = root()->addWidget(std::make_unique<WLineEdit>());

        // 2 breaks for a bigger space
        root()->addWidget(std::make_unique<WBreak>());
        root()->addWidget(std::make_unique<WBreak>());

        passwordLbl = root()->addWidget(std::make_unique<WText>("PASSWORD:   "));
        passwordLbl->setStyleClass("inputLbl");
        password = root()->addWidget(std::make_unique<WLineEdit>());

        // 2 breaks for a bigger space
        root()->addWidget(std::make_unique<WBreak>());
        root()->addWidget(std::make_unique<WBreak>());

        // buttons for login and forgot password
        loginButton = root()->addWidget(std::make_unique<WPushButton>("LOGIN"));
        loginButton->setStyleClass("submitBtn");
        loginButton->setMargin(5);
 
        forgotPassButton = root()->addWidget(std::make_unique<WPushButton>("FORGOT PASSWORD"));
        forgotPassButton->setStyleClass("secondaryNavBtn");
        forgotPassButton->setMargin(5);

	root()->addWidget(std::make_unique<WBreak>());

	//fake login
	auto fakeLogin = std::make_unique<WText>("<a href='#/facultyDashboard'>LOGIN</a>");
	fakeLogin->setInternalPathEncoding(true);
	root()->addWidget(std::move(fakeLogin));
}
