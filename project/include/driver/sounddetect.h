#ifndef _SOUNDDETECT_H
#define _SOUNDDETECT_H
struct timeval;
class SoundDetect
{
public:
	SoundDetect();
	~SoundDetect();
	void init();
	double* getTimes();
private:
	double time[3];
	struct timeval time0;
	struct timeval time1;
	struct timeval time2;
	struct timeval time3;
	struct timeval diff1;
	struct timeval diff2;
	struct timeval diff3;
	int time_diff1;
	int time_diff2;
	int time_diff3;
	int fd;
	int aout;
	unsigned char command[2];
	unsigned char value[4];
	int ready[4];
	unsigned char str[8];
	int addr;
	int max_value[4];
	int key;
	void *i2c;
	int ok;
};

#endif