#include "algorithm/calculoc.h"
#include <iostream>
using namespace std;
int main()
{
	CalcuLoc c;
	for(int i=0;i<10;i++)
	{
		int * loc = c.getLocation(100+i,20,30);
		cout<<"loc x:"<<loc[0]<<" y:"<<loc[1]<<endl;
	}
}