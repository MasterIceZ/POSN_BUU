#include<bits/stdc++.h>
using namespace std;

int dp[1111][1111];

int main (){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, w, h;
	cin >> w >> h >> n;
	for(int i=0; i<n; ++i){
		int x, y, a, b;
		cin >> x >> y >> a >> b;
		dp[y][x]++, dp[b+1][x]--, dp[y][a+1]--, dp[b+1][a+1]++;
	}	
	for(int i=1; i<=h; ++i){
		for(int j=1; j<=w; ++j){
			dp[i][j] += dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1];
		}
	}
	for(int i=1; i<=h; ++i){
		for(int j=1; j<=w; ++j){
			cout << (dp[i][j]%2);
		}
		cout<< endl;
	}

	return 0;
}
