/*************************************************************************
> File Name: server.c
> Author: CarlSun
> Mail:sunxiuyang04@gmail.com 
> Created Time: Sat Aug 20 20:25:49 2016
 ************************************************************************/

#include"gomoku.h"
#include"my_socket.h"
#define IP "127.0.0.1"
#define PORT 8888
void gomoku_show(char gomoku[][10]){
	int i,j;
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			printf("%c ",gomoku[i][j]);
		}
		printf("\n");
	}
}
void gomoku_init(char gomoku[][10]){
	int i,j;
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			gomoku[i][j]='_';
//			printf("%c %d %d\n",gomoku[i][j],i,j);
		}
	}
	for(i=0;i<N;i++)
		gomoku[0][i]=gomoku[i][0]=(i+'0');
	
}
int checkFive1(int x,int y,char gomoku[N][N]);
int main(){
	int msg[2];
	char gomoku[N][N];
	SA client_addr;
	int fd_socket,fd_client;
	my_socketSer(&fd_socket,MY_TCP,IP,PORT);
	my_listen(fd_socket,5);
	int sendlen=0,recvlen=0,len=0;
	int i,j,x,y;
	gomoku_init(gomoku);
	gomoku_show(gomoku);
	printf("五子棋游戏开始\n");
	my_accept(&fd_client,fd_socket,(pSA)&client_addr,&len);
	while(1){
		printf("请等待client下棋\n");
		my_recv(&recvlen,fd_client,msg,1024);
		gomoku[msg[0]][msg[1]]='0';
		gomoku_show(gomoku);
		//server下棋
loop:
		printf("server 请下棋:\n");
		scanf("%d %d",&x,&y);
	    if(gomoku[x][y]!='_'){
			printf("这个位置已经有棋子了\n");
			goto loop;
		}
		if(x<1||x>N-1 || y<1||y>N-1){
			printf("范围不对\n");
			goto loop;
		}
		gomoku[x][y]='*';
		gomoku_show(gomoku);
		if(checkWin(x,y,gomoku,'*')){
			printf("server win 1\n");
			break;
		}
		msg[0]=x;
		msg[1]=y;
		my_send(&sendlen,fd_client,msg,recvlen);
	}
	my_close(fd_socket);
	my_close(fd_client);
}
