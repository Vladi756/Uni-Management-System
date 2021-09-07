#include <iostream>
#include <vector>
#include <string>
#include "head.h"


int main(){
// Interface
int option;
    std::cout << "Welcome to the University Management System!" << "\n\n";
    std::cout << "What would you like to do today?" << std::endl;
    do {
        std::cout << "===========================================" << std::endl;
        std::cout << "\t[1] Create a new Class" << std::endl;
        std::cout << "\t[2] View all Classes" << std::endl;
        std::cout << "\t[3] Create a new Student Profile" << std::endl;
        std::cout << "\t[4] View all Student Profiles" << std::endl;
        std::cout << "\t[5] Add Student to Class" << std::endl;

        std::cout << "\t[0] Exit Application" << std::endl;
        std::cout << "===========================================" << std::endl;
        std::cin >> option;

        switch(option){
        case 1:
            createClass();
            break;
        case 2:
            viewClasses();
            break;
        case 3:
            newStudent();
            break;
        case 4:
            viewStudents();
            break;
        case 5:
            studentToClass();
            break;
        }

    } while(option != 0);
    return 0;
}
