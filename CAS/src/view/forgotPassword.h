#ifndef FORGOT_PASSWORD_H
#define FORGOT_PASSWORD_H

#include <Wt/WContainerWidget.h>
#include <Wt/WLineEdit.h>
#include <Wt/WPushButton.h>
#include <Wt/WText.h>
#include <Wt/WFormWidget.h>

class ForgotPassword : public Wt::WContainerWidget {
public:
    ForgotPassword(Wt::WContainerWidget *parent = nullptr);

private:
    Wt::WLineEdit *emailInput_;
    Wt::WPushButton *submitBtn_;
    Wt::WText *responseText_;

    void onResetClicked();
};

#endif // FORGOT_PASSWORD_H
