#include "addFacultyView.h"
#include <Wt/WBreak.h>
#include <Wt/WText.h>

addFacultyView::addFacultyView() {
    auto title = addWidget(std::make_unique<Wt::WText>("Add Faculty Member"));
    title->setMargin(Wt::WLength("45%"), Wt::Side::Left | Wt::Side::Right);
    this->addWidget(std::make_unique<Wt::WBreak>());

    backButton = addWidget(std::make_unique<Wt::WPushButton>("<- Go Back"));
    backButton->setStyleClass("secondaryNavBtn");
    backButton->setFloatSide(Wt::Side::Left);
    backButton->setLink(Wt::WLink("javascript:history.back()"));

    this->addWidget(std::make_unique<Wt::WBreak>());

    this->addWidget(std::make_unique<Wt::WBreak>());

    createForm();
    this->addWidget(std::make_unique<Wt::WBreak>());
    submitButtonSetup();
}

void addFacultyView::createForm() {
    // First Name
    auto firstNameLabel = addWidget(std::make_unique<Wt::WText>("First Name:"));
    firstNameLabel->addStyleClass("inputLbl");
    auto firstNameEdit = addWidget(std::make_unique<Wt::WLineEdit>());
    firstNameEdit->setStyleClass("inputField");

    this->addWidget(std::make_unique<Wt::WBreak>());

    // Last Name
    auto lastNameLabel = addWidget(std::make_unique<Wt::WText>("Last Name:"));
    lastNameLabel->addStyleClass("inputLbl");
    auto lastNameEdit = addWidget(std::make_unique<Wt::WLineEdit>());
    lastNameEdit->setStyleClass("inputField");

    this->addWidget(std::make_unique<Wt::WBreak>());

    // Email Address
    auto emailLabel = addWidget(std::make_unique<Wt::WText>("Email Address:"));
    emailLabel->addStyleClass("inputLbl");
    auto emailEdit = addWidget(std::make_unique<Wt::WLineEdit>());
    emailEdit->setStyleClass("inputField");

    this->addWidget(std::make_unique<Wt::WBreak>());

    // Department Dropdown
    auto departmentLabel = addWidget(std::make_unique<Wt::WText>("Department:"));
    departmentLabel->addStyleClass("inputLbl");
    auto departmentCombo = addWidget(std::make_unique<Wt::WComboBox>());
    departmentCombo->addStyleClass("inputField");
    departmentCombo->addItem("Select a Department");
    departmentCombo->addItem("Mathematics");
    departmentCombo->addItem("Science");
    departmentCombo->addItem("History");
    departmentCombo->addItem("English");
    departmentCombo->addItem("Engineering");
    departmentCombo->addItem("Art & Design");
    departmentCombo->addItem("Music");
    departmentCombo->addItem("Business Studies");
    departmentCombo->addItem("Economics");
    departmentCombo->addItem("Physical Education");
    departmentCombo->addItem("Computer Science");
    departmentCombo->addItem("Political Science");
    departmentCombo->addItem("Philosophy");

    this->addWidget(std::make_unique<Wt::WBreak>());
}

void addFacultyView::submitButtonSetup() {
    auto submitButton = addWidget(std::make_unique<Wt::WPushButton>("Submit"));
    submitButton->addStyleClass("submitBtn");
    auto responseText = addWidget(std::make_unique<Wt::WText>());

    submitButton->clicked().connect([=] {
        responseText->setText("Faculty member successfully added!");
        responseText->setStyleClass("message");
    });
}