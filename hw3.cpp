#include <stdio.h>
#include<iostream>
#include <string.h>
	int main(){
	int n=0,g=0,a=0;
	int garbage=0;
	char c;
	printf("��J�Ʀr:\n");
		while(1){
			c=getchar();
			if((c==' ')||(c=='\n') ){
				if(garbage==1){
					g++;
					//printf("g\n");
				}
				else{
					n++;
					//printf("n\n");
				}
				garbage=0;
				
				if(c == '\n'){ 
				    //printf("y\n");
					//printf("%c",c); 
					break;
					}
				continue;
				}
				
				if((c<='9')&&(c>='0')){
					continue;
				}else{
					if(a==0){
						printf("��l�U����");
						printf("%c",c);
						a++;
					}
					else{
					printf("%c",c);
					garbage=1;
					}
				}
				continue;
				}
			//system("pause");
	//	}
					 
	if(g>0){
		printf("\n");
		printf("�@��J�F%d�ӼƦr,%d�өU��\n",n,g);
	}
	if(g==0)
	printf("��J�F%d�ӼƦr",n);
			system("pause");
			system("cls");
	} 

	
		
