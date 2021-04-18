#include<bits/stdc++.h>
using namespace std;

int dp[111];

int main (){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	if(n < 6){
		cout << "no" << endl;
		return 0;
	}
	dp[0] = 1;
	for(int i=6; i<=n; ++i){
		if(dp[i-6]){
			dp[i] = 1;
			cout << i << endl;
		}
		else if(i>=9 && dp[i-9] ){
			dp[i] = 1;
			cout << i << endl;
		}
		else if(i>=20 && dp[i-20]){
			dp[i] = 1;
			cout << i << endl;
		}
	}

	return 0;
}
