#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max_len 200
#define max_row 200
int sta[45]={0},total=0,count=0;
float weig[45]={0};
char **argv,keyword[45][200],mailword[1000][200],wei[45][10],word[150][20],imail[1000][200];
FILE *spamkey,*email;
void change(void){
	int i=0,tran[45];
	char a;
	for(i=0;i<500;i++){
		if(( ('a'<=imail[i][1]&&imail[i][1]<='z') || ( ('A'<=imail[i][1]) && (imail[i][1]<='Z') ) || ('0'<=imail[i][1]&&imail[i][1]<='9'))){
			total++;
		}
	}
	for(i=0;i<45;i++){
		
		tran[i]=atoi(wei[i]);
//		printf("%s-->%d\n",wei[i],tran[i]);
	}
	for(i=0;i<45;i++){
		weig[i]=(float)tran[i]/(float)total;
//		printf("%d/%d=%f\n",tran[i],total,weig[i]);
	}
}
void rewrite(void){
	int i,j;
	char a;
	for(i=0;i<count;i++){
		for(j=0;j<200;j++){
			a=mailword[i][j];
			if( !( ('a'<=a&&a<='z') || ( ('A'<=a) && (a<='Z') ) || ('0'<=a&&a<='9'))){
				mailword[i][j]=' ';
				
			}
		}
	}
	
	for(i=0;i<1000;i++){
		for(j=0;j<200;j++){
			a=mailword[i][j];
			if(a==' '){
				break;
			}
			imail[i][j]=a;
		}
	}
}
void key(void){
	int i=0,j=0;
	for(i=0;i<=150;i++){
		fscanf(spamkey,"%s",word[i]);
		if( ('a'<=word[i][0]&&word[i][0]<='z') || ('A'<=word[i][0]&&word[i][0]<='Z') ){
		strcpy(keyword[j],word[i]);
		j++;
		}
		if( (!strcmp(word[i],"-999")) ){			
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
	count=i;
	fclose(email);
}
void weight(void){
	int i=0,j=0;
	for(i=0;i<=150;i++){
		fscanf(spamkey,"%s", word[i]);
		if( ('0'<=word[i][0]&&word[i][0]<='9') ){
			strcpy(wei[j],word[i]);
//			printf("%s/",word[j]);
//			printf("%s/",wei[j]);
			j++;
		}
		if( (!strcmp(word[i],"-999")) ){
			break;
		}
	}
	fclose(spamkey);
}
void compare(void){
	int i=0,j=0,k=0;
	for(i=0;i<200;i++,k++){
		if( ('a'<=keyword[i][0]&&keyword[i][0]<='z') || ('A'<=keyword[i][0]&&keyword[i][0]<='Z') ){
			for(j=0;j<1000;j++){
				if( (strcmp(keyword[i],imail[j])) == 0){
					sta[k]++;
				}
			}
		}
	}
}
int main(int argc,char **argv){
	int i=0,k=0;
	float trash=0;
	if( (spamkey=fopen (*(argv+1) , "r")) == NULL)
		printf("error opening file\n");
	if( (email=fopen (*(argv+2) , "r")) == NULL)
		printf("error opening file1\n");
	printf("spamkey in the mail\n");
	mail();
	key();
	rewrite();
	compare();
	weight();
	change();
	//printf("%d",total); 
//	for(i=0;i<45;i++){
//	printf("%f\n",weig[i]);
//	}
	for(k=0;k<45;k++){
		
//	printf("d");
		if( (sta[k]!=0)  && (sta[k]<=100)){
		//	printf("d");
			printf("%10s",keyword[k]);
			printf(":");
			printf("%d",sta[k]);
			printf("\n");
		}
	}
//	system("pause");
	for(i=0;i<45;i++){
		trash=trash+sta[i]*weig[i];
	}
//	printf("%f",trash);
	if(trash>2){
		printf("this is a spam");
	}
	else{
		printf("this is a normal email");
	}
}
