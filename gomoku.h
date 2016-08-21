/*************************************************************************
> File Name: gomoku.h
> Author: CarlSun
> Mail:sunxiuyang04@gmail.com 
> Created Time: Sat Aug 20 20:28:12 2016
 ************************************************************************/

#ifndef _5ZIQI_
#define _5ZIQI_
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 10
typedef struct tag{
		int x,y,xl,yl;
}node;

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
		}
		for(i=0;i<N;i++)
			gomoku[0][i]=gomoku[i][0]=(i+'0');
	}
}
#endif
