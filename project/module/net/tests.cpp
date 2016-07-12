#include "net/server.h"
#include <string.h>
using namespace std;
int main()
{
	Server *server = new Server();
	server->startServer();
    return 0;
}