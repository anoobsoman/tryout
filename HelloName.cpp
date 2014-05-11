#include <iostream>
int main()
{
    std::string name;
    std::string greeting;

    std::cout << "Please enter your first name : ";
    std::cin >> name;

    greeting = "* Hello, " + name + "! *" ;

    std::string first(greeting.size(), '*');

    std::string second;
    second = "*" + std::string(greeting.size() - 2, ' ') + "*";

    std::cout << first << std::endl;
    std::cout << second << std::endl;
    std::cout << greeting << std::endl;
    std::cout << second << std::endl;
    std::cout << first << std::endl;
    return 0;
}
