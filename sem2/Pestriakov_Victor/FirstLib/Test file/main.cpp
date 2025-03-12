#include <iostream>
#include <vector>
#include "..\First_Lib\FirstLib.h"

int main() {
    setlocale(LC_ALL, "Russian");
    int size = 0;
    std::cout << "Ñêîëüêî ýëåìåíòîâ â âàøåì ìàññèâå (ââåäèòå òîëüêî ÷èñëî)? " << std::endl;
    std::cin >> size;

    std::vector<double> numbers; 

    std::cout << "Ââåäèòå âàøè ýëåìåíòû:" << std::endl;
    for (int i = 0; i < size; i++) {
        double point;
        std::cout << "×èñëî íîìåð " << i + 1 << ": ";
        std::cin >> point;
        numbers.push_back(point);
    }

    std::cout << "ÌÅÄÈÀÍÀ: " << Median(numbers) << std::endl;
    std::cout << "ÑÐÅÄÍÅÅ ÀÐÈÔÌÅÒÈ×ÅÑÊÎÅ: " << Mean(numbers) << std::endl;
    std::cout << "ÑÐÅÄÍÅÅ ÊÂÀÄÐÀÒÈ×ÅÑÊÎÅ: " << RMS(numbers) << std::endl;
    std::cout << "ÄÈÑÏÅÐÑÈß: " << Variance(numbers) << std::endl;

    return 0;
}
