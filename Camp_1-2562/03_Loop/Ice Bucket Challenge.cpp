#include<stdio.h>
/*
		TASK: 
		AUTHOR: Ice
		SCHOOL: RYW
		LANG: C
*/
int main (){
	int g,k,q,p=1,a=0;
	scanf("%d",&q);
	while(q--){
		a = 0,p = 1;
		scanf("%d %d",&g,&k);
		while(g-(p*100)>0){
			g -= 10;
			p = p+k;
			p -= 1;
			a++;
		}
		printf("%d",a);
	}

	return 0;
}
