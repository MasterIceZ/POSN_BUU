/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * CENTER	: BUU
 * TASK		: Maxium Sub Array
 * ALGO		: Dynamic Programmming
 * DATE		: 11 May 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#define dec(x,y) fixed << setprecision(y) << x   
#define all(x) (x).begin(), (x).end()
#define endl '\n'
#define int long long
using LL = long long;

int n, m;
int dp[555][555];

void solve2(){
	cin >> n;
	int nax = -1;
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=n; ++j){
			cin >> dp[i][j];
			nax = max(nax, dp[i][j]);
			dp[i][j] += dp[i][j-1];
		}
	}
	int mic = -1;
//	int cnt = 0;
	for(int i=1; i<=n; ++i){
		for(int j=i; j<=n; ++j){
			int local = 0;
			for(int k=1; k<=n; ++k){
				if(local + dp[k][j] - dp[k][i-1] >= 0){
					local += dp[k][j] - dp[k][i-1];
				}
				else{
					local = 0;
				}
//				cerr << "NOW : " << cnt++ << endl;
				mic = max(local, mic);
			}
		}
	}
	cout << (nax<0 ? nax: mic);
}

void solve(){
	cin >> n;
	int ans = -1e9;
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=n; ++j){
			cin >> dp[i][j];
			ans = max(ans, dp[i][j]);
			dp[i][j] += dp[i-1][j];
		}
	}
	for(int k=1; k<=n; ++k){
		for(int i=1; i<=n-k+1; ++i){
			int now = 0;
			for(int j=1; j<=n; ++j){
				now += dp[i + k - 1][j] - dp[i - 1][j];
				if(now < 0){
					now = dp[i + k - 1][j]- dp[i-1][j];
				}
				ans = max(ans, now);
			}
		}
	}
	cout << ans;
	return ;
}

int32_t main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int t=1;
//	cin >> t;
	while(t--){
		solve2();
		cout << endl;
	}
	return 0;
}
