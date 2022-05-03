/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Jimmy Bond
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

const int MxN = 22;
double a[MxN][MxN], dp[1 << 20];

inline void solution(){
	int n;
	cin >> n;
	for(int i=0; i<n; ++i){
		for(int j=0; j<n; ++j){
			cin >> a[i][j];
			a[i][j] /= 100.0;
		}
	}
	dp[0] = 1.0;
	for(int state=0; state<(1 << n); ++state){
		int cnt = __builtin_popcount(state) - 1;
		for(int i=0; i<n; ++i){
			if(!(state & (1 << i))){
				continue;
			}
			dp[state] = max(dp[state], dp[state ^ (1 << i)] * a[cnt][i]);
		}
	}
	cout << fixed << setprecision(2) << 100 * dp[(1 << n) - 1];
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
