/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Luxurious Hotel
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

const int MxN = 100010;
ll a[MxN], qs[MxN], dp[2][MxN];

inline void solution(){
	int n, k, p;
	cin >> n >> k >> p;
	for(int i=1; i<=n; ++i){
		cin >> a[i];
		qs[i] = qs[i - 1] + a[i];
	}
	for(int state=1; state<=k; ++state){
		for(int i=1; i<=n; ++i){
			int last = max(0, i - p);
			dp[state % 2][i] = max(dp[state % 2][i - 1], dp[(state + 1) % 2][last] + qs[i] - qs[last]);
		}
	}
	cout << dp[k % 2][n];
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
