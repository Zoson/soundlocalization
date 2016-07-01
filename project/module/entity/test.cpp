#include "entity/entity.h"
#include <iostream>
using namespace std;

int main()
{
	Packet packet;
	packet.setFlag(FLAG_START);
	packet.setData("start");
	string cs = packet.toJsonString();
	cout<<"Packet json "<<cs<<" addr "<<&cs<<endl;
	Location location ;
	location.setX(10);
	location.setY(20);
	cout<<"loc :"<<location.toJsonString()<<endl;
	Dimension dim;
	dim.setW(100);
	dim.setH(200);
	cout<<"dim "<<dim.toJsonString()<<endl;

	char * pac = "{\"data\":\"hahhahahtrue\",\"flag\":0}";
	Packet p ;
	p.initJson(pac);
	cout<<"P data "<<p.getData()<<endl;

	char * sd = "{\"h\":200,\"w\":100}";
	Dimension d;
	d.initJson(sd);
	cout<<"d w"<<d.getW()<<endl;

	char * ls = "{\"x\":10,\"y\":20}";
	Location l ;
	l.initJson(ls);
	cout<<" l x"<<l.getX()<<endl;
}