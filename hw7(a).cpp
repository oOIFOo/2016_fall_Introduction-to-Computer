#include<stdio.h>
int num=0,a[100]={0},i=2;
void face(int i){
	a[0]=0,a[1]=1;
	a[i]=a[i-1]+a[i-2];
	i++;
	if(i<100)
	face(i);
	}
int main(){
	while(1){
	printf("input a number\n");
	scanf("%d",&num);
	face(i);
	printf("%d\n",a[num]);
	}
}
