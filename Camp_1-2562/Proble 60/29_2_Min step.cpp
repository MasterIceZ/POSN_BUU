#include<bits/stdc++.h>
using namespace std;
int dp[1000002];
int main (){
	int q,n,i;
	scanf("%d",&q);
	while(q--){
		scanf("%d",&n);
		for(i=1;i<=n;i++){
			dp[i]=1<<30;
		}
		dp[n]=0;
		for(i=n;i>=1;i--){
			dp[i-1]=min(dp[i-1],dp[i]+1);
			if(i%2==0){
				dp[i/2] =min(dp[i/2],dp[i]+1); 
			}
			if(i%3==0){
				dp[i/3] =min(dp[i/3],dp[i]+1); 
			}
		}
		printf("%d",dp[1]);
	}
}
