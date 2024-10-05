#include "headerFooter.h"
#include <Wt/WContainerWidget.h>
#include <Wt/WText.h>
#include <Wt/WPushButton.h>
#include <Wt/WLink.h>

headerFooter::headerFooter(Wt::WContainerWidget *parent) : Wt::WContainerWidget() {
    setupHeader();
    setupFooter();
}

headerFooter::~headerFooter() {}    


void headerFooter::setupHeader() {
    auto header = addWidget(std::make_unique<Wt::WContainerWidget>());
    header->setStyleClass("header");
    // Apply styles directly to the header
    header->setAttributeValue("style", "background-color: #007ea7; color: white; padding: 10px 20px; display: flex; justify-content: space-between; align-items: center; font-weight: bold; font-size: 24px;");

    // Logo and text
    auto logoText = header->addWidget(std::make_unique<Wt::WText>("CLASSMATE"));
    logoText->setStyleClass("logo-text");
    logoText->setAttributeValue("style", "font-family: 'Courier New', Courier, monospace;");

    // Navigation buttons container
    auto nav = header->addWidget(std::make_unique<Wt::WContainerWidget>());
    nav->setStyleClass("nav-buttons");
    nav->setAttributeValue("style", "display: flex;");

    // Dashboard button
    auto dashboardButton = nav->addWidget(std::make_unique<Wt::WPushButton>("Dashboard"));
    dashboardButton->setLink(Wt::WLink(Wt::LinkType::InternalPath, "#dashboard"));
    dashboardButton->setStyleClass("nav-button primary-nav");
    dashboardButton->setAttributeValue("style", "background-color: #007ea7; color: white; margin-right: 10px; border: none;");

    // User settings button
    auto settingsButton = nav->addWidget(std::make_unique<Wt::WPushButton>("User Settings"));
    settingsButton->setLink(Wt::WLink(Wt::LinkType::InternalPath, "#user-settings"));
    settingsButton->setStyleClass("nav-button primary-nav");
    settingsButton->setAttributeValue("style", "background-color: #007ea7; color: white; margin-right: 10px; border: none;");

    // Logout button
    auto logoutButton = nav->addWidget(std::make_unique<Wt::WPushButton>("Logout"));
    logoutButton->setLink(Wt::WLink(Wt::LinkType::InternalPath, "#logout"));
    logoutButton->setStyleClass("logout-button");
    logoutButton->setAttributeValue("style", "background-color: #f39c12; color: white; border: none;");
}



void headerFooter::setupFooter() {
    auto footer = addWidget(std::make_unique<Wt::WContainerWidget>());
    footer->setStyleClass("footer");
    // Apply styles directly to the footer
    footer->setStyleClass("footer");
    footer->setAttributeValue("style", "position: fixed; left: 0; right: 0; bottom: 0; background-color: #8e99a2; color: white; text-align: center; padding: 10px 0; width: 100%;");

    auto text = footer->addWidget(std::make_unique<Wt::WText>("&copy; 2024 South Software Solutions™ | All rights reserved"));
    text->setStyleClass("copy-right");
    // Ensure the text is displayed as a block element for proper centering
    text->setAttributeValue("style", "margin: 0 auto; display: block;");
}


