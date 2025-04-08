#pragma once
#ifndef RAND
#define RAND

#include <random>

class Random
{
public:
	static float bitRandom();
	static int intRandom(int, int);
};

#endif // !RAND