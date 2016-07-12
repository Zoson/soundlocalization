#include "net/server.h"
#include <string.h>
#include "net/callback.h"
using namespace std;
class cb:public ServerCallback
{
public:
	void getClientMessage(char*buf ,int size);
};
void cb::getClientMessage(char*buf ,int size)
{
	printf("call back rec %s\n",buf );
}
int main()
{
	Server *server = new Server();
	server->setCallback(new cb());
	server->startServer();
    return 0;
}