/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Memory
 * ALGO		: Dynamic Programming
 * DATE		: 14 Apr 2022
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

int a[MxN], b[MxN], dp[2][MxN], minn[MxN];

inline void solution(){
	int n, m, k;
	cin >> n >> m >> k;
	for(int i=1; i<=n; ++i){
		cin >> a[i];
	}
	for(int i=1; i<=m; ++i){
		cin >> b[i];
		dp[0][i] = i, minn[i] = i;
	}
	int answer = 0;
	for(int i=1; i<=n; ++i){
		dp[i % 2][0] = 1;
		for(int j=1; j<=m; ++j){
			if(a[i] == b[j]){
				dp[i % 2][j] = dp[(i + 1) % 2][j - 1];
			}
			else{
				dp[i % 2][j] = 1e9 + 100;
			}
			dp[i % 2][j] = min({dp[i % 2][j], dp[i % 2][j - 1] + 1, dp[(i + 1) % 2][j - 1] + 1, minn[j] + 1});
			if(dp[i % 2][j] <= k){
				answer = max(answer, j);
			}
			minn[j] = min(minn[j], dp[i % 2][j]);
		}
	}
	cout << answer;
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
