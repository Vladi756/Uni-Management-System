#ifndef HEAD_H_INCLUDED
#define HEAD_H_INCLUDED


class Student{
private:
    std::string name;
    int age;
    int ID;
    std::string school;
    std::string field;
    float GPA;

public:
    Student () : name("Joe"), age(18), ID(3987372), school("Business"), field("Asset Management"), GPA(64.7)
        {}  // empty body of constructor

    Student(std::string s, int a, int ID, std::string sl, std::string f, float g) :
            name(s), age(a), ID(ID), school(sl), field(f), GPA(g)
        {}

    std::string getName(){return name;}

    void showStudent()const {
        std::cout << "Student Information: " << "\n";
        std::cout << "\tName:              " << name << std::endl;
        std::cout << "\tAge:               " << age << std::endl;
        std::cout << "\tStudent ID:        " << ID << std::endl;
        std::cout << "\tSchool:            " << school << std::endl;
        std::cout << "\tField of Study:    " << field<< std::endl;
        std::cout << "\tGPA:               " << GPA << "\n\n";                  // formatting code for better UI.
    }
};

std::vector<Student> allStudents;

class Class{
private:
    std::string Name;
    int count;
    std::string homeRoom;
    std::vector<std::string> members;

public:
    Class() : Name("N/A"), count(0), homeRoom("N/A") {}
    Class(std::string n, int c, std::string HR) : Name(n), count(c), homeRoom(HR) {}
    void addStudent(Student s){
        members.push_back(s.Student::getName());
        count++;
    }

    void setName(std::string name){Name = name;}
    void setHR(std::string HR){homeRoom = HR;}
    std::string getName(){return Name;}

    void displayClass() const {
        std::cout << "Class Information: " << std::endl;
        std::cout << "\tName:      " << Name << std::endl;
        std::cout << "\tHome Room: " << homeRoom << std::endl;
        std::cout << "\tMembers:" << std::endl;
        if(members.size() < 1) {
            std::cout << "\t\tNo one here yet!";
            std::cout << "\n";
        }
        for(int i = 0; i < members.size(); i++){
            std::cout << "\t" << members[i] << std::endl;
        }
        std::cout << "\n";
    }

};

std::vector<Class> allClasses;

// Case: 1
void createClass(){
    std::cout << "Please enter the name of the class: " << std::endl;
    std::string name;
    std::cin >> name;
    std::cout << "Please enter the Home Room of the class: " << std::endl;
    std::string HR;
    std::cin >> HR;

    Class new1(name, 0, HR);
    new1.displayClass();

    allClasses.push_back(new1);
}
// Case: 2
void viewClasses() {
    for(int i = 0; i < allClasses.size(); i++){
        allClasses[i].displayClass();

    }
}
// Case: 3
void newStudent(){
    std::cout << "Please enter the student's name: " << std::endl;
    std::string name;
    std::cin.ignore();  // to ignore leading whitespace
    std::getline(std::cin, name);
    std::cout << "How old is the student? " << std::endl;
    int age;
    std::cin >> age;
    std::cout << "What is the student's ID?" << std::endl;
    int sID;
    std::cin >> sID;
    std::cout << "What school does the student attend? " << std::endl;
    std::string school;
    std::cin.ignore();
    std::getline(std::cin, school);
    std::cout << "The student's field of study:" << std::endl;
    std::string fieldOfStudy;
    std::getline(std::cin, fieldOfStudy);
    std::cout << "What is the student's GPA?" << std::endl;
    int GPA;
    std::cin >> GPA;

    Student new1(name, age, sID, school, fieldOfStudy, GPA);
    allStudents.push_back(new1);
    new1.showStudent();
}

// Case 4
void viewStudents(){
    for(int i = 0; i < allStudents.size(); i++){
        allStudents[i].showStudent();
    }
}
// Case 5
void studentToClass(){
    std::cout << "Name of student to be added:" << std::endl;
    std::string name;
    std::cin.ignore();
    std::getline(std::cin, name);

    std::cout << "Name of class student to be added to: " << std::endl;
    std::string input;
    std::getline(std::cin, input);

    for(int i = 0; i < allClasses.size(); i++){
        if(allClasses[i].getName() == input){
            for(int j = 0; j < allStudents.size(); j++){
                if(allStudents[j].getName() == name){
                    allClasses[i].addStudent(allStudents[j]);
                    std::cout << "Updated Class Information:" << std::endl;
                    allClasses[i].displayClass();
                    break;
                }
            }
        }
    }
 }

#endif // HEAD_H_INCLUDED
