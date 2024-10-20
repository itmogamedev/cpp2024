#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include<iostream>


class Student
{
private:

    std::string name;
    std::string surname;
    std::string patronic;
    std::string specialization;
    int id;
    std::string score;

public:
    Student()
    {

   }
    Student(int id, std::string name, std::string surname, std::string patronic, std::string score, std::string specialization)
    {
        this->id = id;
        this->name = name;
        this->surname = surname;
        this->patronic = patronic;
        this->score = score;
        this->specialization = specialization;


    }

  
    std::string show_name()
    {
        return name;
    }


    std::string show_surname()
    {
        return surname;
    }


    std::string show_patronic()
    {
        return name;
    }

    int show_ID()
    {
        return id;
    }
    std::string show_score()
    {
        return score;
    }

    std::string show_specialization()
    {
        return specialization;
    }

};



class Data_base
{
private:
    std::vector<Student>student;
public:
   
    void loadFromFile(const std::string& path)
    {
        std::ifstream file(path);
        if (!file.is_open())
        {
            std:: cerr<< "File wasn't found" << std::endl;
        }

        std::string line;
        while (std::getline(file, line))
        {
            std::stringstream ss(line);
            std::string stud_id, stud_name, stud_surname, stud_patronic, stud_score, stud_specialization;

            std::getline(ss, stud_id, ' ');
            std::getline(ss, stud_name, ' ');
            std::getline(ss, stud_surname, ' ');
            std::getline(ss, stud_patronic, ' ');
            std::getline(ss, stud_score, ' ');
            std::getline(ss, stud_specialization, ' ');

            try
            {
                int id = std::stoi(stud_id);
                float sscore = std::stof(stud_score);
                Add_new_student(Student(id, stud_name, stud_surname, stud_patronic, stud_score, stud_specialization));
            }
            catch (const std::exception& e)
            {
                std::cerr << "error parsing line" << line << " - " << e.what() << std::endl;
            }
        }
        file.close();
    }

    void Add_new_student(Student new_student)
    {
        student.push_back(new_student);
    }
    void New_student()
    {
        std::string name;
        std::string surname;
        std::string patronic;
        std::string specialization;
        int id;
        std::string score;

        std::cout << "enter student's name" << std::endl;
        std::cin >> name;
        std::cout << "enter student's surname" << std::endl;
        std::cin >> surname;
        std::cout << "enter student's patronic" << std::endl;
        std::cin >> patronic;
        std::cout << "enter student's ID" << std::endl;
        std::cin >> id;
        std::cout << "enter student's score" << std::endl;
        std::cin >> score;
        std::cout << "enter student's specialisation" << std::endl;
        std::cin >> specialization;
        bool correct_id = 1;
        for (int i = 0; i < student.size(); i++)
        {
            if (student[i].show_ID() == id)
            {
                std::cout << "incorrect ID" << std::endl;
                correct_id = 0;
                break;
            }
        }
        if (correct_id == 1)
        {
            Add_new_student(Student(id, name, surname, patronic, score, specialization));
            std::ofstream out;
            out.open("Base of students.txt", std::ios::app);
            if (out.is_open())
            {
                out << id << " " << name << " " << surname << " " << patronic << " " << score << " " << specialization << "\n";
            }
            out.close();

        }

    }

    void Show_list_of_students()
    {
        std::ifstream in("Base of students.txt", std::ios::app); // эта часть выводит записи из файла, ее надо применять только при соответствующей команде
        std::string line;
        while (std::getline(in, line)) std::cout << line << std::endl;

    }

    void Find_the_student()
    {
        //std::vector<Student> students_list;
        std::string k;
        std::string search;

        std::cout << "choose the number" << std::endl;
        std::cout << "press (1) to find by ID" << std::endl;
        std::cout << "press (2) to find by name" << std::endl;
        std::cout << "press (3) to find by surname" << std::endl;
        std::cout << "press (4) to find by patronic" << std::endl;
        std::cout << "press (5) to find by score" << std::endl;
        std::cout << "press (6) to find by specialization" << std::endl;
        std::cin >> k;


        if (k == "1" || k == "2" || k == "3" || k == "4" || k == "5" || k == "6")
        {
            switch (stoi(k))
            {
            case 1:
                std::cout << "enter ID" << std::endl;
                std::cin >> search;
                //int i = 0;
                //std::cout << student.size() << std::endl;

                for (int i = 0; i < student.size(); i++)
                {
                    //std::cout << "you are here" << std::endl;
                    if (std::to_string(student[i].show_ID()) == search)
                    {
                        std::cout << student[i].show_ID() << " " << student[i].show_name() << " " << student[i].show_surname()<< " "
                            << student[i].show_patronic() << " " << student[i].show_score() << " "<< student[i].show_specialization() << std::endl;

                    }

                }
                break;
            case 2:
                std::cout << "enter name" << std::endl;
                std::cin >> search;

                for (int i = 0; i < student.size(); i++)
                {
                    if (student[i].show_name() == search)
                    {
                        std::cout << student[i].show_ID() << " " << student[i].show_name() << " " << student[i].show_surname() << " "
                            << student[i].show_patronic() << " " << student[i].show_score() << " " << student[i].show_specialization() << std::endl;

                    }

                }
                break;
            case 3:
                std::cout << "enter surname" << std::endl;
                std::cin >> search;

                for (int i = 0; i < student.size(); i++)
                {
                    if (student[i].show_surname() == search)
                    {
                        std::cout << student[i].show_ID() << " " << student[i].show_name() << " " << student[i].show_surname() << " "
                            << student[i].show_patronic() << " " << student[i].show_score() << " " << student[i].show_specialization() << std::endl;

                    }

                }
                break;
            case 4:
                std::cout << "enter patronic" << std::endl;
                std::cin >> search;
               
                for (int i = 0; i < student.size(); i++)
                {
                    if (student[i].show_patronic() == search)
                    {
                        std::cout << student[i].show_ID() << " " << student[i].show_name() << " " << student[i].show_surname() << " "
                            << student[i].show_patronic() << " " << student[i].show_score() << " " << student[i].show_specialization() << std::endl;

                    }

                }
                break;
            case 5:
                std::cout << "enter score" << std::endl;
                std::cin >> search;

                for (int i = 0; i < student.size(); i++)
                {
                    if (student[i].show_score() == search)
                    {
                        std::cout << student[i].show_ID() << " " << student[i].show_name() << " " << student[i].show_surname() << " "
                            << student[i].show_patronic() << " " << student[i].show_score() << " " << student[i].show_specialization() << std::endl;

                    }

                }
                break;
            case 6:
                std::cout << "enter specialization" << std::endl;
                std::cin >> search;

                for (int i = 0; i < student.size(); i++)
                {
                    if (student[i].show_specialization() == search)
                    {
                        std::cout << student[i].show_ID() << " " << student[i].show_name() << " " << student[i].show_surname() << " "
                            << student[i].show_patronic() << " " << student[i].show_score() << " " << student[i].show_specialization() << std::endl;

                    }

                }
                break;
            default:
                std::cout << "There is no command for this simbol" << std::endl;
                break;
            }
        }
    }

    void Delete_student()
    {
        int tm_student;
        std::cout << "enter student ID" << std::endl;
        std::cin >> tm_student;
        if (tm_student != 0)
        {
            for (int i = 0; i < student.size(); i++)
            {
                if (student[i].show_ID() == tm_student)
                {
                    std::cout << "Delete the student?" << std::endl;
                    std::cout << student[i].show_ID() << " " << student[i].show_name() << " " << student[i].show_surname() << " " << student[i].show_patronic() << " " << student[i].show_score() << " " << " " << student[i].show_specialization() << std::endl;;
                    std::cout << "1 - Yes\n" << std::endl;
                    std::cout << "2 - No\n" << std::endl;
                    int del_input = 0;
                    std::cin >> del_input;
                    if (del_input == 1)
                    {
                        std::ofstream out;
                        out.open("Base of students.txt");
                        if (out.is_open()) {
                            for (int j = 0; j < student.size(); j++)
                            {
                                if (student[j].show_ID() != tm_student)
                                {
                                    out << student[j].show_ID() << " " << student[j].show_name() << " " << student[j].show_surname() << " " << student[j].show_patronic() << " " << student[j].show_score() << " " << " " << student[j].show_specialization() << std::endl;
                                }
                            }
                        }
                        out.close();
                        break;
                    }
                    else {
                        std::ofstream out;
                        out.open("Base of students.txt", std::ofstream::out);
                        if (out.is_open()) {
                            out << student[i].show_ID() << " " << student[i].show_name() << " " << student[i].show_surname() << " " << student[i].show_patronic() << " " << student[i].show_score() << " " << " " << student[i].show_specialization() << std::endl;;

                        }
                        out.close();
                    }
                }
                else {
                    std::ofstream out;
                    out.open("Base of students.txt", std::ofstream::out);
                    if (out.is_open()) {
                        out << student[i].show_ID() << " " << student[i].show_name() << " " << student[i].show_surname() << " " << student[i].show_patronic() << " " << student[i].show_score() << " " << " " << student[i].show_specialization() << std::endl;
                    }
                    out.close();
                }
            }
        }
        if (student.size() == 0) {
            std::ofstream out;
            out.open("Base of students.txt", std::ofstream::out);
            if (out.is_open()) {
                out << "";
            }
            out.close();
        }
    }
        
};



int main()
{
    std::string k;
    Data_base db;

    std::string name;
    std::string surname;
    std::string patronic;
    std::string specialization;
    std::string id;
    std::string score;

    db.loadFromFile("Base of students.txt");

    std::cout << "choose the number" << std::endl;
    std::cout << "press (1) to add new student" << std::endl;
    std::cout << "press (2) to see a list of students" << std::endl;
    std::cout << "press (3) to find a student" << std::endl;
    std::cout << "press (4) to delete a student" << std::endl;
    std::cout << "press any other symbol to exit" << std::endl;
    std::cin >> k;
   

    while (k == "1" || k == "2" || k == "3" || k == "4")
    {
        switch (stoi(k))
        {
        case 1:
            db.New_student();
            break;
        case 2:
            db.Show_list_of_students();
            break;
        case 3:
            db.Find_the_student();
            break;
        case 4:
            db.Delete_student();
            break;
        default:
            std::cout << "There is no command for this simbol" << std::endl;
            break;
        }

        std::cout << " " << std::endl;
        std::cout << "choose the number" << std::endl;
        std::cout << "press (1) to add new student" << std::endl;
        std::cout << "press (2) to see a list of students" << std::endl;
        std::cout << "press (3) to find a student" << std::endl;
        std::cout << "press (4) to delete a student" << std::endl;
        std::cout << "press any other simbol to exit" << std::endl;
        std::cin >> k;

    }

    std::cout << "programm is finished";


};

