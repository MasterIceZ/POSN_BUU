#include<bits/stdc++.h>
using namespace std;
int a[100100100];
int main () {
	int i,cnt=0;
	long long num;
	scanf("%lld",&num);
	for(i=2;i<=num;i++){
		if(num==1){
			break;
		}
		for(;num%i==0;){
			a[cnt++] = i;
			num /= i; 
		}
	}
	for(i=0;i<cnt;i++){
		if(i==0)
			printf("%d ",a[i]);
		else if(a[i]==0)
			break;
		else
			printf("x %d ",a[i]);
	}
	return 0;
}
