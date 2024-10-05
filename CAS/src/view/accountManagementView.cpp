#include "accountManagementView.h"
#include <Wt/WVBoxLayout.h>
#include <Wt/WPushButton.h>
#include <Wt/WText.h>

using namespace Wt;

accountManagementView::accountManagementView() {
    auto *layout = setLayout(std::make_unique<WVBoxLayout>());
    layout->addWidget(std::make_unique<WText>("Account Management"));

    // Adding the 'Go Back' button with controlled width
    auto backButton = std::make_unique<WPushButton>("<- Go Back");
    backButton->setStyleClass("secondaryNavBtn");
    // Force the button to be 150 pixels wide, adjust this value as needed
    backButton->setAttributeValue("style", "width: 150px;");
    backButton->setLink(WLink("javascript:history.back()"));
    layout->addWidget(std::move(backButton));

    listUsers();
    addStudent();
    addFaculty();
    editUser();
    deleteUser();
}

void accountManagementView::listUsers() {
    // Placeholder for user listing table
    auto* layout = dynamic_cast<WVBoxLayout*>(this->layout());
    layout->addWidget(std::make_unique<WText>("List of Users Placeholder"));
}

void accountManagementView::addStudent() {
    auto* layout = dynamic_cast<WVBoxLayout*>(this->layout());
    auto addButton = std::make_unique<WPushButton>("Add Student");
    addButton->setStyleClass("primaryNavBtn");
    layout->addWidget(std::move(addButton));
}

void accountManagementView::addFaculty() {
    auto* layout = dynamic_cast<WVBoxLayout*>(this->layout());
    auto addButton = std::make_unique<WPushButton>("Add Faculty");
    addButton->setStyleClass("primaryNavBtn");
    layout->addWidget(std::move(addButton));
}

void accountManagementView::editUser() {
    auto* layout = dynamic_cast<WVBoxLayout*>(this->layout());
    auto editButton = std::make_unique<WPushButton>("Edit User");
    editButton->setStyleClass("primaryNavBtn");
    layout->addWidget(std::move(editButton));
}

void accountManagementView::deleteUser() {
    auto* layout = dynamic_cast<WVBoxLayout*>(this->layout());
    auto deleteButton = std::make_unique<WPushButton>("Delete User");
    deleteButton->setStyleClass("removalBtn");
    layout->addWidget(std::move(deleteButton));
}
