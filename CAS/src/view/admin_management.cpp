#include "admin_management.h"
#include <Wt/WBreak.h>
#include <Wt/WApplication.h>
#include <iostream> // For testing placeholder logic

admin_management::admin_management() {
    createAdminForm();
    createFacultyForm();
    createStudentForm();
    createCourseForm();
    addBackToDashboardButton();

}

void admin_management::createAdminForm() {

     this->addWidget(std::make_unique<Wt::WBreak>());

    // Admin registration form fields
    auto adminTitle = addWidget(std::make_unique<Wt::WText>("Admin Registration"));
    adminTitle->setMargin(Wt::WLength("0%"), Wt::Side::Left | Wt::Side::Right);
    this->addWidget(std::make_unique<Wt::WBreak>());

    auto adminUsernameLabel = addWidget(std::make_unique<Wt::WText>("Username:"));
    adminUsernameLabel->addStyleClass("inputLbl");
    adminUsernameEdit = addWidget(std::make_unique<Wt::WLineEdit>());
    adminUsernameEdit->setStyleClass("inputField");
    this->addWidget(std::make_unique<Wt::WBreak>());

    auto adminPasswordLabel = addWidget(std::make_unique<Wt::WText>("Password:"));
    adminPasswordLabel->addStyleClass("inputLbl");
    adminPasswordEdit = addWidget(std::make_unique<Wt::WLineEdit>());
    adminPasswordEdit->setStyleClass("inputField");
    adminPasswordEdit->setEchoMode(Wt::EchoMode::Password);
    this->addWidget(std::make_unique<Wt::WBreak>());

    auto submitButton = addWidget(std::make_unique<Wt::WPushButton>("Submit"));
    auto responseText = addWidget(std::make_unique<Wt::WText>());
    submitButton->addStyleClass("submitBtn");

    submitButton->clicked().connect([=] {
        submitAdminForm();
        responseText->setText("Admin registration successful!");
        responseText->setStyleClass("message");
    });
}
void admin_management::createFacultyForm() {
    this->addWidget(std::make_unique<Wt::WBreak>());
    this->addWidget(std::make_unique<Wt::WBreak>());
    // Faculty registration form fields
    auto facultyTitle = addWidget(std::make_unique<Wt::WText>("Faculty Registration"));
    facultyTitle->setMargin(Wt::WLength("0%"), Wt::Side::Left | Wt::Side::Right);
    this->addWidget(std::make_unique<Wt::WBreak>());

    auto facultyNameLabel = addWidget(std::make_unique<Wt::WText>("Name:"));
    facultyNameLabel->addStyleClass("inputLbl");
    facultyNameEdit = addWidget(std::make_unique<Wt::WLineEdit>());
    facultyNameEdit->setStyleClass("inputField");
    this->addWidget(std::make_unique<Wt::WBreak>());

    auto adminPasswordLabel = addWidget(std::make_unique<Wt::WText>("Password:"));
    adminPasswordLabel->addStyleClass("inputLbl");
    adminPasswordEdit = addWidget(std::make_unique<Wt::WLineEdit>());
    adminPasswordEdit->setStyleClass("inputField");
    adminPasswordEdit->setEchoMode(Wt::EchoMode::Password);
    this->addWidget(std::make_unique<Wt::WBreak>());

    auto submitButton = addWidget(std::make_unique<Wt::WPushButton>("Submit"));
    auto responseText = addWidget(std::make_unique<Wt::WText>());
    submitButton->addStyleClass("submitBtn");

    submitButton->clicked().connect([=] {
        submitFacultyForm();
        responseText->setText("    Faculty registration successful!");
        responseText->setStyleClass("message");
    });
}

void admin_management::createStudentForm() {
    this->addWidget(std::make_unique<Wt::WBreak>());
    this->addWidget(std::make_unique<Wt::WBreak>());
    // Student registration form fields
    auto studentTitle = addWidget(std::make_unique<Wt::WText>("Student Registration"));
    studentTitle->setMargin(Wt::WLength("0%"), Wt::Side::Left | Wt::Side::Right);
    this->addWidget(std::make_unique<Wt::WBreak>());

    auto studentNameLabel = addWidget(std::make_unique<Wt::WText>("Name:"));
    studentNameLabel->addStyleClass("inputLbl");
    studentNameEdit = addWidget(std::make_unique<Wt::WLineEdit>());
    studentNameEdit->setStyleClass("inputField");
    this->addWidget(std::make_unique<Wt::WBreak>());

    auto adminPasswordLabel = addWidget(std::make_unique<Wt::WText>("Password:"));
    adminPasswordLabel->addStyleClass("inputLbl");
    adminPasswordEdit = addWidget(std::make_unique<Wt::WLineEdit>());
    adminPasswordEdit->setStyleClass("inputField");
    adminPasswordEdit->setEchoMode(Wt::EchoMode::Password);
    this->addWidget(std::make_unique<Wt::WBreak>());

    auto submitButton = addWidget(std::make_unique<Wt::WPushButton>("Submit"));
    auto responseText = addWidget(std::make_unique<Wt::WText>());
    submitButton->addStyleClass("submitBtn");

    submitButton->clicked().connect([=] {
        submitStudentForm();
        responseText->setText("    Student registration successful!");
        responseText->setStyleClass("message");
    });
}  

void admin_management::createCourseForm() {
    this->addWidget(std::make_unique<Wt::WBreak>());
    this->addWidget(std::make_unique<Wt::WBreak>());
    // Course registration form fields
    auto courseTitle = addWidget(std::make_unique<Wt::WText>("Course Registration"));
    courseTitle->setMargin(Wt::WLength("0%"), Wt::Side::Left | Wt::Side::Right);
    this->addWidget(std::make_unique<Wt::WBreak>());

    auto courseNameLabel = addWidget(std::make_unique<Wt::WText>("Name:"));
    courseNameLabel->addStyleClass("inputLbl");
    courseNameEdit = addWidget(std::make_unique<Wt::WLineEdit>());
    courseNameEdit->setStyleClass("inputField");
    this->addWidget(std::make_unique<Wt::WBreak>());

    // Add additional course registration form fields here

    auto submitButton = addWidget(std::make_unique<Wt::WPushButton>("Submit"));
    auto responseText = addWidget(std::make_unique<Wt::WText>());
    submitButton->addStyleClass("submitBtn");

    submitButton->clicked().connect([=] {
        submitCourseForm();
        responseText->setText("    Course registration successful!");
        responseText->setStyleClass("message");
    });
}

void admin_management::submitAdminForm() {
    // Logic to handle admin registration form submission
    std::string username = adminUsernameEdit->text().toUTF8();
    std::string password = adminPasswordEdit->text().toUTF8();
    // Placeholder logic for admin registration
    std::cout << "Admin Registration - Username: " << username << ", Password: " << password << std::endl;
}

void admin_management::submitFacultyForm() {
    // Logic to handle faculty registration form submission
    std::string facultyName = facultyNameEdit->text().toUTF8();
    // Placeholder logic for faculty registration
    std::cout << "Faculty Registration - Name: " << facultyName << std::endl;
}

void admin_management::submitStudentForm() {
    // Logic to handle student registration form submission
    std::string studentName = studentNameEdit->text().toUTF8();
    // Placeholder logic for student registration
    std::cout << "Student Registration - Name: " << studentName << std::endl;
}

void admin_management::submitCourseForm() {
    // Logic to handle course registration form submission
    std::string courseName = courseNameEdit->text().toUTF8();
    // Placeholder logic for course registration
    std::cout << "Course Registration - Name: " << courseName << std::endl;
}

void admin_management::addBackToDashboardButton() {
    this->addWidget(std::make_unique<Wt::WBreak>());
    backButton_ = addWidget(std::make_unique<Wt::WPushButton>("Back to Dashboard"));
    backButton_->setStyleClass("primaryNavBtn");
    backButton_->clicked().connect(this, &admin_management::navigateBack);
}

void admin_management::navigateBack() {
    // Change the internal path to the dashboard
    Wt::WApplication::instance()->setInternalPath("/dashboard", true);
}

