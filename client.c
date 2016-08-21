/*************************************************************************
> File Name: client.c
> Author: CarlSun
> Mail:sunxiuyang04@gmail.com 
> Created Time: Sat Aug 20 21:30:54 2016
 ************************************************************************/

#include<gomoku.h>
#include<my_socket.h>
#define IP "127.0.0.1"
#define PORT 8888
int checkFive2(int x,int y,char gomoku[N][N]);
int main(){
	char gomoku[N][N];
	SA server_addr;
	int msg[2];
	int fd_socket,index,sendlen=0,recvlen=0;
	my_socketCli(&fd_socket,MY_TCP,IP,PORT,&server_addr);
	my_connect(fd_socket,(pSA)&server_addr,sizeof(SA));
	printf("client start\n");
	gomoku_init(gomoku);
	int x,y;
	while(1){
loop:
		printf("client 请下棋：\n");
		scanf("%d %d",&x,&y);
		if(gomoku[x][y]!='_'){
			printf("这个位置已经有棋子了\n");
			goto loop;
		}
		if(x<1||x>9 ||y<1||y>9){
				printf("范围不对\n");
				goto loop;
		}
		gomoku[x][y]='0';
		gomoku_show(gomoku);
		if(checkFive2(x,y,gomoku)){
			printf("client win\n");
			break;
		}
		msg[0]=x;msg[1]=y;
		my_send(&sendlen,fd_socket,msg,8);
		printf("请等待server下棋\n");
		my_recv(&recvlen,fd_socket,msg,1024);
		gomoku[msg[0]][msg[1]]='*';
		gomoku_show(gomoku);
	}
	my_close(fd_socket);
}
