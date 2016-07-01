#include "net/server.h"
#include "json/json.h"
#include <string.h>
#include "entity/entity.h"
using namespace std;
int main()
{
	//Server *server = new Server();
	//server->startServer();
	//字符串
    const char* str = "{\"flag\":0,\"data\":\"start\"}";

    Json::Reader reader;
    Json::Value root;

    //从字符串中读取数据
    if(reader.parse(str,root))
    {
        
        
    }

    return 0;
}