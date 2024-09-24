#include <iostream>
#include<iomanip>
#include<cmath>


const long long inf = 9e18;
const double eps = 1e-6;
const double pi = acos(-1);



int calcTrapezoidAreaByHeightAndBases(int height, int firstBase, int secondBase) {
    return (firstBase + secondBase) / 2 * height;
}

int calcQuadrangleAreaByCoord(std::pair<double, double> point1,
                       std::pair<double, double> point2,
                       std::pair<double, double> point3,
                       std::pair<double, double> point4) {
    return abs(point1.first * point2.second + point2.first * point3.second + point3.first * point4.second + point4.first * point1.second -
               point1.second * point2.first - point2.second * point3.first - point3.second * point4.first - point4.second * point1.first) / 2;
}




int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else 
    std::ios_base::sync_with_stdio(NULL); std::cin.tie(0);
    std::cout << std::fixed << std::setprecision(32);
#endif

    int x1 = 0, y1 = 0, x2 = 1, y2 = 3, x3 = 4, y3 = 3, x4 = 7, y4 = 0;
    int height = 3, firstBase = 3, secondBase = 7;

    std::cout << calcQuadrangleAreaByCoord({ x1, y1 }, { x2, y2 }, { x3, y3 }, { x4, y4 }) << "\n";
    std::cout << calcTrapezoidAreaByHeightAndBases(height, firstBase, secondBase);

    return 0;
}