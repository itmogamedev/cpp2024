#include <iostream>
#include <fstream>
#include <string>
#include <vector>

class Person {
public:
    std::string id, firstName, lastName, patronName, points, flow;

    Person(std::string id, std::string firstName, std::string lastName, std::string patronName,
        std::string points, std::string flow) {
        this->id = id;
        this->firstName = firstName;
        this->lastName = lastName;
        this->patronName = patronName;
        this->points = points;
        this->flow = flow;
    }
};

std::vector<std::string> separation(std::string longString) {
    int first_letter = 0;
    std::vector<std::string> words;
    for (int i = 0; i < longString.size(); i++) {
        if (longString[i] == ' ') {
            words.push_back(longString.substr(first_letter, i));
            first_letter = i + 1;
        }
    }
    return words;
}

class dataBase {
public:
    std::vector<std::vector<std::string>> matrix;
    std::string line;
    std::vector<std::string> words;
    explicit dataBase(const int _strings) {
        matrix.resize(_strings, std::vector<std::string>(6));
        std::ifstream inputFile;
        inputFile.open("database.txt");
        if (inputFile.is_open()) {
            for (int i = 0; i < _strings; i++) {
                std::getline(inputFile, line);
                words = separation(line);
                for (int j = 0; j < 6; j++) {
                    matrix[i][j] = words[j];
                }
            }
        }
    }

    int idCheck() {
        bool columnCheck = true;
        int id = 1;

        while (true) {
            for (int i = 0; i < matrix.size(); i++) {
                if (matrix[i][0] == std::to_string(id)) {
                    id++;
                    columnCheck = false;
                    break;
                }
            }
            if (columnCheck) {
                break;
            }
            columnCheck = true;
        }
        return id;
    }

    void add() {
        std::vector<std::string> fullData(6);
        std::string names;
        fullData[0] = std::to_string(idCheck());
        std::vector<std::string>(*separate) (std::string) { separation };
        std::vector<std::string> words = separate(names);
        std::cout << "Введите ФИО студента. Разделите слова пробелами." << std::endl;
        getline(std::cin, names);


        if ((int)separate(names).size() == 3) {
            for (int i = 0; i < 3; i++) {
                fullData[i + 1] = words[i];
            }
        }
        std::cout << "Введите средний балл студента: " << std::endl;
        getline(std::cin, fullData[4]);
        std::cout << "Введите специальность студента: " << std::endl;
        getline(std::cin, fullData[5]);

        std::ofstream out;
        out.open("database.txt");
        if (out.is_open()) {
            for (int i = 0; i < fullData.size(); i++) {
                out << fullData[i] << std::endl;
            }
        }

    }
};


int main() {
    dataBase db(4);
}