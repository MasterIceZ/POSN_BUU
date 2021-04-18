#include<bits/stdc++.h>
using namespace std;

int dp[1011][1011];

int main (){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=i; ++j){
			cin >> dp[i][j];
		}
	}
	for(int i=n-1; i>=1; --i){
		for(int j=1; j<=i; ++j){
			dp[i][j] += max(dp[i+1][j], dp[i+1][j+1]);
		}
	}
	cout << dp[1][1] << endl;
	return 0;
}
