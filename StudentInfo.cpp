#include <iostream>
#include <vector>

#include "StudentInfo.h"
#include "median.h"

bool compare(StudentInfo &a, StudentInfo &b)
{
    return (a.name < b.name);
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

double calcGrade(double midTerm, double final, double median)
{
    return ((0.2 * midTerm) + (0.4 * final) + (0.4 * median));
}

double calcGrade(double midTerm, double final, std::vector<double> &hw)
{
    return calcGrade(midTerm, final, calcMedian(hw));
}
