#include "pch.h" 
#include "MathLibrary.h"
#include <vector>
#include <math.h>

int average(std::vector<int> sequence) {
    int sum = 0;
    for (int num: sequence) {
        sum += num;
    }

    return sum / size(sequence);
}

int median(std::vector<int> sequence) {
    if (size(sequence) / 2 != 0) {
        return sequence[size(sequence) / 2 + 1];
    }
    else {
        return (sequence[size(sequence) / 2] + sequence[size(sequence) / 2 + 1]) / 2;
    }
}

int average_square(std::vector<int> sequence) {
    int sum = 0;
    for (int num : sequence) {
        sum += pow(2, num);
    }

    return sqrt(sum / size(sequence));
}

int variance(std::vector<int> sequence) {
    int average_sequence = average(sequence);
    
    int sum = 0;
    for (int num : sequence) {
        sum += pow(2, num - average_sequence);
    }

    return sum / size(sequence);
}