/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Kuth Coin
 * ALGO		: Dynamic Programming, Knapsack
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

const int coins[] = {0, 1, 5, 10, 25, 50};
const int MOD = 1e6 + 3;
const int MxN = 100010;
int dp[MxN];

inline void solution(){
	int n;
	cin >> n;
	cout << dp[n];
	return ;
}

signed main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);	

	dp[0] = 1;
	for(int i=1; i<=5; ++i){
		for(int j=1; j<=100000; ++j){
			if(j - coins[i] < 0){
				continue;
			}
			dp[j] += dp[j - coins[i]];
			dp[j] %= MOD;
		}
	}

	int q = 1;
	cin >> q;
	while(q--){
		solution();
		cout << "\n";
	}
	return 0;
}
// https://github.com/MasterIceZ/archive/tree/main/cpp-template
