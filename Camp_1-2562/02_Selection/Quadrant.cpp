#include<stdio.h>
/*
		TASK: Quadrant
		AUTHOR: Ice
		SCHOOL: RYW
		LANG: C
*/
int main() {
	int a;
	scanf("%d",&a);
	double ag = a%360;
	if(a>=d0){
	
	if(ag>=1&&ag<=89)
	printf("1");
	else if(ag>=91&&ag<=179)
	printf("2");
	else if(ag>=181&&ag<=269)
	printf("3");
	else if(ag>=271&&ag<=359)
	printf("4");
	else if(ag==0||ag==180)
	printf("x-axis");
	else if(ag==90||ag==270)
	printf("y-axis");
}
	else if(a<0){
	
	if(ag>=-359&&ag<=-271)
	printf("1");
	else if(ag>=-269&&ag<=-181)
	printf("2");
	else if(ag>=-179&&ag<=-91)
	printf("3");
	else if(ag>=-89&&ag<=-1)
	printf("4");
	else if(ag==0||ag==-180)
	printf("x-axis");
	else if(ag==-90||ag==-270)
	printf("y-axis");
}
}
