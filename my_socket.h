/*************************************************************************
> File Name: my_socket.h
> Author: CarlSun
> Mail:sunxiuyang04@gmail.com 
> Created Time: Sat Aug 20 20:11:40 2016
 ************************************************************************/

#ifndef __MY_SOCKET_H__
#define __MY_SOCKET_H__
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#define IN
#define OUT
#define IN_OUT
#define MY_TCP 1
#define MY_UDP 2
typedef struct sockaddr* pSA;
typedef struct sockaddr_in SA;
#define ASSERT(flag,msg) ((flag)?NULL:(fprintf(stdout,(msg)),exit(EXIT_FAILURE)))//如果flag为假，则执行后面
void my_socketCli(int *fd_socket,int type,char* ip,int port,SA *my_addr);//tcp/udp客户端不需要绑定，但得把存有server的addr发过去，所以的将addr传出
void my_connect(int fd_socket,pSA server_addr,int len);//tcp客户端链接服务器
void my_socketSer(int *fd_socket,int type,char *ip,int port);//tcp/udp服务器端需要绑定自己的addr
void my_listen(int fd_socket,int listen_num);//tcp中服务器端一定别忘了listen
void my_accept(int *fd_client,int fd_socket,pSA client_addr,int *addrlen);//tcp服务器端接受客户端发来的信号，并将信息保存到client_addr结构体中,以后就用fd_client来链接服务器
void my_send(int* sendlen,int fd_socket,int *msg , int len);//tcp，这里msg是一个int型的数组
void my_recv(int* recvlen,int fd_socket,int *msg, int len);//tcp
void my_sendto(int* send_num,int fd_socket,int *msg,int len,pSA server_addr,int addrlen);//udp中使用
void my_recvfrom(int* recv_num,int fd_socket,int* msg,int len,pSA client_addr,int *addrlen);//udp中使用
void my_close(int fd_socket);//tcp/udp 关掉描述符
#endif

