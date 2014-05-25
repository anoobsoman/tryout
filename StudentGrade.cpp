#include <iostream>
#include <vector>

#include "median.h"
#include "StudentInfo.h"

int main()
{
    std::vector <StudentInfo> stdInfo;
    StudentInfo record;
    std::vector<StudentInfo>::iterator i;
    std::vector<StudentInfo> fStudents;

    while(readStdInfo(std::cin, record))
    {
        stdInfo.push_back(record);
    }

    sort(stdInfo.begin(), stdInfo.end(), compare);

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
    return 0;
}


