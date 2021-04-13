/*
 *   TASK  	: ArrayPrac
 *   AUTHOR	: Hydrolyzed~
 *   LANG  	: C
 *   SCHOOL	: RYW
 * */

#include<stdio.h>

int a[1010];

int main(){
	int n;
	scanf("%d", &n);
	for(int i=0;i<n;++i){
		scanf("%d", &a[i]);
	}
	int k, cnt = 0;
	scanf("%d" ,&k);
	for(int i=0;i<n;++i){
		if(a[i] == k){
			cnt++;
		}
	}
	for(int i=n-1;i>=0;--i){
		printf("%d ", a[i]);
	}
	printf("\n%d",cnt);
	printf("\n");
	return 0;
}
