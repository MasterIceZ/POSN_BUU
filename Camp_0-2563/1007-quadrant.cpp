#include<stdio.h>
#include<math.h>
int main (){
	int a;
	scanf("%d", &a);
	if(a >= 0){
		a %= 360;
		if(a == 0 || a == 180){
			printf("x-axis");
		}
		else if(a == 270 || a == 90){
			printf("y-axis");
		}
		else if(a < 90){
			printf("1");
		}
		else if(a <180){
			printf("2");
		}
		else if(a<270){
			printf("3");
		}
		else{
			printf("4");
		}
			
	}
	else{
		a = -a;
		a %= 360;
		if(a ==0 || a == 180){
			printf("x-axis");
		}
		else if(a == 270 || a == 90){
			printf("y-axis");
		}
		else if(a < 90){
			printf("4");
		}
		else if(a <180){
			printf("3");
		}
		else if(a<270){
			printf("2");
		}
		else{
			printf("1");
		}
	}
	return 0;
}
