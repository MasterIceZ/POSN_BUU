/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * CENTER	: BUU
 * TASK		: Equipped
 * ALGO		: Dynamic Programming
 * DATE		: 16 May 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#define dec(x,y) fixed << setprecision(y) << x   
#define all(x) (x).begin(), (x).end()
#define endl '\n'
using LL = long long;
void init();
int n, m;

int dp[333];

void solve(){
	int k;
	cin >> n >> k;
	int nax = 1 << k;
	for(int i=1; i<=nax; ++i){
		dp[i] = 1 << 30;
	}
	for(int i=0, w; i<n; ++i){
		cin >> w;
		int bin = 0;
		for(int j=0, r; j<k; ++j){
			cin >> r;
			bin *= 2;
			bin += r;
		}
		for(int j=0; j<=nax; ++j){
			dp[j|bin] = min(dp[j|bin], dp[j]+w);
		}
	}
	cout << dp[nax-1];
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
