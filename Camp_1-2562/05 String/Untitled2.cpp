#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>

int main (){
	srand(time(NULL));
	int a = rand()%11;
	int x,time=0,i=0;
	while(i<5){
		scanf("%d",&x);
		if(x==a){
			printf("You got it.");
			break;
		}
		else if(x!=a){
			time++;
			if(time>=5){
				printf("You failed.Please try again.");
			}
		}
		i++;
	}
}
