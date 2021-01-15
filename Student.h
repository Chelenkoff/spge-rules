#pragma once

#include<string>
class Student
{
	public:

		const std::string& getFacultyNum() const;
		void setFacultyNum(const std::string& sFacultyNum);

		const std::string& getStudentName() const;
		void setStudentName(const std::string& sName);

		const std::string& getCourseName() const;
		void setCourseName(const std::string& sName);

		float getGrade() const;
		void setGrade(float fGrade);

		std::string toString() const;

	private:
		std::string m_sFacutlyNum;
		std::string m_sStudentName;
		std::string m_sCourseName;
		float m_fGrade;
};

