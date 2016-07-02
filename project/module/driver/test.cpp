#include "driver/sounddetect.h"
#include <iostream>
using namespace std;
int main()
{
	SoundDetect c;
	for(int i=0;i<10;i++)
	{
		int * time = c.getTimes();
		cout<<"time1:"<<time[0]<<" time2:"<<time[1]<<" time3"<<time[2]<<endl;
	}
}