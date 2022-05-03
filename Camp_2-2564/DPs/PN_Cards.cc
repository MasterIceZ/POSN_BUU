/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: PN_Cards
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

const int MxN = 5050;
ll a[MxN], b[MxN], dp[2][MxN];

inline void solution(){
	memset(dp, 0, sizeof dp);
	int n, m;
	cin >> n >> m;
	for(int i=1; i<=n; ++i){
		cin >> a[i];
	}
	for(int i=1; i<=m; ++i){
		cin >> b[i];
	}
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=m; ++j){
			dp[i % 2][j] = max({dp[(i + 1) % 2][j - 1] + abs(a[i] - b[j]), dp[i % 2][j - 1], dp[(i + 1) % 2][j]});
		}
	}
	cout << dp[n % 2][m];
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
