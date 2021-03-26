/*
 * TASK		: 62_Rotate
 * AUTHOR	: Hydrolyzed~
 * LANG 	: C 
 * SCHOOL	: RYW
 * */
#include<stdio.h>
#include<string.h>

char a[1111];

int main (){
	int t;
	scanf("%d",&t);
	while(t--){
		scanf(" %s",a+1);
		int n, k;
		scanf("%d %d", &n, &k);
		k %= n;
		int m = strlen(a+1)/n;
		for(int i=0;i<m;++i){
			for(int j = n*(i+1)-k+1;j<=n*(i+1);++j){
				printf("%c", a[j]);
			}
			for(int j = n*i+1; j<n*(i+1)-k+1;++j){
				printf("%c",a[j]);
			}
		}
		printf("\n");
	}
	return 0;
}
