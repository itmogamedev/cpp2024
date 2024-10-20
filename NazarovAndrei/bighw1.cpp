#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

class Student {
    public:
    int id;
    std::string name;
    double avgScore;
    std::string spec;

    Student(int s_id, std::string s_name, double s_avgScore, std::string s_spec) {
        id = s_id;
        name = s_name;
        avgScore = s_avgScore;
        spec = s_spec;
    }

    void printInfo() {
        std::cout << "ID: " << id << "\nName: " << name << "\nAverage score: " << avgScore << "\nSpecialization: " << spec << std::endl;
        std::cout << "-----------------" << std::endl;
    }

    std::string toString() {
        return std::to_string(id) + "|" + name + "|" + std::to_string(avgScore) + "|" + spec;
    }
};

Student parseStudent(std::string line) {
    std::stringstream ss(line);
    std::string substring;

    getline(ss, substring, '|');
    int id = stoi(substring);

    getline(ss, substring, '|');
    std::string name = substring;

    getline(ss, substring, '|');
    double gpa = stod(substring);

    getline(ss, substring, '|');
    std::string major = substring;

    return Student(id, name, gpa, major);
}

void readFromFile(std::vector<Student>& students) {
    std::ifstream file("students.txt");
    std::string line;

    if (!file.is_open()) {
        std::ofstream createFile("students.txt");
        if (createFile.is_open()) {
            createFile.close();
        }
    } else {
        std::string line;
        while (getline(file, line)) { 
            Student student = parseStudent(line);
            students.push_back(student);
        }
        file.close();
    }
}

void writeToFile(std::vector<Student> students) {
    std::ofstream file("students.txt");
    if (file.is_open()) {
        for (Student student : students) {
            file << student.toString() << std::endl;
        }
        file.close();
    } else {
        std::cout << "File opening failed" << std::endl;
    }
}

Student createStudent() {
    int id;
    std::string name;
    double avgScore;
    std::string spec;

    std::cout << "Enter student ID: " << std::endl;
    std::cin >> id;
    std::cin.ignore();

    std::cout << "Enter student's name: " << std::endl;
    std::getline(std::cin, name);

    std::cout << "Enter student average score: " << std::endl;
    std::cin >> avgScore;
    std::cin.ignore();

    std::cout << "Enter student specialization: " << std::endl;
    std::getline(std::cin, spec);

    return Student(id, name, avgScore, spec);
}

void findStudents(const std::vector<Student>& students, int criteriaNum) {
    if (criteriaNum < 1 || criteriaNum > 4) {
        std::cout << "Invalid number" << std::endl;
        return;
    }

    std::string criteria;
    std::cout << "Enter value: ";
    std::cin >> criteria;
    std::cout << std::endl;

    switch(criteriaNum) {
        case 1: {
            int id = stoi(criteria);
            for (Student student : students) {
                if (student.id == id) {
                    student.printInfo();
                }
            }
            break;
        }
        case 2: {
            for (Student student : students) {
                if (student.name == criteria) {
                    student.printInfo();
                }
            }
            break;
        }
        case 3: {
            double avgScore = stod(criteria);
            for (Student student : students) {
                if (student.avgScore == avgScore) {
                    student.printInfo();
                }
            }
            break;
        }
        case 4: {
            for (Student student : students) {
                if (student.spec == criteria) {
                    student.printInfo();
                }
            }
            break;
        }
        default:
            std::cout << "Invalid number" << std::endl;
            return;
    }
}

void removeStudentByID(std::vector<Student>& students, int removeID) {
    for (size_t i = 0; i < students.size(); ++i) {
        if (students[i].id == removeID) {
            students.erase(students.begin() + i);
            std::cout << "Student " << removeID << " has been removed" << std::endl;
            return;
        }
    }
    std::cout << "Student " << removeID << " doesn't exist" << std::endl;
}

int main() {
    std::vector<Student> students;
    int input;

    readFromFile(students);

    while (true) {
        std::cout << "1 - students list" << std::endl;
        std::cout << "2 - add new student" << std::endl;
        std::cout << "3 - find students by criteria" << std::endl;
        std::cout << "4 - remove student by ID" << std::endl;
        std::cout << "0 - exit" << std::endl;

        std::cout << " >>> ";
        std::cin >> input;
    
        switch(input) {
            case 0: {
                return 0;
            }
            case 1: {
                for(Student student : students) {
                    student.printInfo();
                }
                break;
            }
            case 2: {
                students.push_back(createStudent());
                writeToFile(students);
                break;
            }
            case 3: {
                std::cout << "Enter criteria number:" << std::endl;
                std::cout << "1 - ID" << std::endl;
                std::cout << "2 - Name" << std::endl;
                std::cout << "3 - Average Score" << std::endl;
                std::cout << "4 - Specialization" << std::endl;

                std::cout << " >>> ";
                std::cin >> input;
                findStudents(students, input);
                break;
            }
            case 4: {
                int removeID;
                std::cout << "Enter student ID: ";
                std::cin >> removeID;
                removeStudentByID(students, removeID);
                writeToFile(students);
                break;
            }
            default: {
                std::cout << "Wrong input" << std::endl;
                break;
            }
        }
    }
    return 0;
};