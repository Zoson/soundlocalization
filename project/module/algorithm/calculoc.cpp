#include "algorithm/calculoc.h"
#include "unistd.h"
#include <math.h>
#include <stdio.h>
CalcuLoc::CalcuLoc():v(3400.0),L(1.0)
{
	location[0] = 0.0;
	location[1] = 0.0;
}

CalcuLoc::~CalcuLoc()
{
}

double CalcuLoc::get_ZB(double t1)
{
	double v1 = 3400.0;
	double a = 4 * v1*v1*t1*t1 - 4;
	double b = 4 * v1*v1*v1*t1*t1*t1 - 4 * v1*t1;
	double c = v1*v1*v1*v1*t1*t1*t1*t1 - 2 * v1*v1*t1*t1 + 2;
	double w = (0 - b + sqrt(b*b - 4 * a*c)) / (2 * a);
	double k = sqrt(fabs(w*w - 0.25)) - L;
	return k;
}

double* CalcuLoc::getLocation(double t2,double t3,double t4)
{
	if (t4 - t3 + t2 == 0){
		if (t4 - t3 == 0){
			location[1] = get_ZB(t3 - t2);
			location[0] = 0;
		}
		if (t2 - t3 == 0){
			location[0] = get_ZB(t3 - t4);
			location[1] = 0;
		}
	}
	else{
		double k = 4 * L*(t4 - t3 + t2);
		location[0] = v*v*t2*(t3*(t3 - t2) - t4*(t4 - t2)) / k;
		location[1] = v*v*t4*(t3*(t3 - t4) - t2*(t2 - t4)) / k;
	}
	printf("CalcuLoc::getLocation x:%lf y:%lf | ",location[0],location[1] );
	return location;
}