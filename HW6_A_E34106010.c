#include <stdio.h>
#include <stdlib.h>
#include <time.h>

FILE *result;
int hare();
int tortoise();
void printposition(int movet,int moveh);

int main(){
int movet=1,moveh=1;
	
	result=fopen("result.dat","w");
	srand(time(NULL));

	printf("BANG!!!!!\n");
	fprintf(result,"BANG!!!!!\n");
	printf("AND THEY'RE OFF !!!!!\n");
	fprintf(result,"AND THEY'RE OFF !!!!!\n");

while(movet<70||moveh<70){
sleep(1);
	movet=movet+tortoise();
	moveh=moveh+hare();
	if(movet<1){
		movet=1;	
	}
	if(moveh<1){
		moveh=1;	
	}

printposition(movet,moveh);
if(movet>70||moveh>70){
break;
}
}
if(movet>moveh){
	printf("TORTOISE WINS!!! YAY!!!");
	fprintf(result,"TORTOISE WINS!!! YAY!!!");
}else if(moveh>movet){
	printf("HARE WINS!!! YUCH!!!");
	fprintf(result,"HARE WINS!!! YUCH!!!");
}else{
	printf("IT'S A TIE!!!");
	fprintf(result,"AND THEY'RE OFF !!!!!\n");
}
fclose(result);
return 0;
} 

int tortoise(){
int i,movet;


i=(rand()%10+1);
//printf("%d",i);
	if(i<=5)
	{
		movet=3;
	}else if(i>=6&&i<=7)
	{
		movet=-6;
	}else if(i>=8)
	{
		movet=1;
	}
//printf("%d",movet);
return movet;
}

int hare(){
int i,moveh;


i=(rand()%10+1);
//printf("%d",i);
	if(i<=2)
	{
		moveh=0;
	}else if(i>=3&&i<=4)
	{
		moveh=9;
	}else if(i==5)
	{
		moveh=-12;
	}else if(i>=6&&i<=8)
	{
		moveh=1;
	}else if(i>=9)
	{
		moveh=-2;
	}
//printf("%d",moveh);
return moveh;
}

void printposition(int movet,int moveh){
int m=0;
	if(movet==moveh){
		for(m=0;m<movet;m++){ 
		printf(" ");
		fprintf(result," ");} 
		
		printf("OUCH!!!\n");
		fprintf(result,"OUCH!!!\n");
	}else if(moveh>movet){
	for(m=0;m<movet;m++){
		printf(" ");
		fprintf(result," ");
	}
		printf("T");
		fprintf(result,"T");
	for(m=0;m<(moveh-movet);m++){
		printf(" ");
		fprintf(result," ");}
		printf("H\n");
		fprintf(result,"H\n");
	}else if(movet>moveh){
		for(m=0;m<moveh;m++){
		printf(" ");
		fprintf(result," ");}	
		printf("H");
		fprintf(result,"H");	
	
	for(m=0;m<(movet-moveh);m++){
		printf(" ");
		fprintf(result," ");}	
		printf("T\n");
		fprintf(result,"T\n");	
	}
}
