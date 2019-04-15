#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<windows.h>
int t[10]={3,3,3,3,3,-6,-6,1,1,1},h[10]={0,0,9,9,-12,1,1,1,-2,-2},tor=0,hare=0,t_path=0,h_path=0,tor_next=0,hare_next=0,goal=1,land[60]={0},hmove,tmove,hcount=0,stop,hfor=0,water=0;
void generate_river(void){
	int r=0,i=0;
	srand(time(NULL));
	for(i=0;i<12;){
		r=(rand() % 60);
		if(land[r]==0){
			land[r]=1;
			i++;
		}
	}
}
void generate_forest(void){
	int f=0,i=0;
	srand(time(NULL));
	for(i=0;i<12;){
		f=(rand() % 60);
		if(land[f]==0){
			land[f]=2;
			i++;
		}
	}
}
void generate_slope(void){
	int s=0,i=0;
	srand(time(NULL));
	for(i=0;i<36;){
		s=(rand() % 60);
		if(land[s]==0){
			land[s]=3;
			i++;
		}
	}
}
void hare_move_way(void){
	water--;
	if(hcount==2){
		hmove=0;
		hcount=0;
	}
	if(stop==1){
		hmove=0;
		stop=0;
	}
	if(h[h_path]==9){
		hcount++;
	}
	if(h[h_path]!=9){
		hcount=0;
	}
	if(land[hare]==1){
		hmove=hmove/2;
		water=2;
	}
	if(water==1){
		hmove=hmove/2;
	}
	if(land[hare]==2&&hfor==0){
		hmove=0;
		hcount=0;
		hfor=1;
	}
	else{
		hfor=0;
	}
}
void tortise_move_way(void){
	if(land[tor]==1){
		tmove=3;
	}
}
void print_land(void){
	int i=0;
	for(i=0;i<26;i++){
		if(land[i]==1){
			printf("  R");
		}
		if(land[i]==2){
			printf("  F");
		}
		if(land[i]==3){
			printf("  S");
		}
	}
	printf("\n");
}
void print_land1(void){
	int i=25;
	for(i=26;i<52;i++){
		if(land[i]==1){
			printf("  R");
		}
		if(land[i]==2){
			printf("  F");
		}
		if(land[i]==3){
			printf("  S");
		}
	}
	printf("\n");
}
void next(void){
	srand(time(NULL));
	t_path=(rand() % 10);
	h_path=(rand() % 10);
	tmove=t[t_path];
	hmove=h[h_path];
	tortise_move_way();
	hare_move_way();
	tor=tor+tmove;
	hare=hare+hmove;
		if(tor<0){
			tor=0;	
		}
		if(hare<0){
			hare=0;
		}
		if(hare>59)
		hare=59;
		if(tor>59)
		tor=59;
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
	if(hare<=26||tor<=26){
		for(i=1;i<=26;i++){
		printf("%3d",i);
		}
		printf("\n");
		print_land();
		if(tor<=26){
		for(i=0;i<tor;i++){
			printf("   ");
		}
		printf("  t");
		printf("\n");
	}
	if(hare<=26){
		for(i=0;i<hare;i++){
			printf("   ");
		}
		printf("  h");
		printf("\n");
	}
}
	if( (26<hare&&hare<=52) || (26<tor&&tor<=52)){
		for(i=27;i<=52;i++){
		printf("%3d",i);
	}
	printf("\n");
	print_land1();
	if((26<tor&&tor<=52)){
	for(i=25;i<tor;i++){
			printf("   ");
		}
		printf("  t");
		printf("\n");
	}
	if((26<hare&&hare<=52)){
		for(i=25;i<hare;i++){
			printf("   ");
		}
		printf("  h");
		printf("\n");
	}
}	
	if(hare>52||tor>52){
	for(i=53;i<=60;i++){
		printf("%3d",i);
		}
		printf("\n");
	for(i=52;i<61;i++){
		if(land[i]==1){
			printf("  R");
		}
		if(land[i]==2){
			printf("  F");
		}
		if(land[i]==3){
			printf("  S");
		}
	}
	printf("\n");
	if(tor>53){
	for(i=52;i<tor;i++){
			printf("   ");
		}
		printf("  t");
		printf("\n");
	}
	if(hare>53){
		for(i=52;i<hare;i++){
			printf("   ");
		}
		printf("  h");
		printf("\n");
	}
}
}
void print_tdoing(void){
	printf("tortise\t");
	if(tmove==3){
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
	printf("hare\t");
	if(hmove==0){
		printf("sleep~~\n");
	}
	if(h[h_path]==9&&hmove!=0){
		printf("Big hop!!\n");
	}
	if(h[h_path]==-12&&hmove!=0){
		printf("Big slip!!\n");
	}
	if(h[h_path]==1&&hmove!=0){
		printf("Small hop!\n");
	}
	if(h[h_path]==-2&&hmove!=0){
		printf("Small slip!\n");
	}
}
void print_win(void){
	if(tor>=59&&hare>=59){
		printf("\n");
		printf("It¡¦s a tie\n");
		printf("\n");
		goal=0;
	}
	if(tor>=59){
		printf("\n");
		printf("TORTOISE WINS!!! YAY!!!\n");
		printf("\n");
		goal=0;
	}
	if(hare>=59){
		printf("\n");
		printf("Hare wins. Yuch\n");
		printf("\n");
		goal=0;
	}
}
void runinto(void){
	if(tor==hare){
		printf("\n");
		printf("HURT!!!\n");
		printf("\n");
		stop=1;
	}
}
void start(void){
	printf("¡¨BANG!!! AND THEY¡¦RE OFF!!!!!\n");
}
void run(void){
	//system("cls");
	next();
	print_hdoing();
	print_tdoing();
	print_win();
	runinto();
	map();
//	printf("\n");
//	print_hplayer();
//	printf("\n");
///	print_tplayer();
//	printf("\n");
	system("pause");
	if(goal==0)
		return;
	run();
}
int main(void){
	generate_river();
	generate_forest();
	generate_slope();
	start();
	map();
//	printf("\n");
//	print_hplayer();
//	printf("\n");
//	print_tplayer();
//	printf("\n");
	system("pause");
	run();
}
