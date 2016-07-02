#include "net/server.h"
#include "json/json.h"
#include "domain/slocmanager.h"
#include <iostream>
using namespace std;

int main()
{
	SLocManager slm;
	slm.initThread();
}
