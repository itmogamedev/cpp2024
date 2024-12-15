#include <iostream>
#include <string>
using namespace std::string_literals;
std::string eight_sys(int numb) {
    std::string res;
    while (numb > 0) {
        res = std::to_string(numb % 8) + res;
        numb /= 8;
    }
    return res;
}

std::string sixteen_sys(int numb) {
    std::string res;
    std::string letters = "ABCDEF";
    while (numb > 0) {
        if (numb % 16 > 9) {
            res = letters[numb % 16 - 10] + res;
        }
        else {
            res = std::to_string(numb % 16) + res;
        }
        numb /= 16;
    }
    return res;
}

std::string system(int sys, int numb) { return sys == 16 ? sixteen_sys(numb) : eight_sys(numb); }

int main() {
    int first_input, second_input;
    while (true) {
        std::cout << "„B „{„p„{„…„ „ƒ„y„ƒ„„„u„}„… „ƒ„‰„y„ƒ„|„u„~„y„‘ „r„ „‡„€„„„y„„„u „„u„‚„u„r„u„ƒ„„„y „‰„y„ƒ„|„€? \n"
            "„B„r„u„t„y„„„u 8 „u„ƒ„|„y „r „r„€„ƒ„„}„u„‚„y„‰„~„…„ „y 16 „u„ƒ„|„y „r „Š„u„ƒ„„„~„p„t„ˆ„p„„„y„‚„y„‰„~„…„: ";
        std::cin >> first_input;
        if (first_input == 8 || first_input == 16) {
            std::cout << "„S„u„„u„‚„ „{„p„{„€„u „y„}„u„~„~„€ „‰„y„ƒ„|„€ „„u„‚„u„r„u„ƒ„„„y?: ";
            std::cin >> second_input;
            std::cout << "„B„p„Š„u „„u„‚„u„r„u„t„u„~„~„€„u „‰„y„ƒ„|„€: " << system(first_input, second_input) << std::endl;
        }
        else {
            std::cout << "„S„p„{„€„z „ƒ„y„ƒ„„„u„}„ „ƒ„‰„y„ƒ„|„u„~„y„‘ „r „q„p„x„u „t„p„~„~„„‡ „~„u„„." << std::endl;
        }
    }
}