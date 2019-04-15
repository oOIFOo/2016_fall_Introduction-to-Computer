#include<stdio.h>
#define grindsize 8
#define pathsize 
int change=0,time=2,b,chess[grindsize][grindsize]={0},a[8][2]={
			{2,1},
			{2,-1},
			{1,2},
			{1,-2},
			{-1,2},
			{-1,-2},
			{-2,1},
			{-2,-1},
		};
int walk=0,i=0,j=0,x0=0,y0=0;
		void dfs(int time,int change,int x0,int y0){
			int r=0;
			for(r=0;r<grindsize;r++){
				int x=0,y=0,y2=0,x2=0,change=0;
				change=0;
				x2=x0+a[r][0];
				y2=y0+a[r][1];	
				if(x2<grindsize&&y2<grindsize&&x2>=0&&y2>=0&&change==0){
					if(chess[x2][y2]==0){
						change=1;
						chess[x2][y2]=time;
						time++;
						x0=x2;
						y0=y2;
						r=0;
						b=time;
					}
				}
			}
			//printf("%d",time);
		}
int main(void){
	printf("start point\n",x0,y0);
	scanf("%d%d",&x0,&y0);
	chess[x0][y0]=1;
		while(1){
		dfs(time,change,x0,y0);
			if(change==0){
				while(j<grindsize){
					for(i=0;i<8;i++){
						for(j=0;j<8;j++){
							printf("%d\t",chess[i][j]);
						}
						printf("\n");
		}	
		printf("totally move %d time\n",b);
		break;
				}
			}
		}
}
