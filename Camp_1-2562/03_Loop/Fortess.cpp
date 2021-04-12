#include<stdio.h>
/*
		TASK: 
		AUTHOR: Ice
		SCHOOL: RYW
		LANG: C
*/
int main (){
	int i=1,m,n,x,z;
	
	while(i<21){
	scanf("%d %d",&m,&n);
		if(2*n>m){
			printf("0\n");
		}
		else if(m>4*n){
			printf("0\n");
		}
		else{
			x = m/2 - n;
			z = n - x;
			z += 1;
			printf("%d\n",z) ;
		}
		i++;
	}
	return 0;
}
