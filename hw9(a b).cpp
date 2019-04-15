#include<stdio.h>
#include<string.h>
#define max_len 200
#define max_row 200
int sta[200]={0};
char **argv,keyword[200][200],mailword[1000][200];
FILE *spamkey,*email;
void key(void){
	int i=0;
	for(i=0;i<200;i++){
		fscanf(spamkey,"%s", keyword[i]);
		if(!strcmp(keyword[i],"-999")){
			break;
		}
	}
	fclose(spamkey);
}
void mail(void){
	int i=0;
	while(fscanf(email,"%s", mailword[i])!=EOF)	{
		i++;
	}
}
void compare(void){
	int i=0,j=0,k=0;
	for(i=0;i<200;i++,k++){
		if( ('a'<=keyword[i][0]&&keyword[i][0]<='z') || ('A'<=keyword[i][0]&&keyword[i][0]<='Z') ){
			//printf("g");
			for(j=0;j<1000;j++){
			//	printf("%s/%s\n",keyword[i],mailword[j]);
				if( (strcmp(keyword[i],mailword[j])) ==0){
					sta[k]++;
				//	printf("g");
				}
			}
		}
	}
}
int main(int argc,char **argv){
	int i=0,k=0,trash=0;
	if( (spamkey=fopen (*(argv+1) , "r")) == NULL)
		printf("error opening file\n");
	if( (email=fopen (*(argv+2) , "r")) == NULL)
		printf("error opening file1\n");
	printf("spamkey in the mail\n");
	key();
	mail();
	compare();
//	for(i=0;i<200;i++)
//	printf("%s\n",mailword[i]);
//	for(i=0;i<200;i++)
//	printf("%d",sta[i]);
	for(k=0;k<200;k++){
		if( (sta[k]!=0) && (sta[k]<=100)){
			printf("%10s",keyword[k]);
			printf(":");
			printf("%d",sta[k]);
			printf("\n");
		}
	}
	for(i=0;i<200;i++){
		trash=trash+sta[i];
	}
	if(trash>10){
		printf("this is a spam");
	}
	else{
		printf("this is a normal email");
	}
}
