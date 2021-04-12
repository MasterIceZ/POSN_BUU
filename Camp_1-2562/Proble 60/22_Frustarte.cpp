#include<bits/stdc++.h>
using namespace std;
int dp[100000];
int main (){
	int n,q,num,i,a,b;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&num);
		dp[i] = dp[i-1]+num; 
	}
	scanf("%d",&q);
	while(q--){
		scanf("%d %d",&a,&b);
		printf("%d\n",dp[b]-dp[a-1]);
	}
	
	return 0;
}
