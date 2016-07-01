#include "net/server.h"
#include "json/json.h"
#include "domain/slocmanager.h"
int main()
{
	SLocManager slm;
	slm.initThread();
}