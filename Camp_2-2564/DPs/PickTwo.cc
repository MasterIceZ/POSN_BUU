/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Pick Two Sequence
 * ALGO		: Dynamic Programming
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

const int MxN = 100010;
int dp[2][MxN], a[MxN];

inline void solution(){
	memset(dp, 0, sizeof dp);
	int n;
	cin >> n;
	for(int i=1; i<=n; ++i){
		cin >> a[i];
	}
	int maxx = -1e9 - 100, sum = 0;
	for(int i=1; i<=n; ++i){
		sum = max(sum + a[i], 0);
		maxx = max(maxx, sum);
		dp[0][i] = maxx;
	}
	maxx = -1e9 - 100, sum = 0;
	for(int i=n; i>=1; --i){
		sum = max(sum + a[i], 0);
		maxx = max(maxx, sum);
		dp[1][i] = maxx;
	}
	int answer = -1e9-100;
	for(int i=1; i<=n; ++i){
		answer = max(answer, dp[0][i] + dp[1][i + 1]);
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
