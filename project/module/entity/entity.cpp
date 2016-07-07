#include "entity/entity.h"
#include <string.h>
#include "json/json.h"
#include <sstream>
using namespace std;

Json::Reader * Entity::reader = new Json::Reader();
Json::Value * Entity::root = new  Json::Value();
Json::FastWriter * Entity::fwriter = new Json::FastWriter();

void Packet::initJson(char* json)
{
	if(Entity::reader->parse(json,*root))
	{
		this->flag = (*Entity::root)["flag"].asInt();
		this->data = new string((*Entity::root)["data"].asString());
		root->clear();
	}
}

string Packet::toJsonString()
{
    (*root)["data"] = Json::Value(*data);
    (*root)["flag"] = Json::Value(flag);
    string json = fwriter->write(*root);
    root->clear();
    return json;
}
//template<class Type>
void Location::initJson(char* json)
{
	if(Entity::reader->parse(json,*root))
	{
		this->x = (*Entity::root)["x"].asDouble();
		this->y = (*Entity::root)["y"].asDouble();
		root->clear();
	}
}
//template<class Type>
string Location::toJsonString()
{
	// (*root)["x"] = Json::Value(x);
 //    (*root)["y"] = Json::Value(y);
 //    string json = fwriter->write(*root);
 //    root->clear();
	stringstream ss ;
	ss<<"{\"x\":"<<x<<",\"y\":"<<y<<"}";
	string json = ss.str();
    return json;
}

void Dimension::initJson(char* json)
{
	if(Entity::reader->parse(json,*Entity::root))
	{
		this->w = (*Entity::root)["w"].asInt();
		this->h = (*Entity::root)["h"].asInt();
		root->clear();
	}
}

string Dimension::toJsonString()
{
	(*root)["w"] = Json::Value(w);
    (*root)["h"] = Json::Value(h);
    string json = fwriter->write(*root);
    root->clear();
    return json;
}