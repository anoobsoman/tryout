#include <iostream>
#include <list>

#include "median.h"
#include "StudentInfo.h"

int main()
{
    std::list <StudentInfo> stdInfo;
    StudentInfo record;
    std::list<StudentInfo>::iterator i;
    std::list<StudentInfo> fStudents;

    while(readStdInfo(std::cin, record))
    {
        stdInfo.push_back(record);
    }

    stdInfo.sort(compare);

    for(i = stdInfo.begin(); i != stdInfo.end(); i++)
    {
        std::cout << "Hello, " << i->name << \
            " Your final grade is " << setGrade(*i, calcGrade(i->midTerm, i->final, i->homeWork)) << std::endl;
    }

    fStudents = calcFGrade(stdInfo); 

    if(fStudents.size() != 0)
    {
        i = fStudents.begin();
        while (i != fStudents.end())
        {
            std::cout << i->name << ", FAILED with grade of " << i->grade << std::endl;
            ++i;
        }
    }
    else
        std::cout << "No Student failed " << std::endl;

    if(stdInfo.size() != 0)
    {
        i = stdInfo.begin();
        while (i != stdInfo.end())
        {
            std::cout << i->name << ", PASSED with grade of " << i->grade << std::endl;
            ++i;
        }
 
    }
    return 0;
}


