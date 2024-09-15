// Для записи в файл к объекту ofstream или fstream
// применяется оператор << (как и при выводе на консоль) :

#include <iostream>
#include <fstream>
#include <vector>
#include "conio.h"
#include "math.h"

class Cred{
public:
    int id;
    std::string password;
};

int main() {
    srand(time(NULL));

    std::vector<Cred> creds;
    const int amountString = 1000;
    const int stringLength = 10;

    for (int i = 0; i < amountString; i++) {
        Cred tmpCred;
        tmpCred.id = i;
        for (int i = 0; i < stringLength; i++) {
            tmpCred.password += (char) (rand() % 128 + 36);
        }
        creds.push_back(tmpCred);
    }

    std::ofstream out;          // поток для записи
    out.open("example.txt");    // открываем файл для записи

    if (out.is_open()) {
        for (Cred cred : creds) {
            out << "id: " << cred.id << "; password: " << cred.password << std::endl;
        }
        std::cout << "File has been written" << std::endl;
    }
    else {
        std::cout << "ERROR!!!!!" << std::endl;
    }

    out.close();
    _getch();
}