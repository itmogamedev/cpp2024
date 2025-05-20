#include <windows.h>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <thread>

void shutdownPC() {
    system("shutdown /s /t 0");
}

void Button() {
    std::srand(std::time(nullptr));
    int delay = 1 + std::rand() % 60; 
    std::cout << "Button active";
    std::this_thread::sleep_for(std::chrono::seconds(delay));
    shutdownPC();
}

int main() {
    std::cout << "press ENTER to activate the shutdown button...";
    std::cin.ignore();
    Button();
    return 0;
}
