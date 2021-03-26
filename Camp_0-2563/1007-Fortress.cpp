#include<stdio.h>
int main (){
	int q = 20;
	while(q--){
		int n, m;
		scanf("%d %d", &n, &m);
		if(n > 4*m || 2*m > n){
			printf("0");
		}
		else{
			printf("%d", 2*m - n/2 + 1);
		}
		printf("\n");
	}
	return 0;
}
