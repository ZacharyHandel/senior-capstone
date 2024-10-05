// profileview.cpp
#include "ProfileView.h"

ProfileView::ProfileView()
    : Wt::WContainerWidget()
{
    currentPasswordEdit_ = std::make_unique<Wt::WLineEdit>();
    newPasswordEdit_ = std::make_unique<Wt::WLineEdit>();
    confirmPasswordEdit_ = std::make_unique<Wt::WLineEdit>();
    messageText_ = std::make_unique<Wt::WText>();

    newPasswordEdit_->setEchoMode(Wt::EchoMode::Password);
    confirmPasswordEdit_->setEchoMode(Wt::EchoMode::Password);

    auto changePasswordButton = std::make_unique<Wt::WPushButton>("Change Password");
    changePasswordButton->clicked().connect(this, &ProfileView::changePassword);

    addWidget(std::move(messageText_));
    addWidget(std::move(changePasswordButton));
    addWidget(std::move(confirmPasswordEdit_));
    addWidget(std::move(newPasswordEdit_));
    addWidget(std::move(currentPasswordEdit_));
    addWidget(std::make_unique<Wt::WText>("Confirm New Password:"));
    addWidget(std::make_unique<Wt::WText>("New Password:"));
    addWidget(std::make_unique<Wt::WText>("Current Password:"));
    addWidget(std::make_unique<Wt::WText>("Change Password"));
}

void ProfileView::changePassword() {
    std::string currentPassword = currentPasswordEdit_->text().toUTF8();
    std::string newPassword = newPasswordEdit_->text().toUTF8();
    std::string confirmPassword = confirmPasswordEdit_->text().toUTF8();

    if (currentPassword.empty() || newPassword.empty() || confirmPassword.empty()) {
        messageText_->setText("Please fill in all fields.");
        return;
    }

    if (newPassword != confirmPassword) {
        messageText_->setText("New password and confirmation password do not match.");
        return;
    }

    // Code to verify current password and update password in the database
    // Replace this with your actual authentication and database logic

    // Simulated logic for demonstration purposes
    bool currentPasswordCorrect = true; // Assume current password is correct

    if (!currentPasswordCorrect) {
        messageText_->setText("Current password is incorrect.");
        return;
    }

    // Password change successful
    messageText_->setText("Password changed successfully.");
    currentPasswordEdit_->setText("");
    newPasswordEdit_->setText("");
    confirmPasswordEdit_->setText("");
}