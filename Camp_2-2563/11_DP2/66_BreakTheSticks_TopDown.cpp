/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * CENTER	: BUU
 * TASK		: Break The Sticks
 * ALGO		: Dynamic Programming (Top Down)
 * DATE		: 11 May 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#define dec(x,y) fixed << setprecision(y) << x   
#define all(x) (x).begin(), (x).end()
#define endl '\n'
#define int long long
using LL = long long;

int a[55], dp[55][55];

int divide(int l, int r, int n, int f){
	if(l == r){
		return 0;
	}
	if(dp[l][r]){
		return dp[l][r];
	}
	int nin = INT_MAX;
	for(int i=l; i<r; ++i){
		int now = n + divide(l, i, a[i]-f, f) + divide(i+1, r, n-a[i]+f, a[i]);
		nin = min(now, nin);
	}
	return dp[l][r] = nin;
}

void solve(){
	int p, n;
	cin >> n >> p;
	for(int i=0; i<p; ++i){
		cin >> a[i];
	}
	cout << divide(0, p, n, 0);
	return ;
}

int32_t main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int t=1;
//	cin >> t;
	while(t--){
		solve();
		cout << endl;
	}
	return 0;
}
