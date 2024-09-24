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
    int prev = 0;
    int cur = 1;

    std::cout << 0 << ' ';

    for (int i = 0; i < n; ++i) {
        int tmp = prev;

        std::cout << cur << ' ';
        prev = cur;
        cur += tmp;
    }

    return 0;
}