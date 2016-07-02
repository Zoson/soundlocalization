#ifndef _CALCULOC_H_
#define _CALCULOC_H_

class CalcuLoc
{
public: 
	CalcuLoc();
	~CalcuLoc();
	int* getLocation(int,int,int);
private:
	int* location;
};

#endif