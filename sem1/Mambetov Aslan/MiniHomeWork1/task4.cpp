#include <iostream>
#include<iomanip>
#include<cmath>


const long long inf = 9e18;
const double eps = 1e-6;
const double pi = acos(-1);



int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else 
    std::ios_base::sync_with_stdio(NULL); std::cin.tie(0);
    std::cout << std::fixed << std::setprecision(32);
#endif

    int n; std::cin >> n;
    int tmp = n;
    int l = 1, r = 10;
    int result = 0;

    while (tmp > 0) {
        tmp /= 10;
        l *= 10;
    }
    while (l > 1) {
        result += ((n % r) / (r / 10)) * l;
        l /= 10;
        r *= 10;
    }
    result /= 10;
    std::cout << result;
    return 0;
}