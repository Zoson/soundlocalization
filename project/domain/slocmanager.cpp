#include "domain/slocmanager.h"
#include "json/json.h"
#include "net/server.h"
#include <string.h>
#include <pthread.h>
#include <iostream>
#include "algorithm/calculoc.h"
#include "driver/sounddetect.h"
#include "stdio.h"
using namespace std;

SLocManager::SLocManager()
{
	m_Server = new Server();
	m_calculoc = new CalcuLoc();
	m_detect = new SoundDetect();

	pthread_mutex_init(&mutex_loc_time, NULL);
	pthread_mutex_init(&mutex_loc_info, NULL);
}
SLocManager::~SLocManager()
{
	 delete m_Server;
	 delete m_calculoc;
	 delete m_detect;	
}

void SLocManager::initThread()
{
	pthread_create(&pt_startserver,NULL,startServerThread,this);
	pthread_create(&pt_detectsound,NULL,detectSoundThread,this);
	pthread_create(&pt_computelocation,NULL,computeLocationThread,this);
	pthread_join(pt_startserver,NULL);
	pthread_join(pt_detectsound,NULL);
	pthread_join(pt_computelocation,NULL);
}

void SLocManager::runServer()
{
	cout<<"runServer"<<endl;
	m_Server->startServer();
}

void SLocManager::runSoundDetect()
{
	// for (int i = 0; i < 10; ++i)
	// {
	// 	int * a = m_detect->getTimes();
	// }
}

void SLocManager::runCalcuLoc()
{
	char *msg = "abc";
	// while(true)
	// {
	// 	sleep(1);
	// 	//printf("runCalcuLoc %s\n", msg);
	// 	m_Server->sendMessage(msg,3);
	// }
	// for (int i = 0; i < 10; ++i)
	// {
	// 	int * a = m_calculoc->getLocation(1000+3*i,20+i*i,20+i*i*i/3);;
	// 	printf("x:%d y:%d\n", a[0],a[1]);
	// }
}

void* SLocManager::startServerThread(void *arg)
{
	SLocManager *s = (SLocManager*)arg;
	s->runServer();
}

void* SLocManager::detectSoundThread(void *arg)
{
	SLocManager *s = (SLocManager*)arg;
	s->runSoundDetect();
	
}

void* SLocManager::computeLocationThread(void *arg)
{
	SLocManager *s = (SLocManager*)arg;
	s->runCalcuLoc();
}