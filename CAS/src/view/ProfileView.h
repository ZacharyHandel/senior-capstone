// profileview.h
#ifndef PROFILEVIEW_H
#define PROFILEVIEW_H

#include <Wt/WContainerWidget.h>
#include <Wt/WLineEdit.h>
#include <Wt/WPushButton.h>
#include <Wt/WText.h>
#include <memory>

class ProfileView : public Wt::WContainerWidget {
public:
    ProfileView();

private:
    std::unique_ptr<Wt::WLineEdit> currentPasswordEdit_;
    std::unique_ptr<Wt::WLineEdit> newPasswordEdit_;
    std::unique_ptr<Wt::WLineEdit> confirmPasswordEdit_;
    std::unique_ptr<Wt::WText> messageText_;

    void changePassword();
};

#endif // PROFILEVIEW_H