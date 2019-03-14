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
void gomoku_show(char gomoku[][26]){
	int i,j;
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			printf("%c ",gomoku[i][j]);
		}
		printf("\n");
	}
}
void gomoku_init(char gomoku[][26]){
	int i,j;
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			gomoku[i][j]='_';
		}
	}
	for(i=0;i<N;i++)
		gomoku[0][i]=gomoku[i][0]=(i+'a');
	
}
int checkFive2(int x,int y,char gomoku[N][N]);
int main(){
	char gomoku[N][N];
	SA server_addr;
	int msg[3];
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
		if(x<1||x>N-1 ||y<1||y>N-1){
				printf("范围不对\n");
				goto loop;
		}
		gomoku[x][y]='0';
		gomoku_show(gomoku);
		msg[0]=x;msg[1]=y;msg[2]=0;
		if(checkWin(x,y,gomoku,'0')){
			printf("client win\n");
			msg[2] = -1;
            my_send(&sendlen,fd_socket,msg,12);
            my_close(fd_socket);
            break;
		}
		my_send(&sendlen,fd_socket,msg,12);
		printf("请等待server下棋\n");
		my_recv(&recvlen,fd_socket,msg,1024);
		gomoku[msg[0]][msg[1]]='*';
		gomoku_show(gomoku);
		if(msg[2] == -2){
			printf("server win\n");
            my_close(fd_socket);
		    break;
        }
	    
    }
	my_close(fd_socket);
}
