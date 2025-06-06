#pragma once

#ifdef HW_01_EXPORTS
#define HW_01_API __declspec(dllexport)
#else
#define HW_01_API __declspec(dllimport)
#endif
#include <vector>

extern "C" HW_01_API double srznach(std::vector <float> numb);

extern "C" HW_01_API double med(std::vector <float> numb);

extern "C" HW_01_API double skvad(std::vector <float> numb);

extern "C" HW_01_API double dis(std::vector <float> numb);