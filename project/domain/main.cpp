#include "net/server.h"
#include "json/json.h"
#include "domain/slocmanager.h"
#include "algorithm/calculoc.h"
#include "driver/sounddetect.h"
#include <iostream>
using namespace std;
int main()
{

	// SLocManager slm;
	// slm.initThread();
	// return 0;
	Calculoc c;
	SoundDetect s;
	s.init();
	while(1)
	{
		double *times = s.getTimes();
		double * loc = c.getLocation(times[0],times[1],times[2]);
		cout<<"x:"<<loc[0]<<" y:"<<loc[1]<<endl;
	}
}
