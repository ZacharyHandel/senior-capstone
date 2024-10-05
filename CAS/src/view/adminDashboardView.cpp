#include "adminDashboardView.h"
#include <Wt/WApplication.h>
#include <Wt/WContainerWidget.h>
#include <Wt/WText.h>
#include <Wt/WPushButton.h>

using namespace Wt;

adminDashboardView::adminDashboardView() {
    // Existing links setup
    auto* accountManagementLink = addWidget(std::make_unique<WText>(
        "<a href='#/accountManagement' style='display: inline-block; background-color: #007ea7; color: white; padding: 5px 10px; border-radius: 5px; text-decoration: none;' "
        "onmouseover=\"this.style.backgroundColor='#5cbcdd';\" onmouseout=\"this.style.backgroundColor='#007ea7';\">Account Management</a>"
    ));
    accountManagementLink->setInternalPathEncoding(true); // Ensures clicking the link updates the internal path

    auto* courseManagementLink = addWidget(std::make_unique<WText>(
        "<a href='#/courseManagement2' style='display: inline-block; background-color: #007ea7; color: white; padding: 5px 10px; border-radius: 5px; text-decoration: none;' "
        "onmouseover=\"this.style.backgroundColor='#5cbcdd';\" onmouseout=\"this.style.backgroundColor='#007ea7';\">Course Management</a>"
    ));
    courseManagementLink->setInternalPathEncoding(true);

}
