//Если надо считать всю строку целиком или все строки из файла,
//то лучше использовать ф - ю getline(), она принимает
//поток для чтения и переменную, в которую надо считать текст 

#include <iostream>
#include <fstream>
#include <vector>
#include <string>     // для std::getline
#include "conio.h"

class Cred {
public:
    int id;
    std::string password;
};

int main() {
    std::string line;
    std::fstream stream("example.txt", std::ios_base::in);
    std::vector<Cred> creds;

    while (!stream.eof()) {
        Cred cred;
        stream >> cred.id >> cred.password;
        creds.push_back(cred);
    }

    stream.close();     // закрываем файл

    /////////////////////////////////////////////////////////////////////////////////////

    for (Cred cred : creds) {
        std::cout << cred.id << " " << cred.password << std::endl;
    }

    _getch();
}