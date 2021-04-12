#include<bits/stdc++.h>
using namespace std;
int dp[505][505];
int main(){
	int n,m,i,j,ans=1<<30;
	scanf("%d %d",&n,&m);	
	for(i=0;i<=n+1;i++){
		for(j=0;j<=m+1;j++){
			dp[i][j]=1<<30;
		}
	}
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			scanf("%d",&dp[i][j]);
		}
	}
	for(i=n-1;i>=1;i--){
		for(j=1;j<=m;j++){
		dp[i][j]=min(dp[i+1][j-1],min(dp[i+1][j],dp[i+1][j+1]))+dp[i][j];	
		}
	}
	for(j=1;j<=m;j++){
		ans=min(ans,dp[1][j]);
	}
	printf("%d",ans);
	return 0;
}
