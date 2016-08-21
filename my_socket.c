/*************************************************************************
> File Name: my_socket.c
> Author: CarlSun
> Mail:sunxiuyang04@gmail.com 
> Created Time: Sat Aug 20 20:36:03 2016
 ************************************************************************/

#include<my_socket.h>
void my_socketCli(int *fd_socket,int type,char* ip,int port,SA *my_addr{
	ASSERT(type==MY_TCP || type==MY_UDP,"invalid arg\n");
	if(type==MY_TCP){
			ASSERT((*fd_socket=socket(AF_INET,SOCK_STREAM,0))!=-1,"TCP socket init fail\n");
	}else if(type==MY_UDP){
	ASSERT((*fd_socket=socket(AF_INET,SOCK_DGRAM,0))!=-1,"UDP socket init fail\n");
	}
	memset(my_addr,0,sizeof(SA));
	(*my_addr).sin_family=AF_INET;
	(*my_addr).sin_port=htons(port);
	(*my_addr).sin_addr.s_addr=inet_addr(ip);
	return;
	
}
void my_socketSer(int *fd_socket,int type,char* ip,int port){
	ASSERT(type==MY_TCP || type==MY_UDP,"invalid arg\n");
	if(type == MY_TCP){
		ASSERT((*fd_socket=socket(AF_INET,SOCK_STREAM,0))!=-1,"TCP socket init fail");
	} else if(type == MY_UDP){
		ASSERT((*fd_socket=socket(AF_INET,SOCK_DGRAM,0))!=-1,"UDP socket init fail\n");
	}
	SA my_addr;
	memset(&my_addr,0,sizeof(my_addr));
	my_addr.sin_family=AF_INET;
	printf("PORT:%s IP:%s\n",port,ip);
	my_addr.sin_port=htons(prot);
	my_addr.sin_addr.s_addr=inet_addr(ip);
	int len = sizeof(my_addr);
	ASSERT(bind(*fd_socket,(struct sockaddr*)&my_addr,len)!=-1,"bind fail\n");
	return;
}
void my_listen(int fd_socket,int listen_num){
	ASSERT((listen(fd_socket,listen_num))!=-1,"listen fail\n");
}
ept(int *fd_client,int fd_socket,pSA client_addr,int* addrlen){

		ASSERT((*fd_client = accept(fd_socket,client_addr,addrlen))!=-1,"server accept fail\n");
}
void my_send(int *sendlen,int fd_socket,int *msg,int len){

		ASSERT((*sendlen=send(fd_socket,msg,len,0))!=-1,"send fail\n");
}
void my_recv(int *recvlen,int fd_socket,int *msg,int len){

		ASSERT((*recvlen=recv(fd_socket,msg,len,0))!=-1,"recv fail\n");
}

