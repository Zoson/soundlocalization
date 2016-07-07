#ifndef _CALCULOC_H_
#define _CALCULOC_H_

class CalcuLoc
{
public: 
	CalcuLoc();
	~CalcuLoc();
	double* getLocation(double t2,double t3,double t4);
protected:
	double get_ZB(double t1);
private:
	double location[2];
	const double v;
	double L;

};

#endif