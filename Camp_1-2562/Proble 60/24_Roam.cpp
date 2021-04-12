#include<bits/stdc++.h>
using namespace std;
int dp[100100];
int main (){
	int n,m,a,b,q,k,i;
	scanf("%d %d",&n,&m);
	while(m--){
		scanf("%d %d",&a,&b);
		dp[a]++,dp[b+1]--;
	}
	for(i=0;i<=n;i++){
		dp[i] += dp[i-1];
	}
	scanf("%d",&q);
	while(q--){
		scanf("%d",&k);
		printf("%d\n",dp[k]);
	}
	return 0;
}
