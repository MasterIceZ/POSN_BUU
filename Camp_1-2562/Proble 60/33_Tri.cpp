#include<bits/stdc++.h>
using namespace std;
int dp[1010][1010];
int main () {
	int i,j,n;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		for(j=1;j<=i;j++){
			scanf("%d",&dp[i][j]);
		}
	}
	for(i=n-1;i>=1;i--){
		for(j=1;j<=i;j++)
		{
			dp[i][j] += max(dp[i+1][j],dp[i+1][j+1]);
		}
	}
	printf("%d",dp[1][1]);
	return 0;
}
