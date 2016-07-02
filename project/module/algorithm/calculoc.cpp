#include "algorithm/calculoc.h"
#include "unistd.h"
CalcuLoc::CalcuLoc()
{
	location = new int[2];
}

CalcuLoc::~CalcuLoc()
{
	delete location;
}

int* CalcuLoc::getLocation(int time0,int time1,int time2)
{
	sleep(1);
	location[0] = time0-time1;
	location[1] = time0-time2;
	return location;
}