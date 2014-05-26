#include <iostream>
#include <cstdlib>
#include <vector>
#include <list>

#include "StudentInfo.h"
#include "median.h"

bool compare(StudentInfo &a, StudentInfo &b)
{
    return (a.name < b.name);
}

void randStdInfo(std::vector<StudentInfo> &stdInfo, unsigned int numStdInfo)
{
    StudentInfo record;
    for (int i=0; i<=numStdInfo; i++)
    {
        record.name = "A";
        record.midTerm = (rand() % 100);
        record.final = (rand() % 100);
        record.homeWork.push_back((rand() % 100));
        stdInfo.push_back(record);
    }
    return;
}

void randStdInfo(std::list<StudentInfo> &stdInfo, unsigned int numStdInfo)
{
    StudentInfo record;
    for (int i=0; i<=numStdInfo; i++)
    {
        record.name = "A";
        record.midTerm = rand() % 100;
        record.final = rand() % 100;
        record.homeWork.push_back(rand() % 100);
        stdInfo.push_back(record);
    }
 
    return;
}
std::istream& readStdInfo(std::istream &in, StudentInfo &record)
{
    if(in)
    {
        std::cout << "Please enter your first name: ";
        std::cin >> record.name;

        std::cout << "Hello, " << record.name << std::endl;

        std::cout << "Please enter your midterm and final grade: ";
        in >> record.midTerm >> record.final;

        std::cout << "Midterm and Final grade " << record.midTerm << " " << record.final << std::endl;

        readHw(in, record.homeWork);
    }
    return in;
}

std::istream& readHw(std::istream &in, std::vector<double> &hw)
{
    if (in)
    {
        hw.clear();

        double x;
        std::cout << "Please enter all your home work grades, finish by entering 0\n";
        while(in >> x && x !=0)
        {
            hw.push_back(x);
        }
        in.clear();
    }
    return in;
}

double setGrade(StudentInfo &info, double grade)
{
    info.grade = grade;
    return grade;
}

double calcGrade(double midTerm, double final, double median)
{
    return ((0.2 * midTerm) + (0.4 * final) + (0.4 * median));
}

double calcGrade(double midTerm, double final, std::vector<double> &hw)
{
    return calcGrade(midTerm, final, calcMedian(hw));
}

std::vector<StudentInfo> calcFGrade(std::vector<StudentInfo> &stdInfo)
{
    std::vector<StudentInfo>::iterator itr;
    std::vector<StudentInfo> fStudent;

    itr = stdInfo.begin();
    while(itr != stdInfo.end())
    {
        if(itr->grade < 35)
        {
            fStudent.push_back(*itr);
            itr = stdInfo.erase(itr);
            continue;
        }
        ++itr;
    }
    return fStudent;
}

std::list<StudentInfo> calcFGrade(std::list<StudentInfo> &stdInfo)
{
    std::list<StudentInfo>::iterator itr;
    std::list<StudentInfo> fStudent;

    itr = stdInfo.begin();
    while(itr != stdInfo.end())
    {
        if(itr->grade < 35)
        {
            fStudent.push_back(*itr);
            itr = stdInfo.erase(itr);
            continue;
        }
        ++itr;
    }
    return fStudent;
}
