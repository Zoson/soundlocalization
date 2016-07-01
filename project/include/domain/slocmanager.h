#ifndef _SOUND_LOCATION_H_
#define _SOUND_LOCATION_H_
#include <pthread.h>
class Server;
class SLocManager
{
public:
	SLocManager();
	~SLocManager();
	void initThread();
	static void *startServerThread(void *arg);
	static void *detectSoundThread(void *arg);
	static void *computeLocationThread(void *arg);
private:
	Server *m_Server;
	pthread_t pt_startserver;
	pthread_t pt_detectsound;
	pthread_t pt_computelocation;
};

#endif