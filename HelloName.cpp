#include <iostream>
#define PAD 4
#define MAX_ROW 5
int main()
{
    std::string name;

    std::cout << "Please enter your first name : ";
    std::cin >> name;
    std::string::size_type nameLen = name.size();
    std::string::size_type nameIndex = 0;

    std::cout << "Hello, " << name << "[" << nameLen << "]" << std::endl;

    for (int row = 0; row < MAX_ROW ; row++) {
        for (int col = 0; col < nameLen + PAD; col++) {
            /* First and the last line */
            if (row == 0 || row == (MAX_ROW-1)) {
                std::cout << "*";
            }
            /* Second and last but one line */
            if (row == 1 || row == 2|| row == (MAX_ROW-2)) {
                if (col == 0 || col == (nameLen + PAD - 1))
                    std::cout << "*";
                else if (row != 2)
                    std::cout << " ";
            }
            /* Finally the greeting */
            if (row == 2) {
                if (col != 0 && col != (nameLen + PAD - 1)) {
                    if (col == 1 || col == (nameLen + PAD - 2))
                        std::cout << " ";
                    else {
                        std::cout << name[nameIndex];
                        nameIndex++;
                    }
                }
            }
        }
        std::cout << std::endl;
    }
    return 0;
}
