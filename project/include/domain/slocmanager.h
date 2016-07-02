#ifndef _SOUND_LOCATION_H_
#define _SOUND_LOCATION_H_
#include <pthread.h>
#include <semaphore.h>
class Server;
class CalcuLoc;
class SoundDetect;
class SLocManager
{
public:
	SLocManager();
	~SLocManager();
	void initThread();
	void runServer();
	void runSoundDetect();
	void runCalcuLoc();
	static void *startServerThread(void *arg);
	static void *detectSoundThread(void *arg);
	static void *computeLocationThread(void *arg);
	
private:
	Server *m_Server;
	CalcuLoc *m_calculoc;
	SoundDetect *m_detect;
	
	sem_t sem_loc_time;
	sem_t sem_loc_info;
	pthread_mutex_t mutex_loc_time;
	pthread_mutex_t mutex_loc_info;

	pthread_t pt_startserver;
	pthread_t pt_detectsound;
	pthread_t pt_computelocation;
};

#endif