/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Inversion
 * ALGO		: Dynamic Programming
 * DATE		: 13 Apr 2022
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

const int MOD = 2012;
const int MxN = 1010;
int dp[MxN][MxN];

inline void solution(){
	int n, k;
	cin >> n >> k;
	dp[0][0] = 1;
	for(int i=1; i<=n; ++i){
		dp[i][0] = 1;
		for(int j=1; j<=k; ++j){
			for(int state=1; state<=i; ++state){
				dp[i][j] += (j - state + 1 >= 0 ? dp[i - 1][j - state + 1]: 0);
				dp[i][j] %= MOD;
			}
		}
	}
	cout << dp[n][k];
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
