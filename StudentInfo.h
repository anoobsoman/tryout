#ifndef __STUDENT_INFO
#define __STUDENT_INFO

#include <iostream>
#include <list>
#include <vector>
#include <string>

struct StudentInfo {
    std::string name;
    double midTerm, final;
    std::vector<double> homeWork;
    double grade;
};

std::istream& readHw(std::istream& in, std::vector<double>& hw);
std::istream& readStdInfo(std::istream& in, StudentInfo &record);

void randStdInfo(std::vector<StudentInfo> &stdInfo, unsigned int numStdInfo);
void randStdInfo(std::list<StudentInfo> &stdInfo, unsigned int numStdInfo);

bool compare(StudentInfo &a, StudentInfo &b);

double calcGrade(double midTerm, double final, double median);
double calcGrade(double midTerm, double final, std::vector<double> &hw);
std::list<StudentInfo> calcFGrade(std::list<StudentInfo> &stdInfo);
std::vector<StudentInfo> calcFGrade(std::vector<StudentInfo> &stdInfo);
double setGrade(StudentInfo &info, double grade);


#endif
