#include<bits/stdc++.h>
using namespace std;
int dp[1010][1010];
int main () {
	int i,j,r,c,ma=-1;
	char a;
	scanf("%d %d",&r,&c);
	for(i=1;i<=r;i++){
		for(j=1;j<=c;j++){
			scanf(" %c",&a);
			if(a=='#')	dp[i][j]=0;
			else dp[i][j]=min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]))+1;
			ma = max(ma,dp[i][j]);
		}
	}
	printf("%d",ma);
	return 0;
}
