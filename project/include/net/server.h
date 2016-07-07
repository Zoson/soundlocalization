/*
* Wrote by :Zhuang zhuoxin
*/
#ifndef _SERVER_H_
#define _SERVER_H_

#include <string>
#include <error.h>
#include <sys/errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

class Server
{
public:
	Server();
	~Server();
	void startServer();
	void setPost(int post);
	void setClient(int count);
	void sendMessage(const char* msg,int size);
protected:
	void createSocket();
	void initFdSet();
private:
	int m_sfd; 
	int *m_cfd;
	int m_client_num;
	int m_post;
	char m_buff[1024];
	fd_set m_global_rdfs;
	fd_set m_current_rdfs;
	fd_set m_global_wdfs;
	fd_set m_current_wdfs;
	int m_max_fd;
	int m_listenfd;
	struct sockaddr_in m_server;
	struct sockaddr_in m_client;

	char *m_send;
	int m_send_size;
	bool able_send;
};


#endif