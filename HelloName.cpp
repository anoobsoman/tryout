#include <iostream>
int main()
{
    std::string name;

    std::cout << "Please enter your first name : ";
    std::cin >> name;

    std::cout << "Hello " << name << std::endl;
    return 0;
}