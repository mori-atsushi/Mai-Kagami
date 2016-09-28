#ifndef __BEZIER_H_INCLUDED__
#define __BEZIER_H_INCLUDED__

#include <math.h>

class Bezier {
public:
	Bezier(const double x1, const double y1, const double x2, const double y2);
	double Calc(const double x); // ŒvŽZ
private:
	double x1, x2, y1, y2;
};

#endif