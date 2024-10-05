PROG=app
PORT=8090
DB=casDatabase
SRCS=main.cpp casApp.cpp view/bulkOnBoardView.cpp view/studentDash.cpp view/headerFooter.cpp view/FacultyDashboardView.cpp view/forgotPassword.cpp view/studentCourseView.cpp view/courseManagementView.cpp view/studentViewList.cpp view/accountManagementView.cpp view/adminDashboardView.cpp view/courseManagementView2.cpp view/admin_management.cpp view/attendanceManagementView.cpp view/addFacultyView.cpp view/displayRecordView.cpp view/ProfileView.cpp view/viewStudentView.cpp view/addStudentView.cpp view/modifyStudentListView.cpp view/recordAttendanceView.cpp model/User.cpp model/SCA.cpp model/Course.cpp model/casDatabase.cpp
OBJS=$(SRCS:.cpp=.o)

CXXFLAGS=-Wall -std=c++17 -I/usr/local/include -I./model -I./view
LDFLAGS=-L/usr/local/lib -lwthttp -lwt -lwtdbosqlite3 -lwtdbo

.PHONY: all clean run

all: ${PROG}

${PROG}: ${OBJS}
	${CXX} ${CXXFLAGS} -o $@ ${OBJS} ${LDFLAGS}

#Compile each source file into an object file
%.o: %.cpp
	${CXX} ${CXXFLAGS} -c -o $@ $<

#### Model dependencies
model/casDatabase.o: model/casDatabase.cpp model/casDatabase.h
	${CXX} ${CXXFLAGS} -c -o $@ $<

model/User.o: model/User.cpp model/User.h
	${CXX} ${CXXFLAGS} -c -o $@ $<

model/SCA.o: model/SCA.cpp model/SCA.h
	${CXX} ${CXXFLAGS} -c -o $@ $<

model/Course.o: model/Course.cpp model/Course.h
	${CXX} ${CXXFLAGS} -c -o $@ $<

#### View dependencies
view/bulkOnBoardView.o: view/bulkOnBoardView.cpp view/bulkOnBoardView.h
	${CXX} ${CXXFLAGS} -c -o $@ $<

view/studentDash.o: view/studentDash.cpp view/studentDash.h
	${CXX} ${CXXFLAGS} -c -o $@ $<

view/headerFooter.o: view/headerFooter.cpp view/headerFooter.h
	${CXX} ${CXXFLAGS} -c -o $@ $<

view/FacultyDashboardView.o: view/FacultyDashboardView.cpp view/FacultyDashboardView.h
	${CXX} ${CXXFLAGS} -c -o $@ $<

view/forgotPassword.o: view/forgotPassword.cpp view/forgotPassword.h
	${CXX} ${CXXFLAGS} -c -o $@ $<

view/studentCourseView.o: view/studentCourseView.cpp view/studentCourseView.h
	${CXX} ${CXXFLAGS} -c -o $@ $<

view/courseManagementView.o: view/courseManagementView.cpp view/courseManagementView.h
	${CXX} ${CXXFLAGS} -c -o $@ $<

view/studentViewList.o: view/studentViewList.cpp view/studentViewList.h
	${CXX} ${CXXFLAGS} -c -o $@ $<

view/accountManagementView.o: view/accountManagementView.cpp view/accountManagementView.h
	${CXX} ${CXXFLAGS} -c -o $@ $<

view/adminDashboardView.o: view/adminDashboardView.cpp view/adminDashboardView.h
	${CXX} ${CXXFLAGS} -c -o $@ $<

view/courseManagementView2.o: view/courseManagementView2.cpp view/courseManagementView2.h
	${CXX} ${CXXFLAGS} -c -o $@ $<

view/admin_management.o: view/admin_management.cpp view/admin_management.h
	${CXX} ${CXXFLAGS} -c -o $@ $<

view/attendanceManagementView.o: view/attendanceManagementView.cpp view/attendanceManagementView.h
	${CXX} ${CXXFLAGS} -c -o $@ $<

view/addFacultyView.o: view/addFacultyView.cpp view/addFacultyView.h
	${CXX} ${CXXFLAGS} -c -o $@ $<

view/displayRecordView.o: view/displayRecordView.cpp view/displayRecordView.h
	${CXX} ${CXXFLAGS} -c -o $@ $<

view/ProfileView.o: view/ProfileView.cpp view/ProfileView.h
	${CXX} ${CXXFLAGS} -c -o $@ $<

view/viewStudentView.o: view/viewStudentView.cpp view/viewStudentView.h
	${CXX} ${CXXFLAGS} -c -o $@ $<

view/addStudentView.o: view/addStudentView.cpp view/addStudentView.h
	${CXX} ${CXXFLAGS} -c -o $@ $<

view/modifyStudentListView.o: view/modifyStudentListView.cpp view/modifyStudentListView.h
	${CXX} ${CXXFLAGS} -c -o $@ $<

view/recordAttendanceView.o: view/recordAttendanceView.cpp view/recordAttendanceView.h
	${CXX} ${CXXFLAGS} -c -o $@ $<




#Utilities
clean:
	@rm -f ${PROG} ${OBJS} ${DB} *.core

run: ${PROG}
	./${PROG} --docroot . --http-address 0.0.0.0 --http-port ${PORT} &
