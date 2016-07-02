#ifndef _SOUNDDETECT_H
#define _SOUNDDETECT_H

class SoundDetect
{
public:
	SoundDetect();
	~SoundDetect();
	int* getTimes();
private:
	int* times;	
};

#endif