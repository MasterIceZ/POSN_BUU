/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Equipped
 * ALGO		: Dynamic Programming, Bitmasks
 * DATE		: 26 Apr 2022
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

int dp[1 << 8];

inline void solution(){
	int n, k, x, c;
	cin >> n >> k;
	memset(dp, 0x3f, sizeof dp);
	dp[0] = 0;
	for(int i=1; i<=n; ++i){
		cin >> c;
		int state = 0;
		for(int j=0; j<k; ++j){
			cin >> x;
			if(!x){
				continue;
			}
			state |= (1 << j);
		}
		for(int j=0; j<(1 << k); ++j){
			dp[j | state] = min(dp[j | state], dp[j] + c);
		}
	}
	cout << dp[(1 << k) - 1];
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
