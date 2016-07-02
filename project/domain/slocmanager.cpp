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

}

void SLocManager::runSoundDetect()
{
	for (int i = 0; i < 10; ++i)
	{

		int * a = m_detect->getTimes();
		printf("time1:%d time2:%d time3:%d\n", a[0],a[1],a[2]);
	}
}

void SLocManager::runCalcuLoc()
{
	for (int i = 0; i < 10; ++i)
	{
		int * a = m_calculoc->getLocation(1000+3*i,20+i*i,20+i*i*i/3);;
		printf("x:%d y:%d\n", a[0],a[1]);
	}
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