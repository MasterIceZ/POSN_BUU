#include<bits/stdc++.h>
using namespace std;

int dp[1111][1111];

int main (){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	int cnt = 0;
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=m; ++j){
			char s;
			cin >> s;
			if(s != '#'){
				dp[i][j] = min({dp[i][j-1], dp[i-1][j], dp[i-1][j-1]})+1;
				cnt = max(dp[i][j], cnt);
			}
		}
	}
	cout << cnt << endl;
	return 0;
}
