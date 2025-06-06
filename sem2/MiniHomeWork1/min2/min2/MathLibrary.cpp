// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <iostream>
#include "MathLibrary.h"

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

static unsigned long long previous_; 
static unsigned long long current_; 
static unsigned index_;


double calculateMean(const std::vector<int>& numbers) {
        if (numbers.empty()) {
            throw std::runtime_error("Vector is empty");
        }

        double sum = std::accumulate(numbers.begin(), numbers.end(), 0.0);
        return sum / numbers.size();
    }

double calculateMedian(std::vector<int> numbers) {
        if (numbers.empty()) {
            throw std::runtime_error("Vector is empty");
        }

        std::sort(numbers.begin(), numbers.end());

        size_t size = numbers.size();
        if (size % 2 == 0) {
            size_t mid = size / 2;
            return (numbers[mid - 1] + numbers[mid]) / 2.0;
        }
        else {

            return numbers[size / 2];
        }
    }

 double calculateMeanSquare(const std::vector<int>& numbers) {
        if (numbers.empty()) {
            throw std::runtime_error("Vector is empty");
        }

        double sumSquares = 0.0;
        for (int num : numbers) {
            sumSquares += num * num;
        }
        return sumSquares / numbers.size();
    }


double calculateVariance(const std::vector<int>& numbers) {
        if (numbers.empty()) {
            throw std::runtime_error("Vector is empty");
        }

        double mean = calculateMean(numbers);
        double sumSquaredDiff = 0.0;

        for (int num : numbers) {
            double diff = num - mean;
            sumSquaredDiff += diff * diff;
        }

        return sumSquaredDiff / numbers.size();
}
