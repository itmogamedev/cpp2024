#include <iostream>
#include <cstdlib>
#include <ctime>
#include <thread>
#include <chrono>
#include <windows.h>

void shutdown() {
    system("shutdown /s /t 0");
}

int main() {
    std::cout << "Нажмите R, чтобы отключить ПК через случайную задержку (от 10 до 60 секунд)..." << std::endl;

    srand(static_cast<unsigned int>(time(nullptr)));

    while (true) {
        if (GetAsyncKeyState('R') & 0x8000) {
            break;
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }

    int delay = rand() % 51 + 10;
    std::cout << "Компьютер будет отключен через " << delay << " секунд." << std::endl;

    std::this_thread::sleep_for(std::chrono::seconds(delay));

    shutdown();

    return 0;
}