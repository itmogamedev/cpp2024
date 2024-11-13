#include <algorithm>
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>




class Student
{
public:
    int ID;
    std::string fullName;
    std::string specialty;
    float avgScore;

    Student(int ID, std::string FullName, std::string specialty, float avgScore)
        : ID(ID), fullName(FullName), specialty(specialty), avgScore(avgScore){}


    std::string ToString() {
        std::ostringstream oss;
        oss << ID << "," << fullName << "," << specialty << "," << avgScore;
        return oss.str();
    }
    static Student fromString(std::string line) {
        std::istringstream iss(line);
        int ID;
        std::string fullName;
        float avgScore;
        std::string specialty;

        std::string bufer;

        std::getline(iss, bufer, ',');
        ID = std::stoi(bufer);
        std::getline(iss, fullName, ',');
        std::getline(iss, specialty, ',');
        std::getline(iss, bufer);
        avgScore = std::stof(bufer);
        return Student(ID, fullName, specialty, avgScore);

    }
};

class StudentBase {
public:
    std::vector<Student> students;
    std::string filePath = "C:\\Users\\Cauua\\untitled\\MyFile.txt";

    void loadFile()
    {
        std::string line;
        std::ifstream file(filePath);
        if (file.is_open()) {
            while(std::getline(file, line))
            {
                students.push_back(Student::fromString(line));
            }
        }
    }
    void rewriteFile() {
        std::ofstream file(filePath);
        if (file.is_open()) {
            for (Student student : students)
            {
                file << student.ToString() << std::endl;
            }
        }
    }

    StudentBase() {
        loadFile();
    }

    void addStudent(int ID, std::string fullName,std::string specialty, float avgScore) {
        students.emplace_back(ID, fullName, specialty, avgScore);
        rewriteFile();
    }

    void displayStudents() {
        for (Student student : students) {
            std::cout << student.ToString() << std::endl;
        }
    }


    void delStudent(int ID) {
        students.erase(std::remove_if(students.begin(), students.end(), [ID](Student student) {
            return student.ID == ID;
        }));
    }

    void searchStudent(std::string criterion, std::string value) {
        for (Student student : students) {
            if((criterion == "id" and std::stoi(value) == student.ID)
                or (criterion == "full_name" and value == student.fullName)
                or (criterion == "spec" and value == student.specialty)
                or (criterion == "avg_score" and std::stof(value) == student.avgScore)  ) {
                std::cout << student.ToString() << std::endl;
                }
        }
    }


};

int main() {
    bool in_Program = true;
    StudentBase studentBases;
    while(true) {
        std::cout
                << "1 - add Student\n"
                << "2 - delete Student\n"
                << "3 - display Students\n"
                << "4 - Find student\n"
                << "0 - Exit\n";

        std::cout << "Choose operetion: ";
        int choise;
        std::cin >> choise;

        int ID;
        std::string fullName;
        float avgScore;
        std::string specialty;
        std::string criterion;
        std::string value;

        switch (choise) {
            case 0:
                std::cout << "GoodBye!";
                exit(0);
                in_Program = false;
            break;
            case 1:
                std::cout << "Enter Student ID: ";
                std::cin >> ID;

                std::cout << "Enter Student Full Name(SecondName_FirstName_FatherName): ";
                std::cin >> fullName;

                std::cout << "Enter Student specialty: ";
                std::cin >> specialty;

                std::cout << "Enter Student Average score: ";
                std::cin >> avgScore;

                studentBases.addStudent(ID, fullName, specialty, avgScore);
            break;
            case 2:
                std::cout << "Enter Student ID: ";
                std::cin >> ID;
                studentBases.delStudent(ID);
            break;
            case 3:
                studentBases.displayStudents();
            break;
            case 4:
                std::cout << "(id, full_name, spec, avg_score) \n Enter search criterion: ";
                std::cin >> criterion;
                std::cout << "Enter search value: ";
                std::cin >> value;
                studentBases.searchStudent(criterion, value);
            break;
        }
    }

    return 0;
}







