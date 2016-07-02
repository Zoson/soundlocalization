#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <fcntl.h>
#include "net/server.h"

Server::Server()
{
	this->m_post = 4999;
	this->m_client_num = 10;
	this->m_listenfd = -1;
	createSocket();
	initFdSet();
	
}

Server::~Server()
{
	if (m_listenfd!=-1)
	{
		close(m_listenfd);
	}
}

void Server::createSocket()
{
	int sockfd, opt = 1;
	socklen_t len;
	int timep;
	int ret;

	m_listenfd = socket(AF_INET, SOCK_STREAM, 0);
	if(m_listenfd < 0){
		perror("Create socket fail.");
		return;
	} 

	if((ret = setsockopt(m_listenfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) < 0){
		perror("Error, set socket reuse addr failed");  
		return;
	}

	bzero(&m_server, sizeof(m_server));
	m_server.sin_family = AF_INET;
	m_server.sin_port   = htons(m_post);
	m_server.sin_addr.s_addr  = htonl(INADDR_ANY);
	
	len = sizeof(struct sockaddr);
	if(bind(m_listenfd, (struct sockaddr *)&m_server, len)<0){
			  perror("bind error.");
		return;
	}
	listen(m_listenfd, m_client_num);
}

void Server::initFdSet()
{
	FD_ZERO(&m_global_rdfs);
	FD_SET(m_listenfd,&m_global_rdfs);
	m_max_fd = m_listenfd;
}

void Server::setClient(int count)
{
	this->m_client_num = count;
}

void Server::startServer()
{
	int bytes = 0;
	int len = sizeof(struct sockaddr_in);
	while(1)
	{
		m_current_rdfs = m_global_rdfs;
		if(select(m_max_fd + 1, &m_current_rdfs, NULL, NULL, NULL)<0)
		{
			perror("select error.\n");
			return ;
		}

		for(int i = 0; i <= m_max_fd; i++)
		{

			if(FD_ISSET(i, &m_current_rdfs))
			{
				if(m_listenfd == i){
					if((m_sfd = accept(m_listenfd, (struct sockaddr*)&m_client, (socklen_t*)&len))<0)
					{
						perror("accept error.\n");
						return ;
					}
					printf("sockfd:%d\n", m_sfd);
					FD_CLR(i, &m_current_rdfs);
					m_max_fd = m_max_fd > m_sfd ? m_max_fd :m_sfd;
					FD_SET(m_sfd, &m_global_rdfs);
				}else{
					printf("read socket:%d\n", i);
					bytes = recv(i, m_buff, sizeof(m_buff), 0);
					if(bytes < 0){
						perror("recv error.\n");
						return ;
					}
					if(bytes == 0){
						FD_CLR(i, &m_global_rdfs);
						close(i);
						continue;
					}
					printf("buf:%s\n", m_buff);
					send(i, m_buff, strlen(m_buff), 0);
				}

			}
	
		}
	}
}

void Server::setPost(int post)
{
	this->m_post = post;
}