#include <iostream>
#include <vector>

#include "median.h"
#include "StudentInfo.h"

int main()
{
    std::vector <StudentInfo> stdInfo;
    StudentInfo record;
    std::vector<StudentInfo>::iterator i;

    while(readStdInfo(std::cin, record))
    {
        stdInfo.push_back(record);
    }

    sort(stdInfo.begin(), stdInfo.end(), compare);

    for(i = stdInfo.begin(); i != stdInfo.end(); i++)
    {
        std::cout << "Hello, " << i->name << \
            " Your final grade is " << calcGrade(i->midTerm, i->final, i->homeWork) << std::endl;
    }
    return 0;
}


