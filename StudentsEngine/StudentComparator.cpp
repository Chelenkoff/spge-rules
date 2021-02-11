#include "StudentComparator.h"
StudentComparator::StudentComparator(CompareByOpt eCompare)
    : m_eComparisonOpt(eCompare)
{
    // constructor
}

bool StudentComparator::operator()(const Student& pFirstStudent, const Student& pSecondStudent) const
{
    switch (m_eComparisonOpt)
    {
        case COMPARE_BY_GRADE_ASC: return pFirstStudent.getGrade() < pSecondStudent.getGrade(); break;
        case COMPARE_BY_GRADE_DESC: return pFirstStudent.getGrade() > pSecondStudent.getGrade(); break;
        case COMPARE_BY_NAME_ASC: return pFirstStudent.getStudentName() < pSecondStudent.getStudentName(); break;
        case COMPARE_BY_NAME_DESC: return pFirstStudent.getStudentName() > pSecondStudent.getStudentName(); break;
        case COMPARE_BY_GRADES_ASC_NAME_ASC:
        {
            return (pFirstStudent.getGrade() < pSecondStudent.getGrade()
                || ( pFirstStudent.getGrade() == pSecondStudent.getGrade()
                     && pFirstStudent.getStudentName() < pSecondStudent.getStudentName()
                    )
                );
            break;
        }
        default: break;
    }

    return false;
}