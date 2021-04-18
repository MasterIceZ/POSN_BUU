#include<bits/stdc++.h>
using namespace std;

int dp[1000001];

int main (){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	for(int i=1; i<=n; ++i){
		cin >> dp[i];
	}
	int nax = INT_MIN;
	for(int i=n; i>=0; --i){
		nax = max(dp[i], nax);
		if(nax >= dp[i]){
			dp[i] = nax - dp[i];
		}
	}
	nax = INT_MIN;
	for(int i=1; i<=n; ++i){
		nax = max(dp[i], nax);
	}
	cout << nax << endl;

	return 0;
}
