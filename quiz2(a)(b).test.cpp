#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//#define testcase
#define data1
//#define data2
//#define data3
//#define data4

#include "test2.h"
#ifdef testcase
int x0=4,y0=4,goal[5][6]={0};
#endif
#ifdef data1
int x0=1,y0=1,goal[8][8]={0};
#endif
#ifdef data2
int x0=5,y0=2,goal[8][8]={0};
#endif
int change=0,time=1,b=0,a[4][2]={
			{1,0},
			{0,-1},
			{-1,0},
			{0,1},
		};
int walk=0,i=0,j=0,max=5555;
		void dfs(int time,int x0,int y0){
			int r=0;
			for(r=0;r<4;r++){
				int x=0,y=0,y2=0,x2=0,change=0;
				b=0;
				change=0;
				x2=x0+a[r][0];
				y2=y0+a[r][1];	
				if((x2<Width) && (y2<Height) && (x2>=0) &&(y2>=0) && (change==0) ){
					if(map[x2][y2]==0){
						change=1;
						map[x2][y2]=9;
						dfs(time+1,x2,y2);
						map[x2][y2]=0;
					}
					if( (map[x2][y2]==-1) && (max>time)) {
						memcpy(goal,map,Height*Width*4);
						b=1;
					//	printf("%d\n",time);
						max=time;
						map[x0][y0]=0;
						//break;
					}
				}	
			//printf("%d",time);
		}
	}	
int main(void){
	map[x0][y0]=9;
	dfs(time,x0,y0);
		while(j<Height){
			for(i=0;i<Height;i++){
				for(j=0;j<Width;j++){
					printf("%d\t",goal[i][j]);
				}
				printf("\n");
			}	
		printf("totally min move %d step\n",max);
		//break;
		}	
	return 0;	
}
