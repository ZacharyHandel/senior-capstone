//User Model

#ifndef USER_H
#define USER_H

#include <Wt/Dbo/Dbo.h>
#include <Wt/Dbo/backend/Sqlite3.h>

enum class Role {
	Student = 0,
	Faculty = 1,
	Admin = 2
};

namespace dbo = Wt::Dbo;

class User {
public:
	std::string userName;
	std::string firstName;
	std::string lastName;
	Role 		role;
	std::string email;
	std::string password;


	template<class Action>
	void persist(Action& a)
	{
		dbo::id(a, userName, "userName");
		dbo::field(a, firstName, "firstName");
		dbo::field(a, lastName, "lastName");
		dbo::field(a, role, "role");
		dbo::field(a, email, "email");
		dbo::field(a, password, "password");
	}
};

namespace Wt {
	namespace Dbo {

		template<>
		struct dbo_traits<User> : public dbo_default_traits {
			using IdType = std::string;

			static IdType invalidId() {
				return std::string();
			}

			static const char *surrogateIdField() {
				return nullptr;
			}
		};
	}
}


#endif //USER_H
