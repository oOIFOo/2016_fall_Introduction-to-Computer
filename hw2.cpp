#include<stdio.h>
  int main(void) 
  {char a;
  label1:printf("�п�Jy or n\n");
  scanf(" %c",&a);
  if(a=='y'||a=='n'||a=='N'||a=='Y'){
  
  
  printf("CORRECT!\n");
  
  return 0;}
  else if(a>47&&a<58){
  
  
  printf("�A��J�F�@�ӼƦr\n");
  
  goto label1;}
  else{
  
  printf("�A��J�F�@�ӭ^��\n");
  goto label1;
  
  
  printf("���~\n");
  goto label1;
  
  
  
  
  
  
  
  	
  }
  
   
  }
