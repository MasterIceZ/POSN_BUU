#include<bits/stdc++.h>
using namespace std;

#define endl '\n'

int dp[1010][1010];

int main (){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int x, y, k;
	cin >> x >> y >> k;
	while(k--){
		int a, b;
		cin >> a >> b;
		dp[a+1][b+1] = -1;
	}
	x++, y++;
	dp[1][0] = 1;
	for(int i=1; i<=x; ++i){
		for(int j=1; j<=y; ++j){
			if(dp[i][j] == -1){
				dp[i][j] = 0;
			}
			else{
				dp[i][j] = dp[i-1][j] + dp[i][j-1];
				dp[i][j] %= 1000000;
			}
		}
	}
	cout << dp[x][y] << endl;
	return 0;
}
