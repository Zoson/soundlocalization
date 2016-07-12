#ifndef _SERVER_CALLBACK_
#define _SERVER_CALLBACK_

class ServerCallback
{
public:
	virtual void getClientMessage(char *buf,int size) = 0;
};

#endif