#include <Wt/WApplication.h>
#include <Wt/WEnvironment.h>
#include <Wt/WServer.h>
#include "forgotPassword.h"

ForgotPassword::ForgotPassword(Wt::WContainerWidget *parent) : 
	    Wt::WContainerWidget() {
		        setContentAlignment(Wt::AlignmentFlag::Center);

    // Email input
    emailInput_ = addWidget(std::make_unique<Wt::WLineEdit>());
    emailInput_->setPlaceholderText("Enter your registered email");
    emailInput_->setStyleClass("form-control");

    // Submit button
    submitBtn_ = addWidget(std::make_unique<Wt::WPushButton>("Reset Password"));
    submitBtn_->setStyleClass("submitBtn");

    addWidget(std::make_unique<Wt::WBreak>());

    // Response text
    responseText_ = addWidget(std::make_unique<Wt::WText>());

    submitBtn_->clicked().connect(this, &ForgotPassword::onResetClicked);
}

void ForgotPassword::onResetClicked() {
    const std::string email = emailInput_->text().toUTF8();
    if (!email.empty()) {
        responseText_->setText("If your email is registered, you will receive a password reset link.");
    } else {
        responseText_->setText("Please enter a valid email address.");
    }
}
