#pragma once
#include "Student.h"
class StudentComparator
{
	public:
        enum CompareByOpt
        {
            COMPARE_BY_UNKNOWN              ,
            COMPARE_BY_GRADE_ASC            ,
            COMPARE_BY_GRADE_DESC           ,
            COMPARE_BY_NAME_ASC             ,
            COMPARE_BY_NAME_DESC            ,
            COMPARE_BY_GRADES_ASC_NAME_ASC  
        };

        StudentComparator(CompareByOpt eCompare);
        bool operator()(const Student& pFirstStudent, const Student& pSecondStudent) const;

	private:
        CompareByOpt m_eComparisonOpt;

};

