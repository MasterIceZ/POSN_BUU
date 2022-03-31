/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		:
 * ALGO		:
 * DATE		:
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
int dp[MxN];

inline void solution(){
	int n;
	cin >> n;
	for(int i=1; i<=n; ++i){
		cin >> dp[i];
		dp[i] += dp[i - 1];
	}
	if(dp[n] % 2){
		cout << "NO";
		return ;
	}
	int middle = dp[n] / 2;
	for(int i=1; i<=n; ++i){
		if(dp[i] == middle){
			cout << i;
			return ;
		}
	}
	for(int i=0; i<n; ++i){
		int idx = lower_bound(dp + 1, dp + n + 1, middle + dp[i]) - dp;
		if(dp[idx] == middle + dp[i]){
			cout << i << " " << idx;
			return ;
		}
	}
	cout << "NO";
	return ;
}

signed main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);	
	int q = 1;
	cin >> q;
	while(q--){
		solution();
		cout << "\n";
	}
	return 0;
}
// https://github.com/MasterIceZ/archive/tree/main/cpp-template
