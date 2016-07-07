#include "driver/sounddetect.h"
#include "unistd.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <linux/i2c-dev.h>
#include <ncurses.h>
#include <sys/time.h> 
SoundDetect::SoundDetect()
{
	i2c = malloc(4);
	addr = 0x48;
	ok = 1;
	ready[0]=0;
	ready[1]=0;
	ready[2]=0;
	ready[3]=0;
}

SoundDetect::~SoundDetect()
{
	close(fd);
}

void SoundDetect::init()
{
	initscr();
	noecho();
	cbreak();
	nodelay(stdscr, true);
	curs_set(0);
	fd = open("/dev/i2c-1", O_RDWR);
	if (fd < 0)
	{
		perror("Opening i2c device node\n");
		return 1;
	}
	int r = ioctl(fd, I2C_SLAVE, addr);
	if (r < 0)
	{
		perror("Selecting i2c device\n");
	}
	command[1] = 0;
	aout = 0;
}

double* SoundDetect::getTimes()
{
	while(ok)
	{
		for (i = 0; i < 4; i++)
		{
			if (ready[i] == 1) continue;
			command[1] = aout++;
			command[0] = 0x40 | ((i + 1) & 0x03); // output enable | read input i
			r = write(fd, &command, 2);
			r = read(fd, &value[i], 1);
			if (value[i] > 200)
			{
				switch (i)
				{
				case 0:
					gettimeofday(&time0, 0);
					break;
				case 1:
					gettimeofday(&time1, 0);
					break;
				case 2:
					gettimeofday(&time2, 0);
					break;
				case 3:
					gettimeofday(&time3, 0);
					break;
				}
				ready[i] = 1;
			}

			if (ready[0] == 1 && ready[1] == 1 && ready[2] == 1 && ready[3] == 1)
			{
				ok = 0;
				break;
			}

		}
	}
	ok=1;
	ready[0] = 0;
	ready[1] = 0;
	ready[2] = 0;
	ready[3] = 0;
	timeval_subtract(&diff1, &time0, &time1);
	timeval_subtract(&diff2, &time0, &time2);
	timeval_subtract(&diff3, &time0, &time3);
	time_diff1 = diff1.tv_usec;
	time_diff2 = diff2.tv_usec;
	time_diff3 = diff3.tv_usec;
	time[0] = time_diff1 / 1000000.0;
	time[1] = time_diff2 / 1000000.0;
	time[2] = time_diff3 / 1000000.0;
	return time;
}