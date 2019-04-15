#include<stdio.h>
  int main(void) 
  {char a;
  label1:printf("請輸入y or n\n");
  scanf(" %c",&a);
  if(a=='y'||a=='n'||a=='N'||a=='Y'){
  
  
  printf("CORRECT!\n");
  
  return 0;}
  else if(a>47&&a<58){
  
  
  printf("你輸入了一個數字\n");
  
  goto label1;}
  else{
  
  printf("你輸入了一個英文\n");
  goto label1;
  
  
  printf("錯誤\n");
  goto label1;
  
  
  
  
  
  
  
  	
  }
  
   
  }
