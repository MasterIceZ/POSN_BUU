/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Peatt Matter
 * ALGO		: Dynamic Programming, Bitmasks
 * DATE		: 27 Apr 2022
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

const int Offset = 100 * 100;
bool dp[55][2 * 100 * 100 + 20];

inline void solution(){
	memset(dp, false, sizeof dp);
	int n, sum = 0;
	cin >> n;
	dp[0][Offset] = true;
	for(int i=1, x; i<=n; ++i){
		cin >> x;
		sum += x;
		for(int state=n/2; state>=1; --state){
			for(int j=1; j<=20000; ++j){
				if(0 <= j - x && j - x <= 20000);
				dp[state][j] |= dp[state - 1][j - x];
			}
		}
	}
	int answer = 1e9 + 100;
	for(int i=0; i<=20000; ++i){
		if(dp[n / 2][i]){
			answer = min(answer, abs(2 * (i - 10000) - sum));
		}
	}
	cout << answer;
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
