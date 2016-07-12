#include "domain/slocmanager.h"
#include "json/json.h"
#include "net/server.h"
#include <string.h>
#include <pthread.h>
#include <iostream>
#include "algorithm/calculoc.h"
#include "driver/sounddetect.h"
#include <stdio.h>
#include "entity/entity.h"
#include <math.h>
#include "net/callback.h"
using namespace std;

SLocManager::SLocManager():isStarted(false)
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
	pthread_join(pt_startserver,NULL);
}

void SLocManager::getClientMessage(char *buf,int size)
{
	printf("slocManage %s\n",buf );
	Packet pack;
	pack.initJson(buf);
	if(pack.getFlag()==FLAG_START)
	{
		if(!isStarted)
		{
			printf("start SoundDetect\n");
			pthread_create(&pt_detectsound,NULL,detectSoundThread,this);
			pthread_join(pt_detectsound,NULL);
		}else{
			printf("SoundDetect is already started\n");
		}
	}else if (pack.getFlag()==FLAG_STOP){
		printf("stop SoundDetect\n");
	}
}

void SLocManager::runServer()
{
	this->m_Server->setCallback(this);
	m_Server->startServer();
}

void SLocManager::runSoundDetect()
{
	m_detect->init();
	while(true)
	{
		double* times = m_detect->getTimes();
		if((int)abs(times[0])>=1.0||(int)abs(times[1])>=1.0||(int)abs(times[2])>=1.0)
		{
			printf("times >1.0\n");
			continue;
		
		}
		double *location = m_calculoc->getLocation(times[0],times[1],times[2]);
		Location loc;
		Packet packet;
		packet.setFlag(FLAG_LOCATION);
		loc.setX(location[0]);
		loc.setY(location[1]);
		loc.setTime1(times[0]);
		loc.setTime2(times[1]);
		loc.setTime3(times[2]);
		string str = loc.toJsonString();
		packet.setData(str.data());
		string pack = packet.toJsonString();
		pack = pack+"\n";
		m_Server->sendMessage(pack.data(),strlen(pack.data()));
		printf("loc::%s\n", str.data());
		sleep(1);
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

