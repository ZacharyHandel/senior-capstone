#include "casDatabase.h"
void run() {
	//setting up session
	std::unique_ptr<dbo::backend::Sqlite3> sqlite3(new dbo::backend::Sqlite3("casDatabase"));
	sqlite3->setProperty("show-queries", "true");
	dbo::Session session;
	session.setConnection(std::move(sqlite3));

	//map classes
	session.mapClass<User >("User");
	session.mapClass<SCA >("SCA");
	session.mapClass<Course >("Course");

	//create tables (will fail if already exists)
	session.createTables();

	{
		dbo::Transaction transaction(session);

		//establish db tables
		std::unique_ptr<User> u{new User()};
		u->userName = "john1";
		u->firstName = "John";
		u->lastName = "Doe";
		u->role = Role::Student;
		u->email = "jdoe@una.edu";
		u->password = "123456";
		//...
		
		std::unique_ptr<SCA> sca{new SCA()};
		sca->userName = "john1";
		sca->courseId = 1;
		sca->semesterId = 1;
		sca->attended = false;
		sca->date = "PLACEHOLDER";

		std::unique_ptr<Course> c{new Course()};
		c->courseId = 1;
		c->semesterId = 1;
		c->faculty = "James Jerkins";
		c->student = "John Doe";
		c->duration = 150;
		
		dbo::ptr<User> john = session.add(std::move(u));
		dbo::ptr<SCA> entry1 = session.add(std::move(sca));
		dbo::ptr<Course> course1 = session.add(std::move(c));
	}
}
