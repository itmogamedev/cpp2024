#include <iostream>

void Nsystems(long long n, int system) {
    switch (system) {
    case 8:
        std::cout << std::oct << n << std::endl;
        break;
    case 16:
        std::cout << std::hex << n << std::endl;
        break;
    default:
        std::cout << "Unsupported input data" << std::endl;
        break;
    }
}


int main() {
    long long n;
    int system;
    std::cout << "Number and system(8 or 16)" << std::endl;
    std::cin >> n >> system;
    Nsystems(n, system);
}