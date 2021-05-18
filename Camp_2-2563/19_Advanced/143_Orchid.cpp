/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * CENTER	: BUU
 * TASK		: Orchid
 * ALGO		: Dynamic Programming
 * DATE		: 17 May 2021
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

int dp[1000100];

void solve(){
	cin >> n;
	vector<int>v(n);
	for(auto &x: v){
		cin >> x;
	}
	int sz = 0;
	for(int i=0; i<n; ++i){
		int idx = upper_bound(dp, dp+sz, v[i]) - dp;
		dp[idx] = v[i];
		if(idx == sz){
			sz++;
		}
	}
	cout << n-sz;
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
