/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * CENTER	: BUU
 * TASK		:
 * ALGO		:
 * DATE		:
 * */
#include<bits/stdc++.h>
using namespace std;

#define dec(x,y) fixed << setprecision(y) << x   
#define all(x) (x).begin(), (x).end()
#define endl '\n'
#define int long long
using LL = long long;
void init();
int n, m;

int dp[222][222], a[222][222];

void solve(){
	int r, c;
	cin >> r >> c;
	for(int i=1; i<=r; ++i){
		for(int j=1; j<=c; ++j){
			cin >> a[i][j];
		}
	}
	for(int i=r; i>=1; --i){
		for(int j=1; j<=c; ++j){
			dp[i][j] = a[i][j] + max(dp[i+1][j], dp[i][j-1]);
		}
	}
	int tmp = dp[1][c];
//	for(int i=1; i<=r; ++i){
//		for(int j=1; j<=c; ++j){
//			cout << dp[i][j] << " ";
//		}
//		cout << endl;
//	}
	for(int i=r-1; i>=1; --i){
		dp[i][1] = a[i][1] + dp[i+1][1];
	}
	for(int j=1; j<=c; ++j){
		dp[r][j] = a[r][j] + dp[r][j-1];
	}
	for(int i=r-1; i>=1; --i){
		for(int j=2; j<=c; ++j){
			dp[i][j] = a[i][j] + min(dp[i+1][j], dp[i][j-1]);
		}
	}
	cout << tmp - dp[1][c];
	return ;
}

int32_t main(){
	init();
	int t=1;
//	cin >> t;
	while(t--){
		solve();
		cout << endl;
	}
	return 0;
}
void init(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	#ifdef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	return ;
}
