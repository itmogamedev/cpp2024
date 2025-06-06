#include <iostream>

int siracus(int numb) {
    if (numb == 1) return 1;
    if (numb % 2) {
        return siracus((numb * 3 + 1) / 2);
    }
    else return siracus(numb / 2);
}
int main() {
    setlocate(LS_ALL, "Russian");
    int simple_numb;
    while (true) {
        std::cout << "„B„r„u„t„y„„„u „‰„y„ƒ„|„€ „t„|„‘ „„‚„€„r„u„‚„{„y „s„y„„€„„„u„x„ „R„y„‚„p„{„…„x: ";
        std::cin >> simple_numb;
        std::cout << "„O„„„r„u„„: " << siracus(simple_numb) << std::endl;
    }

}