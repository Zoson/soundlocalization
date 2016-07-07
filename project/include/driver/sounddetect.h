#ifndef _SOUNDDETECT_H
#define _SOUNDDETECT_H
class SoundDetect
{
public:
	SoundDetect();
	~SoundDetect();
	int init();
	double* getTimes();
protected:
	int timeval_subtract(struct timeval* result, struct timeval* x, struct timeval* y);
private:
	double time[3];
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