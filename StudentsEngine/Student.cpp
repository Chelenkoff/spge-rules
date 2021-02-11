#include "Student.h"
#include <sstream>

const std::string& Student::getFacultyNum() const
{
	return m_sFacutlyNum;
}

void Student::setFacultyNum(const std::string& sFacultyNum)
{
	m_sFacutlyNum = sFacultyNum;
}

const std::string& Student::getStudentName() const
{
	return m_sStudentName;
}

void Student::setStudentName(const std::string& sName)
{
	m_sStudentName = sName;
}

const std::string& Student::getCourseName() const
{
	return m_sCourseName;
}

void Student::setCourseName(const std::string& sName)
{
	m_sCourseName = sName;
}

float Student::getGrade() const
{
	return m_fGrade;
}

void Student::setGrade(float fGrade)
{
	m_fGrade = fGrade;
}

std::string Student::toString() const
{
	std::ostringstream ss;
	ss << getGrade();
	std::string sGrade(ss.str());

	std::string sTxt = getFacultyNum() + " " + getStudentName() + " " + getCourseName() + " " + sGrade;

	return sTxt;
}
