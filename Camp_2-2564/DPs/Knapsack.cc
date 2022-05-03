/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: 0/1 Knapsack
 * ALGO		: Dynamic Programming
 * DATE		: 20 Apr 2022
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

int dp[110][10010];

inline void solution(){
	int n, m;
	cin >> n >> m;
	for(int i=1, v, w; i<=n; ++i){
		cin >> v >> w;
		memcpy(dp[i], dp[i - 1], sizeof(dp[i - 1]));
		for(int j=w; j<=m; ++j){
			dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w] + v);
		}
	}
	cout << dp[n][m];
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
