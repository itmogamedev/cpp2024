#include <iostream>
#include <MathLibrary.h>
#include <vector>

int main()
{
    std::vector<int> numbers = { 1, 2, 3, 4, 5 };

    try
    {
        std::cout << "Mean: " << calculateMean(numbers) << std::endl;

        std::cout << "Median: " << calculateMedian(numbers) << std::endl;

        std::cout << "Mean Square: " << calculateMeanSquare(numbers) << std::endl;

        std::cout << "Variance: " << calculateVariance(numbers) << std::endl;
    }
    catch (std::runtime_error& er) {
        std::cout << "OSHIBKA! - " << er.what();
    }

    return 0;
}