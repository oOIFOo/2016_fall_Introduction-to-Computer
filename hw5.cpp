#include<stdio.h>
#include<stdlib.H>
#include <time.h>
int random[10];
	void magic(void){
		int random[10]={0},n=0,i=0;
		srand(time(NULL));
		for(n=0;n<10;n++){
			random[n]=rand()%900+100;
			//printf("%d ",random[n]);
			}
		}
	void sort_up(){
		int i=0,j=0,temp=0;
		for(i=0;i<10;i++){
			for(j=0;j<9;j++){
				if(random[j]>random[j+1]){
					temp = random[j];
                	random[j] = random[j+1];
                	random[j+1] = temp;
				}
			}
		}
	}
	void sort_down(){
		int i=0,j=0,temp=0;
		for(i=0;i<10;i++){
			for(j=0;j<9;j++){
				if(random[j]<random[j+1]){
				temp = random[j];
                random[j] = random[j+1];
                random[j+1] = temp;
				}
			}
		}
	}
	
	int main(void){
		int n=0,i=0,head=0,tail=9,mid=0,b=0;
		char a='i',q='r';
		srand(time(NULL));
		for(n=0;n<10;n++){
			random[n]=rand()%900+100;
			printf("%d ",random[n]);
		}
		n=0;
		printf("\n");
		printf("遞增或遞減(i or d):");
		scanf("%c",&a);
		while(a=='i'&&n<=9){
			sort_up();
			printf("%d ",random[n]);
			n++;
		}
		while(a=='d'&&n<=9){
			sort_down();
			printf("%d ",random[n]);
			n++;
		} 
		printf("\n");
		mid=(head+tail)/2;
	//	printf("%d",mid);
		while(q=='r'){
		//	printf("%d",mid);
			printf("請輸入您想找的數字:\n");
			scanf("%d",&b);
		//	printf("%d",mid);
			if(a=='i'){
				while(1){
					//printf("%d",mid);
					i++;
					if(b>random[mid]&&i<6){
						head=mid;
						mid=(head+tail)/2;
					//	printf("%d",mid);
						continue;
					}
					if(b<random[mid]&&i<6){
						tail=mid;
						mid=(head+tail)/2;
					//	printf("%d",mid);
						continue;	
					}
					if(b==random[mid]){
						printf("第%d個\n",mid);
						//printf("%d",mid);
						break;
					}
					if(i>=6){
					printf("找不到\n");
					//printf("%d",mid);
					i=0;
					mid=4;
					head=0;
					tail=9;
					break;
					}
					continue;        
				}
				i=0;
				mid=4;
				head=0;
				tail=9;
			//continue;	
			}
		if(a=='d'){
				while(1){
					//printf("%d",mid);
					i++;
					if(b>random[mid]&&i<6){
						tail=mid;
						mid=(head+tail)/2;
					//	printf("%d",mid);
						continue;
					}
					if(b<random[mid]&&i<6){
						head=mid;
						mid=(head+tail)/2;
					//	printf("%d",mid);
						continue;	
					}
					if(b==random[mid]){
						printf("第%d個\n",mid);
						//printf("%d",mid);
						break;
					}
					if(i>=6){
					printf("找不到\n");
					//printf("%d",mid);
					i=0;
					mid=4;
					head=0;
					tail=9;
					break;
					}
					continue;        
				}
				i=0;
				mid=4;
				head=0;
				tail=9; 
			//continue;	
			}
			printf("是否繼續?(是請打r,否請打q)\n");
			scanf("%c",&q);
			scanf("%c",&q);
			//printf("%c",q); 
		}
	}
