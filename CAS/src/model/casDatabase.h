#ifndef CASDB_H
#define CASDB_H

#include <Wt/Dbo/Dbo.h>
#include <Wt/Dbo/backend/Sqlite3.h>

#include <chrono>

#include "User.h"
#include "SCA.h"
#include "Course.h"

namespace dbo= Wt::Dbo;

class User;
class SCA;
class Course;

void run();

#endif //CASDB_H
