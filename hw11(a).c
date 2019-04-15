#include<stdio.h>
#include<stdlib.h>
int total=0,liner[200][3]={0};
char **argv;
FILE *point_set;
struct point[500]{
	int x,y;
};
void bubblesort(void){
	int i=0,j=0,k=0;
	for(i=0;i<total;i++){
		for(j=0;j<total;j++){
			if(point[j].y>point[j+1].y){
				k=point[j].y;
				point[j].y=point[j+1].y;
				point[j+1].y=k;
			}
			if(point[j].y=point[j+1].y){
				if(point[j].x>point[j+1].x){
					k=point[j].x;
					point[j].x=point[j+1].x;
					point[j+1].x=k;
				}
			}
		}
	}
}
void read(void){
	int i=0;
	fscanf(point_set,"%d",total);
	for(i=0;i<total;i++){
		fscanf(point_set,"%d",point[i].y);
		fscanf(point_set,"%d",point[i].x);
	}	
}
int main(int argc,char**argv){
	point_set = fopen( *(argv+1),"r" );
}
