#include<stdio.h>
#include<math.h>

int main (){
	int q;
	scanf("%d",&q);
	while(q--){
		double x1,x2,y1,y2,r1,r2;
		scanf("%lf %lf %lf %lf %lf %lf",&x1,&y1,&r1,&x2,&y2,&r2);
		double dist = sqrt(pow(x1-x2, 2) + pow(y1-y2,2));
		if(dist > r1+r2){
			printf("None");
		}	
		else if(x1 == x2 && y1 == y2 && r1 == r2){
			printf("More");
		}
		else if(dist < r1 && dist+r2 == r1){
			printf("One");
		}
		else if(dist < r2 && dist+r1 == r2){
			printf("One");
		}
		else if(dist < r1 && dist+r2 < r1){
			printf("None");
		}
		else if(dist < r2 && dist+r1 < r2){
			printf("None");
		}
		else if(dist < r1+r2){
			printf("More");
		}
		else if(dist == r1+r2 || dist+r1 == r2 || dist+r2 == r1){
			printf("One");
		}
		else{
			printf("None");
		}
		printf("\n");
	}
	return 0;
}
