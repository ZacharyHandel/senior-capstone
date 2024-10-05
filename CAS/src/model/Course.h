#ifndef COURSE_H
#define COURSE_H

#include <Wt/Dbo/Dbo.h>
#include <Wt/Dbo/backend/Sqlite3.h>

namespace dbo = Wt::Dbo;

class Course {
public:
	int courseId;
	int semesterId;
	std::string faculty;
	std::string student;
	std::string courseName;
	int duration;

	template<class Action>
	void persist(Action& a)
	{
		dbo::id(a, courseId, "courseId");
		dbo::field(a, semesterId, "semesterId");
		dbo::field(a, faculty, "faculty");
		dbo::field(a, student, "student");
		dbo::field(a, courseName, "courseName");
		dbo::field(a, duration, "duration");
	}

};

namespace Wt {
	namespace Dbo {
		
		template<>
		struct dbo_traits<Course> : public dbo_default_traits {
			using IdType = int;

			static IdType invalidId() {
				return int();
			}

			static const char *surrogateIdField() {
				return nullptr;
			}
		};
	}
}
#endif //COURSE_H
