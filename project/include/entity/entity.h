#ifndef _NET_ENTITY_H_
#define _NET_ENTITY_H_
#include "json/json.h"
#include <string.h>
using namespace std;
#define FLAG_START 0
#define FLAG_STOP 1
#define FLAG_LOCATION 2
#define FLAG_DIMENSION 3
class Entity
{
public:
	Entity(){};
	virtual ~Entity(){}
	virtual void initJson(char *json)=0;
	virtual string toJsonString()=0;
	static Json::Reader *reader;
	static Json::Value *root;
	static Json::FastWriter *fwriter;
};
class Packet:public Entity
{
public:
	Packet(){}
	~Packet()
	{
		delete data;
	}
	void setFlag(int flag)
	{
		this->flag = flag;
	}
	void setData(char *data)
	{
		string *str = new string(data);
		this->data = str;
	}
	int getFlag()
	{
		return flag;
	}
	string getData()
	{
		return *data;
	}
	void initJson(char* json);
	string toJsonString();

private:
	int flag;
	string *data;
};
template<class Type>
class Location:public Entity
{
public:
	Location(){}
	~Location(){}
	void setX(Type x)
	{
		this->x = x;
	}
	void setY(Type y)
	{
		this->y = y;
	}
	Type getX()
	{
		return x;
	}
	Type getY()
	{
		return y;
	}
	void initJson(char* json);
	string toJsonString();
private:
	Type x;
	Type y;
};

class Dimension:public Entity
{
public:
	Dimension(){}
	~Dimension(){}
	void setW(int x)
	{
		this->w = x;
	}
	void setH(int h)
	{
		this->h =h;
	}
	int getW()
	{
		return w;
	}
	int getH()
	{
		return h;
	}
	void initJson(char* json);
	string toJsonString();
private:
	int w;
	int h;
};
template<class Type>
class TimeRecord
{
public:
	TimeRecord(){};
	~TimeRecord(){};
	Type getTimeA()
	{
		return time_a;
	}
	Type getTimeB()
	{
		return time_b;
	}
	Type getTimeC()
	{
		return time_c;
	}
	Type setTimeA(Type time)
	{
		this->time_a = time;
	}
	Type setTimeB(Type time)
	{
		this->time_b = time;
	}
	Type setTimeC(Type time)
	{
		this->time_c = time;
	}
private:
	Type time_a;
	Type time_b;
	Type time_c;
};
#endif