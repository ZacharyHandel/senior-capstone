#include <string>

#include <Wt/WApplication.h>
#include <Wt/WContainerWidget.h>
#include <Wt/WText.h>
#include <Wt/Dbo/Dbo.h>
#include <Wt/Dbo/backend/Sqlite3.h>
#include <Wt/WLineEdit.h>
#include <Wt/WPushButton.h>

#ifndef CASAPP_H
#define CASAPP_H

using namespace Wt;

class casApp: public Wt::WApplication {
	public:
		explicit casApp(const Wt::WEnvironment &env);

	private:
		void onInternalPathChange();
		void createNavigationContainer();
		void showLoginScreen();
		//void createFooterContainer();
		
		std::string 		appName;
		WContainerWidget* 	content;
		WText*			header;
		WText*			emailLbl;
		WText*			passwordLbl;
		WLineEdit*		email;
		WLineEdit*		password;
		WPushButton*		loginButton;
		WPushButton*		forgotPassButton;
};

#endif /*CASAPP_H*/
