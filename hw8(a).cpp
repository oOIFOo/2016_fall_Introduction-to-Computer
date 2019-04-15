#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<windows.h>
int t[10]={3,3,3,3,3,-6,-6,1,1,1},h[10]={0,0,9,9,-12,1,1,1,-2,-2},tor=0,hare=0,t_path=0,h_path=0,tor_next=0,hare_next=0,goal=1;
void next(void){
	srand(time(NULL));
	t_path=(rand() % 10);
	h_path=(rand() % 10);
	tor=tor+t[t_path];
	hare=hare+h[h_path];
		if(tor<0){
			tor=0;	
		}
		if(hare<0){
			hare=0;
		}
		if(hare>24)
		hare=24;
		if(tor>24)
		tor=24;
}
void print_tplayer(void){
	int i=0;
		for(i=0;i<tor;i++){
			printf("   ");
		}
		printf("  t");
}
void print_hplayer(void){
	int i=0;
		for(i=0;i<hare;i++){
			printf("   ");
		}
		printf("  h");
}
void map(void){
	int i;
		for(i=1;i<=25;i++){
		printf("%3d",i);
		}
}
void print_tdoing(void){
	printf("t\t");
	if(t[t_path]==3){
		printf("Fast plod!!\n");
	}
	if(t[t_path]==-6){
		printf("Slip!!\n");
	}
	if(t[t_path]==1){
		printf("Slow plod!\n");
	}
}
void print_hdoing(void){
	printf("h\t");
	if(h[h_path]==0){
		printf("sleep~~\n");
	}
	if(h[h_path]==9){
		printf("Big hop!!\n");
	}
	if(h[h_path]==-12){
		printf("Big slip!!\n");
	}
	if(h[h_path]==1){
		printf("Small hop!\n");
	}
	if(h[h_path]==-2){
		printf("Small slip!\n");
	}
}
void print_win(void){
	if(tor>=24&&hare>=24){
		printf("\n");
		printf("It¡¦s a tie\n");
		printf("\n");
		goal=0;
	}
	if(tor>=24){
		printf("\n");
		printf("TORTOISE WINS!!! YAY!!!\n");
		printf("\n");
		goal=0;
	}
	if(hare>=24){
		printf("\n");
		printf("Hare wins. Yuch\n");
		printf("\n");
		goal=0;
	}
}
void runinto(void){
	if(tor==hare){
		printf("\n");
		printf("OUCH!!!\n");
		printf("\n");
	}
}
void start(void){
	printf("¡¨BANG!!! AND THEY¡¦RE OFF!!!!!\n");
}
void run(void){
	system("cls");
	next();
	print_hdoing();
	print_tdoing();
	print_win();
	runinto();
	map();
	printf("\n");
	print_hplayer();
	printf("\n");
	print_tplayer();
	printf("\n");
	system("pause");
	if(goal==0)
		return;
	run();
}
int main(void){
	start();
	map();
	printf("\n");
	print_hplayer();
	printf("\n");
	print_tplayer();
	printf("\n");
	system("pause");
	run();
}
