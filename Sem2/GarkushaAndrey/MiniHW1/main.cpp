#include <iostream>
#include <vector>
#include "Math.h"

int main() {
    stats::Math math;

    std::vector<int> data = { 4, 1, 3, 2, 5 };

    std::cout << "Data: ";
    for (int x : data) {
        std::cout << x << " ";
    }
    std::cout << "\n\n";

    std::cout << "Mean: " << math.mean(data) << std::endl;
    std::cout << "Median: " << math.median(data) << std::endl;
    std::cout << "Root mean square: " << math.RMS(data) << std::endl;
    std::cout << "Variance: " << math.disp(data) << std::endl;


    std::cout << "\nReady! Press Enter to exit...";
    std::cin.get();
    return 0;
}