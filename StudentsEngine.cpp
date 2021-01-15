

#include <iostream>
#include <map>
#include <utility>
#include <string>
//#include <sstream>
#include "StudentsEngine.h"


StudentsEngine::StudentsEngine()
{
	//constructor
}

StudentsEngine::~StudentsEngine()
{
	//destructor
}

bool StudentsEngine::init()
{
	m_mStudents.clear();
	return true;
}

void StudentsEngine::start()
{
	std::string sHeader("");
	sHeader = "            /+_\n"
		"        ........  /   +_ ........\n"
		"      .........../     /............\n"
		"    ............/      >..............\n"
		"  .............(      >................\n"
		" ............./      /..................\n"
		"............./     /.....................\n"
		"............/      /.....................\n"
		".........__/      \\_____.................\n"
		" ......./'             +................\n"
		"  ......./     /+\\     /...............\n"
		"   ...../      /  \\++/................-------------------------------------------------+\n"
		"    .../     /.......................                                                  |\n"
		"      /      /.....................8888ba  88888888ba    ,ad8888ba,  88888888888       |\n"
		"     (      >....................\"     \"8b 88      \"8b  d8\"'    `\"8b 88                |\n"
		"    /      >...................Y8,         88      ,8P d8'           88                |\n"
		"   /     _+ .................  `Y8aaaaa,   88aaaaaa8P' 88            88aaaaa           |\n"
		"  /  __/      .............|     `\"\"\"\"\"8b, 88\"\"\"\"\"\"'   88      88888 88\"\"\"\"\"           |\n"
		" /_/            .........  |           `8b 88          Y8,        88 88                |\n"
		"                  .....    |   Y8a     a8P 88           Y8a.    .a88 88                |\n"
		"                   ...     |    \"Y88888P\"  88            `\"Y88888P\"  88888888888       |\n"
		"                    .      |                                                           |\n"
		"                           |                                                           |\n"
		"                           |                                                           |\n"
		"                           |   88888888ba              88                      88      |\n"
		"                           |   88      \"8b             88                      88      |\n"
		"                           |   88      ,8P             88                      88      |\n"
		"                           |   88aaaaaa8P' 88       88 88  ,adPPYba, ,adPPYba, 88      |\n"
		"                           |   88\"\"\"\"88'   88       88 88 a8P_____88 I8[    \"\" 88      |\n"
		"                           |   88    `8b   88       88 88 8PP\"\"\"\"\"\"\"  `\"Y8ba,  \"\"      |\n"
		"                           |   88     `8b  \"8a,   ,a88 88 \"8b,   ,aa aa    ]8I aa      |\n"
		"                           |   88      `8b  `\"YbbdP'Y8 88  `\"Ybbd8\"' `\"YbbdP\"' 88      |\n"
		"                           |                                                           |\n"
		"                           +----------------------------------------------------------->\n";
	std::cout << sHeader;
	bool bExit(false);
	while (!bExit) { run(bExit); }
}

void StudentsEngine::run(bool& bExit)
{
	printMenu();

	int nCommand;
	std::string sCommand("");
	std::cout << "Your choice:";
	std::getline(std::cin, sCommand);

	nCommand = std::stoi(sCommand);


	//std::cin >> nCommand;

	switch (nCommand)
	{
		case COMMAND_UNKNOWN:
			break;

		case COMMAND_ADD_STUDENT:
			addStudentGUI(m_mStudents);
			listStudents(m_mStudents);
			break;

		case COMMAND_SORT_BY_GRADES_DESC:
			listStudentsVec(sortByGrades(SORT_DESC, m_mStudents));
			break;

		case COMMAND_SORT_BY_NAME_ASC:
			listStudentsVec(sortByName(SORT_ASC, m_mStudents));
			break;

		case COMMAND_GET_GRADES_HIGHER_THAN:
			getStudentsWithGradesHigherThanGUI(m_mStudents);
			break;

		case COMMAND_EXIT:
			bExit = true;
			break;

		case COMMAND_LIST_STUDENTS:
			listStudents( m_mStudents );
			break;

		default:
			break;
	}
}

void StudentsEngine::addStudentGUI(std::map< std::string, Student >& mStudents)
{
	std::cout << "You have choosen to add student.\n" << "Enter faculty number:" << std::endl;

	std::string sFacultyNumber("");
	std::getline(std::cin, sFacultyNumber);

	if (sFacultyNumber.empty())
	{
		std::cout << "Provided faculty number is empty !" << std::endl;
		return;
	}
		
	if( checkStudentExists(sFacultyNumber, mStudents) )
	{
		std::cout << "Student with faculty number: '" + sFacultyNumber + "' already exists!" << std::endl;
		return;
	}

	std::string sStudentName("");
	std::cout << "Enter student name:";
	std::getline(std::cin, sStudentName);

	if (sStudentName.empty())
	{
		std::cout << "Provided student name is empty !" << std::endl;
		return;
	}

	std::cout << "Enter course name:";
	std::string sCourseName("");
	std::getline(std::cin, sCourseName);

	if (sCourseName.empty())
	{
		std::cout << "Provided course name is empty !" << std::endl;
		return;
	}

	std::string sGrade("");
	float fGrade(0.0);
	std::cout << "Enter student grade:";
	std::getline(std::cin, sGrade);

	try
	{
		fGrade = std::stof(sGrade);
	}
	catch (...) 
	{
		std::cout << "Invalid grade value:" << sGrade << std::endl;
		return;
	}

	Student pStudent;
	pStudent.setFacultyNum(sFacultyNumber);
	pStudent.setStudentName(sStudentName);
	pStudent.setCourseName(sCourseName);
	pStudent.setGrade(fGrade);

	addStudent(mStudents, pStudent.getFacultyNum(), pStudent);
}

void StudentsEngine::getStudentsWithGradesHigherThanGUI(std::map< std::string, Student >& mStudents)
{
	std::cout << "You have choosen to retrieve students with grade higher than certain value.\n" << "Enter Grade value:" << std::endl;

	std::string sGrade("");
	float fGrade(0.0);
	std::cout << "Enter student grade:";
	std::getline(std::cin, sGrade);

	try
	{
		fGrade = std::stof(sGrade);
	}
	catch (...)
	{
		std::cout << "Invalid grade value:" << sGrade << std::endl;
		return;
	}

	listStudentsVec(getStudentsWithGradesHigherThan(fGrade, mStudents));
}


bool StudentsEngine::addStudent(std::map< std::string, Student >& mStudents, const std::string& sFacultyNum, const Student& pStudent)
{
	if (sFacultyNum.empty())
	{
		return false;
	}

	if (pStudent.getFacultyNum().empty())
	{
		return false;
	}



	Student* pTmpStudent = 0;

	std::map< std::string, Student >::const_iterator iterMap = mStudents.find(sFacultyNum);
	if ( iterMap != mStudents.end() ) 
	{
		// student already exists
	}
	else 
	{
		// add new student
		mStudents.insert(std::pair<std::string, Student>(pStudent.getFacultyNum(), pStudent));
	}

	return true;
}

std::vector<Student> StudentsEngine::sortByGrades(SortingType eType, std::map< std::string, Student >& mStudents)
{
	std::map< std::string, Student >::const_iterator iterStudents = mStudents.begin();
	std::vector<Student> vTmpStudents;
	for (; iterStudents != mStudents.end(); ++iterStudents)
	{
		vTmpStudents.push_back(iterStudents->second);
	}

	StudentComparator::CompareByOpt eOpt = StudentComparator::COMPARE_BY_UNKNOWN;
	if (eType == SORT_ASC) eOpt = StudentComparator::COMPARE_BY_GRADE_ASC;
	else if (eType == SORT_DESC) eOpt = StudentComparator::COMPARE_BY_GRADE_DESC;

	std::sort(vTmpStudents.begin(), vTmpStudents.end(), StudentComparator(eOpt));

	return vTmpStudents;
}

std::vector<Student> StudentsEngine::sortByName(SortingType eType, std::map< std::string, Student >& mStudents)
{
	std::map< std::string, Student >::const_iterator iterStudents = mStudents.begin();
	std::vector<Student> vTmpStudents;
	for (; iterStudents != mStudents.end(); ++iterStudents)
	{
		vTmpStudents.push_back(iterStudents->second);
	}

	StudentComparator::CompareByOpt eOpt = StudentComparator::COMPARE_BY_UNKNOWN;
	if (eType == SORT_ASC) eOpt = StudentComparator::COMPARE_BY_NAME_ASC;
	else if (eType == SORT_DESC) eOpt = StudentComparator::COMPARE_BY_NAME_DESC;

	std::sort(vTmpStudents.begin(), vTmpStudents.end(), StudentComparator(eOpt));

	return vTmpStudents;
}

std::vector<Student> StudentsEngine::getStudentsWithGradesHigherThan(float fHigherThanValue, std::map< std::string, Student >& mStudents)
{
	std::map< std::string, Student >::const_iterator iterStudents = mStudents.begin();

	//isolate eligible ones
	std::map< std::string, Student > mTmpEligibleStudents;
	for (; iterStudents != mStudents.end(); ++iterStudents)
	{
		if (iterStudents->second.getGrade() > fHigherThanValue)
		{
			addStudent(mTmpEligibleStudents, iterStudents->first, iterStudents->second);
		}
	}

	return sortByGradesThenName(mTmpEligibleStudents);
}

std::vector<Student> StudentsEngine::sortByGradesThenName(std::map< std::string, Student >& mStudents)
{
	std::map< std::string, Student >::const_iterator iterStudents = mStudents.begin();
	std::vector<Student> vTmpStudents;
	for (; iterStudents != mStudents.end(); ++iterStudents)
	{
		vTmpStudents.push_back(iterStudents->second);
	}

	StudentComparator::CompareByOpt eOpt = StudentComparator::COMPARE_BY_GRADES_ASC_NAME_ASC;


	std::sort(vTmpStudents.begin(), vTmpStudents.end(), StudentComparator(eOpt));

	return vTmpStudents;
}


void StudentsEngine::listStudents(const std::map< std::string, Student >& mStudents)
{
	if (mStudents.size() == 0)
	{
		std::cout << "There are no students available!\n";
		return;
	}

	std::cout << "The students are:\n";
	std::map< std::string, Student >::const_iterator iterStudents = mStudents.begin();
	for (; iterStudents != mStudents.end(); ++iterStudents)
	{
		std::cout << iterStudents->second.toString() << std::endl;
	}
}

void StudentsEngine::listStudentsVec(const std::vector< Student >& vStudents)
{
	if (vStudents.size() == 0)
	{
		std::cout << "There are no students available!\n";
		return;
	}

	std::cout << "The students are:\n";
	std::vector< Student >::const_iterator iterStudents = vStudents.begin();
	for (; iterStudents != vStudents.end(); ++iterStudents)
	{
		std::cout << iterStudents->toString() << std::endl;
	}
}


bool StudentsEngine::checkStudentExists(const std::string& sFacultyNum, const std::map< std::string, Student >& mStudents)
{
	std::map< std::string, Student >::const_iterator iterMap = mStudents.find(sFacultyNum);
	if (iterMap != mStudents.end()) return true;
	else return false;
}


void StudentsEngine::printMenu()
{
	std::string sMenu("");
	sMenu = 
		"                           +----------------------------------------------------------->\n"
		"                           ||        [1] Add student                                  ||\n"
		"                           ||        [2] List students                                ||\n"
		"                           ||        [3] Sort by grades (descending)                  ||\n"
		"                           ||        [4] Sort by name (ascending)                     ||\n"
		"                           ||        [5] Get grades higher than certain value         ||\n"
		"                           ||        [0] Exit                                         ||\n"
		"                           |----------------------------------------------------------->\n"
		"                           +-----------------------------------------------------------+\n"
		"";

	std::cout << sMenu << std::endl;
}