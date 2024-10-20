#include <iostream>
#include <vector>
#include <cstdio>
#include <string>
#include <iomanip>
#include <map>
#include <set>
#include <iostream>
#include <fstream>

bool is_running = true;

std::vector<std::string> split(std::string str_in) {
    std::vector<std::string> tokens;
    size_t pos = 0;
    std::string token;
    while ((pos = str_in.find(" ")) != std::string::npos) {
        token = str_in.substr(0, pos);
        tokens.push_back(token);
        str_in.erase(0, pos + 1);
    }
    tokens.push_back(str_in);

    return tokens;
}

int inp_correct_int() {
    std::string input;
    int int_inp;

    while (true) {
        std::cin >> input;

        try {
            int_inp = std::stoi(input);
            return int_inp;
        }
        catch (const std::invalid_argument& e) {
            std::cout << "\nplease enter correct number\n\n";
        }
        catch (const std::out_of_range& e) {
            std::cout << "\nplease enter correct number\n\n";
        }
    }
    return int_inp;
}

float inp_correct_float() {
    std::string input;
    float int_inp;

    while (true) {
        std::cin >> input;

        try {
            int_inp = std::stof(input);
            return int_inp;
        }
        catch (const std::invalid_argument& e) {
            std::cout << "\nplease enter correct number\n\n";
        }
        catch (const std::out_of_range& e) {
            std::cout << "\nplease enter correct number\n\n";
        }
    }
    return int_inp;
}

class Student {
private:
    int id;
    std::string name;
    std::string surname;
    std::string faculty;
    float grade;

public:
    Student() {

    }
    Student(int id_in, std::string name_in, std::string surname_in, std::string faculty_in, float grade_in) {
        id = id_in;
        name = name_in;
        surname = surname_in;
        faculty = faculty_in;
        grade = grade_in;
    }
    Student(std::vector<std::string> vector_data) {
        id = stoi(vector_data[0]);
        name = vector_data[1];
        surname = vector_data[2];
        faculty = vector_data[3];
        grade = stof(vector_data[4]);
    }

    int get_id() {
        return id;
    }

    std::string get_info(int info_index) {

        switch (info_index)
        {
        case 1:
            return name;
            break;

        case 2:
            return surname;
            break;

        case 3:
            return faculty;
            break;

        default:
            return ":/";
        }
    }

    void display() {
        std::cout << "\nname: " << name << ' ' << surname << std::endl;
        std::cout << "id: " << id << std::endl;
        std::cout << "faculty: " << faculty << std::endl;
        std::cout << std::setprecision(3) << "grade: " << grade << std::endl;
    }

    void wright_yourself_to_file(std::ofstream& file) {
        file << id << " " << name << " " << surname << " " << faculty << " " << grade << std::endl;
    }
};

class Students_data {
private:

    std::map<int, Student> all_students;
    std::set<int> students_indexes;

public:
    Students_data() {

    }

    Students_data(std::map<int, Student> in_all_students) {
        all_students = in_all_students;
    }
 
    void set_all_students(std::map<int, Student> in_all_students) {
        all_students = in_all_students;
    }

    void show_everyone() {

        for (int i : students_indexes) {
            all_students[i].display();
        }
    }

    void add_student() {
        int id;
        std::string name;
        std::string surname;
        std::string faculty;
        float grade;

        do {
            std::cout << "\nplease, enter non-existing id:\n";
            id = inp_correct_int();

        } while (students_indexes.find(id) != students_indexes.end());

        std::cout << "\nplease, enter name:\n";
        std::cin >> name;

        std::cout << "\nplease, enter surname:\n";
        std::cin >> surname;

        std::cout << "\nplease, enter faculty:\n";
        std::cin >> faculty;

        std::cout << "\nplease, enter grade:\n";
        grade = inp_correct_float();

        all_students[id] = Student(id, name, surname, faculty, grade);
        students_indexes.insert(id);
    }

    int inp_existing_id() {
        int id;

        do {
            std::cout << "\nplease, enter existing id of a student\n";
            id = inp_correct_int();

        } while (students_indexes.find(id) == students_indexes.end());

        return id;
    }

    void delite_student() {
        int delete_id = inp_existing_id();

        all_students.erase(delete_id);
        students_indexes.erase(delete_id);
    }

    void find_student() {
        std::cout << "\n0 -- search by id\n1 -- search by first name\n2 -- search by second name\n3 -- search by faculty\n";
        int search_by = inp_correct_int();
        
        if (search_by == 0) {

            int search_id;
            std::cout << "\nnow please enter your search: ";
            search_id = inp_existing_id();

            std::cout << "\nyour search results:\n";
            all_students[search_id].display();

            return;
        }

        std::string search;
        std::cout << "\nnow please enter your search: ";
        std::cin >> search;

        std::set<int> found_students_indexes;
        for (int i : students_indexes) {
            if (all_students[i].get_info(search_by) == search) {
                all_students[i].display();
            }
        }
    }

    void wright_to_file(std::ofstream& file) {

        for (int i : students_indexes) {
            all_students[i].wright_yourself_to_file(file);
        }
    }

    void read_from_file(std::ifstream& file) {

        all_students.clear();
        students_indexes.clear();

        std::string line;
        while (std::getline(file, line)) {

            Student new_student(split(line));
            int new_id = new_student.get_id();

            all_students[new_id] = new_student;
            students_indexes.insert(new_id);
        }
    }
};


class Menu {
public:

    Menu() {

    }

    void do_menu(Students_data& students_data) {
        std::cout << "\n1 -- show everyone\n2 -- add student\n3 -- delite student\n4 -- search\n5 -- exit\n";

        procces_input(students_data);
    }

    void procces_input(Students_data& students_data) {
        int input;

        input = inp_correct_int();

        switch (input)
        {
        case 1:
            students_data.show_everyone();
            break;

        case 2:
            students_data.add_student();
            break;

        case 3:
            students_data.delite_student();
            break;

        case 4:
            students_data.find_student();
            break;
        
        case 5:
            is_running = false;
            break;

        default:
            std::cout << "\nplease enter correct number for a command\n";
        }
    }
};


int main()
{
    Menu menu;
    Students_data students_data = Students_data();

    std::ifstream out_file;
    std::ofstream in_file;

    while (is_running) {

        out_file.open("students_database_file.txt");
        students_data.read_from_file(out_file);
        out_file.close();

        menu.do_menu(students_data);

        in_file.open("students_database_file.txt", std::ofstream::out | std::ofstream::trunc);
        students_data.wright_to_file(in_file);
        in_file.close();
    }

    return 0;
}