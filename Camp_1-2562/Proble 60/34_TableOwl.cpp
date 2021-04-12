#include<bits/stdc++.h>
using namespace std;
int dp[500][500];
int main (){
	int n,m,i,j,ans=0;
	scanf("%d %d",&n,&m);
	for(i=0;i<=n+1;i++){
		for(j=0;j<=m+1;j++){
			dp[i][j]=1<<30;
		}
	}
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++)
			scanf("%d",&dp[i][j]);
	}
	for(i=n-1;i>=1;i--){
		for(j=1;j<=m;j++){
			dp[i][j]=min(dp[i+1][j-1],min(dp[i+1][j],dp[i+1][j+1]))+dp[i][j];
		}
	}
	for(j=1;j<=m;j++){
		ans = min(ans,dp[1][j]);
	}
	printf("%d",ans);
	return 0;
}
/*
5 6 
3 6 1 7 2 3
4 7 9 5 2 1
3 3 2 9 9 8
7 5 7 5 8 9
2 4 1 3 7 1 

*/
