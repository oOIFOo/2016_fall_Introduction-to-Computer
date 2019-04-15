#include<stdio.h>
#include<stdlib.h>
int right=0,left=0,count=0,ans=0;
long long total=0;
FILE *line_set1;
char **argv;
typedef struct {
	int left, right;
} Line;
Line line[300000]={0};
void read(void){
	int i=0;
	for(i=0;i<300000;i++){
		if(fscanf(line_set1,"%d",&line[i].left)==EOF)
			break;
		fscanf(line_set1,"%d",&line[i].right);
	//	printf("%d\n",line[i].left);
	}
	count=i-1;
	fclose(line_set1);
}
void set(void){
	int i=0,a=0,b=0,c=0;
	Line tmp;
	while(1){
		c=0;
		for(i=0;i<count;i++){
			a=line[i].left;
			b=line[i+1].left;
			if(a>b){
				tmp = line[i];
				line[i]=line[i+1];
				line[i+1] = tmp;
				c=1;
			}
		//	printf("%d",c);
		}
	//	printf("%d",c);
		if(c==0)
			break;
	}
}
void compare(void){
	int i=0,x=0,j=0;
	for(i=0;i<count;i++){
		for(j=1; (i+j) <count;j++){
			if( (line[i].right<=line[i+j].left) ){
				break;
			}
			total=total+(line[i].right-line[i+j].left);
		//	printf("%d = %d - %d",dis[x],line[i].right,line[i+j].left);
		//	system("pause");
		//	printf("%lld\n",total);
			if(line[i].right>line[i+j].right){
				total=total-(line[i].right-line[i+j].right);
			}
		}
	}
}
int main(int argc ,char **argv){
	int i=0;
	line_set1=fopen (*(argv+1) , "r");
	if( (line_set1) == NULL)
		printf("error opening file\n");
	read();
	set();
	for(i=0;i<100;i++){
		printf("%d/",line[i].left);
		printf("%d/\n",line[i].right);
	}
//	system("pause");
	compare();
	printf("%lld",total);
}
