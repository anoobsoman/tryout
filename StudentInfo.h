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
double calcGrade(double midTerm, double final, double median);
double calcGrade(double midTerm, double final, std::vector<double> &hw);
std::list<StudentInfo> calcFGrade(std::list<StudentInfo> &stdInfo);
double setGrade(StudentInfo &info, double grade);

std::istream& readHw(std::istream& in, std::vector<double>& hw);
std::istream& readStdInfo(std::istream& in, StudentInfo &record);

bool compare(StudentInfo &a, StudentInfo &b);

#endif
