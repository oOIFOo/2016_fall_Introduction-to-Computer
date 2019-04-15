#include<stdio.h>
#include<stdlib.h>
char **argv;
struct input_0{
	int name;
	char type;
	int in;
	int out;
};
struct point_0{
	struct input_0 *point;
	int name;
};
point_0 point[500];
input_0 input[500];
FILE *pc;
void read_pc(void){
	char star, garbage;
	int num = 0 , i = 0 , j = 0 , k = 0;
	for( fscanf( pc ,"%c", &star) = '*' );
	num = atoi(star);
	input[0].name = num;
	for( i=0 ; ( fscanf( pc ,"%s", &garbage) )!= EOF ; i++){
		fscanf( pc ,"%c", & input.type);
		fscanf( pc ,"%s", &garbage );
		fscanf( pc ,"%d", & input.out);
		fscanf( pc ,"%d", & input.in);
		fscanf( pc ,"%s", &garbage );
		if( input[i].out != 1 ){
			fscanf( pc ,"%s", &garbage );
			fscanf( pc ,"%d", &point[j].name );
			fscanf( pc ,"%s", &garbage );
			fscanf( pc ,"%s", &garbage );
			fscanf( pc ,"%d", &k );
		}
	}
}
int main(int argc , char **argv){
	pc = fopen( *(argv+1) , "r" );
}
