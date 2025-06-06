#include "pch.h"

#include "HW_01.h"

double srznach(std::vector <float> numb) {
	double sum = 0, res = 0;
	if (numb.size() != 0) {
		for (int i = 0; i < numb.size(); i++) {
			sum += numb[i];
		}
		res = sum / numb.size();
	}
	return res;
}

double med(std::vector <float> numb) {
	double res = 0;
	if (numb.size() == 0) {
		return 0;
	}
	else if (numb.size() % 2 == 0) {
		return (numb[numb.size() / 2] + numb[(numb.size() / 2) - 1]) / 2;
	}
	else {
		return numb[floor(numb.size() / 2)];
	}
}
double skvad(std::vector <float> numb) {
	double sum = 0, res = 0;
	if (numb.size() != 0) {
		for (int i = 0; i < numb.size(); i++) {
			sum += pow(numb[i],2);
		}
		res = sqrt(sum / numb.size());
	}
	return res;
}

double dis(std::vector <float> numb) {
	double sum = 0, res = 0,sr;
	if (numb.size() != 0) {
		for (int i = 0; i < numb.size(); i++) {
			sum += numb[i];
		}
		sr = sum / numb.size();
		std::vector <float> kvotkl;
		for (int i = 0; i < numb.size(); i++) {
			kvotkl.push_back(pow(numb[i]-sr, 2));
		}
		sum = 0;
		for (int i = 0; i < kvotkl.size(); i++) {
			sum += kvotkl[i];
		}
		res = sum / kvotkl.size();
	}
	return res;
}