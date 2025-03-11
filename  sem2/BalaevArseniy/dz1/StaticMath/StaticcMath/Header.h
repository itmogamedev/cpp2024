#pragma once
#include <vector>
namespace MathLibrary
{
	class Arithmetic
	{
	public:

		static double Avg(std::vector<double> data );
		static double MED(std::vector<double> data);
		static double RMS(std::vector<double> data);
		static double Disp(std::vector<double> data);
	};
}