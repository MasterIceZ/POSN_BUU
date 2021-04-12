#include<stdio.h>
/*
		TASK: 
		AUTHOR: Ice
		SCHOOL: RYW
		LANG: C
*/
int main (){
	int g,k,q,p=0,a;
	scanf("%d",&q);
	while(q--){
		scanf("%d %d",&g,&k);
		if(g>100){
			while(a<g)
			g %= 100;
			g = g-(10);
			p += g;
		}
		else{
			p = 0;
		}	
		
	printf("%d",p);
	}

	return 0;
}
