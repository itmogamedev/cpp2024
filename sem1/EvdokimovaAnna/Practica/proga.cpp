#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

using std::string;
using std::cout;
using std::cin;
using std::ostringstream;
using std::istringstream;
using std::getline;
using std::ifstream;
using std::ofstream;
using std::vector;
using std::endl;
using std::to_string;
using std::remove_if;

class Student
{
public:
    string studentid, fullname, studentmajor;
    double averagegrade;

    Student(const string& id, const string& fullname, double avegagegrade, string& studentmajor)
        : studentid(id), fullname(fullname), averagegrade(averagegrade), studentmajor(studentmajor) {}

    string studinfo() const
    {
        ostringstream info;
        info << studentid << "," << fullname << "," << averagegrade << "," << studentmajor;
        return info.str();
    }

    static Student studinfo(string& str)
    {
        istringstream Str(str);
        string studentid, fullname, studentmajor;
        double averagegrade;
        Str >> studentid;
        getline(Str, fullname, ',');
        Str >> averagegrade;
        Str.ignore();
        getline(Str, studentmajor);
        return Student(studentid, fullname, averagegrade, studentmajor);
    }
};

void savestudents(const vector<Student>& students, const string& filename)
{
    ofstream file(filename);
    for (const auto& student : students)
    {
        file << student.studinfo() << "\n";
    }
}

vector<Student> loadstudents(const string& filename)
{
    ifstream file(filename);
    vector<Student> students;
    string line;
    while (getline(file, line))
    {
        students.push_back(Student::studinfo(line));
    }
    return students;
}

void addstudent(vector<Student>& students)
{
    string studentid, fullname, studentmajor;
    double averagegrade;

    cout << "Enter the student's id: ";
    cin >> studentid;
    cout << "Enter the student's  full name:";
    cin.ignore();
    getline(cin, fullname);
    cout << "Enter the grade point averagegrade: ";
    cin >> averagegrade;
    cout << "Enter the student's speciality: ";
    cin.ignore();
    getline(cin, studentmajor);

    students.emplace_back(studentid, fullname, averagegrade, studentmajor);
}

void alltudents(const vector<Student>& students)
{
    for (const auto& student : students)
    {
        cout << student.studinfo() << "\n";
    }
}

void criteria(const vector<Student>& students)
{
    string criteriafield, criteriavalue;
    cout << "Eneter criteria:\n ";
    cout << "studentid\n";
    cout << "first name\n";
    cout << "last name\n";
    cout << "patronymic\n";
    cout << "averagegrade\n";
    cout << "studentmajor\n";
    cin >> criteriafield;
    cout << "Enter variant:";
    cin.ignore();
    getline(cin, criteriavalue);

    for (const auto& student : students)
    {
        bool found = false;
        if (criteriafield == "first name" && student.studentid == criteriavalue) found = true;
        else if (criteriafield == "first name" && student.fullname == criteriavalue) found = true;
        else if (criteriafield == "averagegrade" && to_string(student.averagegrade) == criteriavalue) found = true;
        else if (criteriafield == "studentmajor" && student.studentmajor == criteriavalue) found = true;

        if (found)
        {
            cout << student.studinfo() << "\n";
        }
    }
}

void deleteStudent(vector<Student>& students)
{
    string studentid;
    cout << "Enter id for deled:";
    cin >> studentid;

    students.erase(remove_if(students.begin(), students.end(),
        [&studentid](const Student& student) { return studentid == studentid; }),
        students.end());
}

int main()
{
    const string filename = "students.txt";
    vector<Student> students = loadstudents(filename);

    while (true)
    {
        cout << "1. Add a record\n2. All records\n3. Search by criteria\n4. Delete the record by id\n5. Exit\n";
        int choice;
        cout << "Select an action: ";
        cin >> choice;

        switch (choice) {
        case 1:
            addstudent(students);
            savestudents(students, filename);
            break;
        case 2:
            alltudents(students);
            break;
        case 3:
            criteria(students);
            break;
        case 4:
            deleteStudent(students);
            savestudents(students, filename);
            break;
        case 5:
            return 0;
        default:
            std::cout << "Error! try again\n";
            break;
        }
    }
}