#include<bits/stdc++.h>
using namespace std;

int dp[1000001];

int main (){
	ios::sync_with_stdio(0);
	cin.tie(0);

	for(int i=2; i<=1000000; ++i){
		dp[i] = dp[i-1] + 1;
		if(i%2==0){
			dp[i] = min(dp[i], dp[i/2] + 1);
		}
		if(i%3==0){
			dp[i] = min(dp[i], dp[i/3] + 1);
		}
	}

	int q;
	cin >> q;
	while(q--){
		int n;
		cin >> n;
		cout << dp[n] << endl;
	}	

	return 0;
}
