#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>

class Student {
private:
    std::string  ID, special, FIO;
    double average;
public:
    class Student() {

    }
    class Student(std::string ID_, std::string FIO_, double average_, std::string special_) {
        ID = ID_;
        FIO = FIO_;
        average = average_;
        special = special_;
    }
    void SetAll(std::string ID_, std::string FIO_, double average_, std::string special_) {
        ID = ID_;
        FIO = FIO_;
        average = average_;
        special = special_;
    }
    void Book() {
        std::ofstream out;
        out.open("Student.txt", std::ios::app);
        if (out.is_open()) {
            out << ID << " " << FIO << " " << average << " " << special << "\n";
        }
        out.close();

    }
    ~Student() {
        //std::cout << "Student" << FIO << " was deleted" << "\n";
    }
};

void Info() {
    std::cout << "Choose variant" << "\n";
    std::cout << "1) Add Student" << "\n";
    std::cout << "2) Read all" << "\n";
    std::cout << "3) Found Student" << "\n";
    std::cout << "4) Delete Student" << "\n";
    std::cout << "5) Leave" << "\n";
}

void Read() {
    std::string line;
    std::ifstream in("Student.txt");
    if (in.is_open()) {
        while (std::getline(in, line)) {
            std::cout << line << "\n";
        }
    }
    in.close();

}

void Readln(bool variant) {
    std::string Del_student;
    if (variant == 1) {
        std::cin >> Del_student;

    }
    std::string  ID, special, FIO;
    std::string average;
    int kolichestvo = 0;
    std::vector<std::vector<std::string>> sortirovka;
    std::ifstream in("Student.txt");
    if (in.is_open()) {
        while (in >> ID >> FIO >> average >> special) {
            kolichestvo++;

            std::vector<std::string> masiv;
            masiv.push_back(ID);
            masiv.push_back(FIO);
            masiv.push_back(average);
            masiv.push_back(special);
            sortirovka.push_back(masiv);
        }

    }
    std::ofstream ofs;
    ofs.open("Student.txt", std::ofstream::out | std::ofstream::trunc);
    ofs.close();
    in.close();
    sort(sortirovka.begin(), sortirovka.end());
    for (int i = 0; i < kolichestvo; i++) {
        if (sortirovka[i][0] != Del_student){
            std::string ID_ = sortirovka[i][0], FIO_ = sortirovka[i][1], special_ = sortirovka[i][3];
            double average_ = stod(sortirovka[i][2]);
            Student student(ID_, FIO_, average_, special_);
            student.Book();
        }
    }
}


void ReadFound() {
    std::cout << "1) ID" << "\n";
    std::cout << "2) FIO" << "\n";
    std::cout << "3) average" << "\n";
    std::cout << "4) special" << "\n";
    std::string  ID, special, FIO;
    double average;
    int  choose;
    bool ans = false;
    bool answer = false;
    std::cin >> choose;
    while (answer == 0) {
        if (choose == 1) {
            std::cout << "Enter ID" << "\n";
            std::string ID_;
            std::cin >> ID_;
            std::ifstream in("Student.txt");
            if (in.is_open()) {
                while (in >> ID >> FIO >> average >> special) {
                    if (ID == ID_) {
                        std::cout << ID << " " << FIO << " " << average << " " << special << "\n";
                        ans = 1;
                    }
                }
                if (ans == 0) {
                    std::cout << "Student don't found" << "\n";
                }
            }
            in.close();

            answer = 1;
        }
        else if (choose == 2) {
            std::cout << "Enter FIO" << "\n";
            std::string FIO_;
            std::cin >> FIO_;
            std::ifstream in("Student.txt");
            if (in.is_open()) {
                while (in >> ID >> FIO >> average >> special) {
                    if (FIO == FIO_) {
                        std::cout << ID << " " << FIO << " " << average << " " << special << "\n";
                    }
                }
                if (ans == 0) {
                    std::cout << "Student don't found" << "\n";
                }
            }
            in.close();
            answer = 1;
        }
        else if (choose == 3) {
            std::cout << "Enter average" << "\n";
            double average_;
            std::cin >> average_;
            std::ifstream in("Student.txt");
            if (in.is_open()) {
                while (in >> ID >> FIO >> average >> special) {
                    if (average == average_) {
                        std::cout << ID << " " << FIO << " " << average << " " << special << "\n";
                        ans = 1;
                    }
                }
                if (ans == 0) {
                    std::cout << "Student don't found" << "\n";
                }
            }
            in.close();
            answer = 1;
        }
        else if (choose == 4) {
            std::cout << "Enter special" << "\n";
            std::string special_;
            std::cin >> special_;
            std::ifstream in("Student.txt");
            if (in.is_open()) {
                while (in >> ID >> FIO >> average >> special) {
                    if (special == special_) {
                        std::cout << ID << " " << FIO << " " << average << " " << special << "\n";
                        ans = 1;
                    }
                }
                if (ans == 0) {
                    std::cout << "Student don't found" << "\n";
                }
            }
            in.close();

            answer = 1;
        }
        else {
            std::cout << "choose corectely variant" << "\n";
        }
    }

}

int main()
{
    int answer_ = 6;
    std::string  ID, special, FIO;
    double average;
    while (answer_ != 5) {
        Info();
        std::cin >> answer_;
        if (answer_ == 1) {
            std::cout << "Enter a base" << "\n";
            std::cout << "ID" << " " << "FIO" << " " << "average" << " " << "special" << "\n";
            std::cin >> ID >> FIO >> average >> special;
            Student noviy(ID, FIO, average, special);
            noviy.Book();
            Readln(false);

        }
        else if (answer_ == 2) {
            Read();
        }
        else if (answer_ == 3) {
            ReadFound();
        }
        else if (answer_ == 4) {
            Readln(true);
        }
        else if (answer_ == 5) {
            break;
        }
        else if (answer_ == 99) {
            std::ofstream ofs;
            ofs.open("Student.txt", std::ofstream::out | std::ofstream::trunc);
            ofs.close();
        }
        else {
            std::cout << "Choose correctely number" << "\n";
        }
    }
}