#include<bits/stdc++.h>
using namespace std;
int dp[110]={1};
int main () {
	int i,n;
	for(i=6;i<=100;i++){
		if(i>=6 && dp[i-6]) dp[i] = 1;
		if(i>=9 && dp[i-9]) dp[i] = 1;
		if(i>=20 && dp[i-20]) dp[i] = 1;
	}
	scanf("%d",&n);
	if(n<6){
		printf("no\n");
		return 0;
	}
	for(i=6;i<=n;i++){
		if(dp[i]==1)
			printf("%d\n",i);
	}
	return 0;
}
