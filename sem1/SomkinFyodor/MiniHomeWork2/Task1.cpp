#include <string>
#include <iostream>

int Vosem(int chislo) {
    int perevod = 0, razryd = 1;
    while (chislo != 0) { //цикл перевода из 10 в 8
        perevod += (chislo % 8) * razryd;
        chislo /= 8;
        razryd *= 10;
    }
    return perevod;
}

std::string Bykva(int chislo) {
    if (chislo == 1) {
        return "1";
    }
    else if (chislo == 2) {
        return "2";
    }
    else if (chislo == 3) {
        return "3";
    }
    else if (chislo == 4) {
        return "4";
    }
    else if (chislo == 5) {
        return "5";
    }
    else if (chislo == 6) {
        return "6";
    }
    else if (chislo == 7) {
        return "7";
    }
    else if (chislo == 8) {
        return "8";
    }
    else if (chislo == 9) {
        return "9";
    }
    else if (chislo == 10) {
        return "A";
    }
    else if (chislo == 11) {
        return "B";
    }
    else if (chislo == 12) {
        return "C";
    }
    else if (chislo == 13) {
        return "D";
    }
    else if (chislo == 14) {
        return "E";
    }
    else {
        return "F";
    }
}

std::string Shestnadcat(int chislo) {
    int  razryd = 1, kolichestvo = 0, razmer = chislo;
    while (razmer > 0) { //узнаём размер числа
        razmer /= 16;
        kolichestvo++;
    }
    std::string shest[100];
    while (chislo != 0) { //цикл перевода из 10 в 16
        shest[kolichestvo - razryd] = Bykva(chislo % 16);
        chislo /= 16;
        razryd++;
    }
    std::string perevod;
    for (int i = 0; i < kolichestvo; i++) {
        perevod += shest[i];
    }
    return perevod;
}

int main()
{
    int eight, sixteen;
    std::cin >> eight;//для восьмеричной 
    std::cin >> sixteen;//для шестнадцатеричной
    std::cout << Vosem(eight) << "\n";
    std::cout << Shestnadcat(sixteen) << "\n";
}



