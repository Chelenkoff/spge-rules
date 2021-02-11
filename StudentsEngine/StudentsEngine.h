#pragma once

#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
#include "Student.h"
#include "StudentComparator.h"

class StudentsEngine
{
	public:

        enum Command
        {
			COMMAND_UNKNOWN				   = -1,
			COMMAND_EXIT				   = 0,
			COMMAND_ADD_STUDENT			   = 1,
			COMMAND_LIST_STUDENTS		   = 2,
			COMMAND_SORT_BY_GRADES_DESC    = 3,
			COMMAND_SORT_BY_NAME_ASC	   = 4,
			COMMAND_GET_GRADES_HIGHER_THAN = 5,

        };

		enum SortingType
		{
			SORT_DESC = 0,
			SORT_ASC
		};

		StudentsEngine();
		virtual ~StudentsEngine();

		bool init();
		void start();

		static void addStudentGUI( std::map< std::string, Student >& mStudents);
		static void getStudentsWithGradesHigherThanGUI(std::map< std::string, Student >& mStudents);

		static void printMenu();

		static bool addStudent(std::map< std::string, Student >& mStudents, const std::string& sFacultyNum, const Student& pStudent);
		static std::vector<Student> sortByGrades(SortingType eType, std::map< std::string, Student >& mStudents);
		static std::vector<Student> sortByName(SortingType eType, std::map< std::string, Student >& mStudents);
		static std::vector<Student> sortByGradesThenName(std::map< std::string, Student >& mStudents);

		static std::vector<Student> getStudentsWithGradesHigherThan(float fHigherThanValue, std::map< std::string, Student >& mStudents);

		static void listStudents(const std::map< std::string, Student >& mStudents);
		static void listStudentsVec(const std::vector< Student >& vStudents);

		static bool checkStudentExists(const std::string& sFacultyNum, const std::map< std::string, Student >& mStudents);
	private:
		void run( bool& bExit );


		std::map< std::string, Student > m_mStudents;
};

