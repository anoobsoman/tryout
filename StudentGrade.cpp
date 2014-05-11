#include <iostream>
#include <vector>

int main()
{
    std::string name;
    double midTerm = 0.0, final = 0.0;
    double x = 0.0, median = 0.0;
    std::vector <double> homeWork;
    std::vector <double>::size_type homeWorkSize = 0;

    std::cout << "Please enter your first name: ";
    std::cin >> name;

    std::cout << "Hello, " << name << std::endl;

    std::cout << "Please enter your midterm and final grade: ";
    std::cin >> midTerm >> final;

    std::cout << "Midterm and Final grade " << midTerm << " " << final << std::endl;

    std::cout << "Please enter all your home work grades, finish by entering <eof>\n";


    while (std::cin >> x) {
        homeWork.push_back(x);
    }

    homeWorkSize = homeWork.size();

    if(homeWorkSize)
    {
        sort (homeWork.begin(), homeWork.end());
        median = ((homeWorkSize % 2) == 0) ? (homeWork[homeWorkSize/2] + homeWork[(homeWorkSize/2)-1])/2 : homeWork[homeWorkSize/2];
    }

    std::cout << "Median " << median << std::endl;
    std::cout << "Your final grade is " << (0.2 * midTerm) + (0.4 * final) + (0.4 * median) << std::endl;
    return 0;
}
