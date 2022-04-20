/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: C-Value
 * ALGO		: Dynamic Programming
 * DATE		: 15 Apr 2022
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

const int MxN = 1e6 + 10;
int a[MxN], dp[4][MxN];

inline void solution(){
	int n;
	cin >> n;
	for(int i=1; i<=n; ++i){
		cin >> a[i];
	}
	for(int i=1; i<=n; ++i){
		int modify = (i % 2 ? -1: 1);
		dp[0][i] = dp[0][i - 1] + modify * a[i];
		dp[1][i] = min(dp[0][i - 1] + modify * a[i], dp[1][i - 1] - modify * a[i]);
		dp[2][i] = min(dp[1][i - 1] - modify * a[i], dp[2][i - 1] + modify * a[i]); 
		
	}
	dbg(dp[0][n]);
	cout << min({dp[0][n], dp[1][n], dp[2][n]});
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
