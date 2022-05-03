/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: toi8_schedule
 * ALGO		: Dynamic Programming
 * DATE		: 21 Apr 2022
 * */

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>

#ifndef _DEBUG
// @==== Libary ====@ //

// @================@ //
#endif

using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;

template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update> ;

// @=== Debugger ===@ //
#ifdef _DEBUG
#include "debug.hpp"
#else
#define dbg(...) 0
#endif
// @================@ //

using ll = long long;
using pii = pair<int, int> ;

const int MxN = 1010;
int k, a[MxN], b[MxN];
pii dp[MxN][MxN];

pii operator + (const pii a, const pii b){
	if(a.second + b.second > k){
		return make_pair(a.first + 1, b.second);
	}
	return make_pair(a.first, a.second + b.second);
}

inline void solution(){
	int n;
	cin >> k >> n;
	for(int i=1; i<=n; ++i){
		cin >> a[i];
	}
	for(int i=1; i<=n; ++i){
		cin >> b[i];
	}
	dp[0][0] = make_pair(1, 0);
	for(int i=1; i<=n; ++i){
		dp[i][0] = dp[i - 1][0] + make_pair(0, a[i]);
		dp[0][i] = dp[0][i - 1] + make_pair(0, b[i]);
	}
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=n; ++j){
			dp[i][j] = min(dp[i - 1][j] + make_pair(0, a[i]), dp[i][j - 1] + make_pair(0, b[j]));
		}
	}
	cout << dp[n][n].first << "\n" << dp[n][n].second ;
	return ;
}

signed main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);	
	int q = 1;
//	cin >> q;
	while(q--){
		solution();
		cout << "\n";
	}
	return 0;
}
// https://github.com/MasterIceZ/archive/tree/main/cpp-template
