#include "domain/slocmanager.h"
#include "json/json.h"
#include "net/server.h"
#include <string.h>
#include <pthread.h>
#include <iostream>
using namespace std;

SLocManager::SLocManager()
{
	
}
SLocManager::~SLocManager()
{
	
}
void SLocManager::initThread()
{
	pthread_create(&pt_startserver,NULL,startServerThread,this);
}
void* SLocManager::startServerThread(void *arg)
{
	cout<<"startServerThread"<<endl;
}

void* SLocManager::detectSoundThread(void *arg)
{
	cout<<"detectSoundThread"<<endl;
}

void* SLocManager::computeLocationThread(void *arg)
{
	cout<<"computeLocationThread"<<endl;
}