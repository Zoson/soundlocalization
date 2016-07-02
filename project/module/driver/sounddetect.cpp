#include "driver/sounddetect.h"
#include "unistd.h"
SoundDetect::SoundDetect()
{
	times = new int[3];
}

SoundDetect::~SoundDetect()
{
	delete times;
}

int* SoundDetect::getTimes()
{
	sleep(1);
	times[0] = 100;
	times[1] = 110;
	times[2] = 120;
	return times;
}