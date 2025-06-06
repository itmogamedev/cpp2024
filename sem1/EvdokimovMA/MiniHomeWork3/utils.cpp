//
// Created by Maksim Evdokimov on 01.11.2024.
//

#pragma once

#include <cstdint>
#include <iostream>

static constexpr unsigned int hash_string(const char* data, size_t const size) noexcept {
    unsigned int hash = 5381;

    for(const char *c = data; c < data + size; ++c)
        hash = ((hash << 5) + hash) + (unsigned char) *c;

    return hash;
}

static void clear_screen() {
#if defined _WIN32
    system("cls");
#elif defined (__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
    system("clear");
#elif defined (__APPLE__)
    system("clear");
#endif
}

static void wait_for_enter() {
    std::cout << "Press Enter to continue...";
    std::cin.ignore();
    std::cin.get();
}