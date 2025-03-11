#include "Header.h"
#include <iostream>
#include <math.h>
#include <vector>

namespace MathLibrary
{
    double Arithmetic::Avg(std::vector<double> data) {
        int y = 0;
        for (int i : data) {
            y += i;
        }
        return static_cast<double>(y) / size(data);

    }

    double Arithmetic::MED(std::vector<double> data)
    {
        int y = 0;

        for (int i = 0; i < size(data); i++) {
            for (int j = 0; j < size(data) - 1; j++) {
                if (data[j] > data[j + 1]) {
                    int b = data[j];
                    data[j] = data[j + 1];
                    data[j + 1] = b;
                }
            }
        }
        if (size(data) % 2 == 0) {

            return static_cast<double>((data[size(data) / 2] + data[size(data) / 2 - 1])) / 2;
        }
        else {
            return static_cast<double>(data[size(data) / 2]);
        }

    }

    double Arithmetic::RMS(std::vector<double> data) {
        int y = 0;

        for (int i : data)
        {
            y += i* i;
        }
        return sqrt(static_cast<double>(y) / size(data));
    }
    double Arithmetic::Disp(std::vector<double> data) {
        double sr = Arithmetic::Avg(data);
        double y = 0;
        for (int i : data)
        {
            y += (i-sr)* (i - sr);
        }


        return y /size(data);
    }


}