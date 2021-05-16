/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * CENTER	: BUU
 * TASK		: Pot
 * ALGO		: Dynamic Programming
 * DATE		: 16 May 2021
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

const int MOD = 2009;

int dp[100100];

void solve(){
	int n, k;
	cin >> n >> k;
	dp[0] = 1;
	for(int i=1; i<=n; ++i){
		dp[i] += dp[i-1];
		dp[i] %= MOD;
		dp[i] += dp[i-1];
		dp[i] %= MOD;
		if(i > k){
			dp[i] -= dp[i-k-1];
		}
		dp[i] += MOD;
		dp[i] %= MOD;
	}
	cout << (dp[n] - dp[n-1] + MOD)%MOD;
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
