#ifndef SCA_H
#define SCA_H

#include <Wt/Dbo/Dbo.h>
#include <Wt/Dbo/backend/Sqlite3.h>
#include <Wt/WDate.h>

#include <chrono>

namespace dbo = Wt::Dbo;

class SCA {
public:
	std::string userName;
	int courseId;
	int semesterId;
	bool attended;
	std::string date;

	template<class Action>
	void persist(Action& a)
	{
		dbo::field(a, userName, "userName");
		dbo::field(a, courseId, "courseId");
		dbo::field(a, semesterId, "semesterId");
		dbo::field(a, attended, "attended");
		dbo::field(a, date, "date");
	}
};

#endif //SCA_H
