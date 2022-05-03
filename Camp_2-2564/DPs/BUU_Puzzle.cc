/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: BUU Puzzle
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

const int MxN = 50050;
int a[6][MxN], dp[33][MxN];

inline void solution(){
	memset(dp, 0, sizeof dp);
	int m;
	cin >> m;
	for(int i=0; i<5; ++i){
		for(int j=1; j<=m; ++j){
			cin >> a[i][j];
		}
	}
	vector<int> masks = {0, 1, 2, 4, 5, 8, 9, 10, 16, 17, 18, 20, 21};
	for(int j=1; j<=m; ++j){
		for(int i=0; i<(int) masks.size(); ++i){
			int res = 0;
			for(int k=0; k<5; ++k){
				if(masks[i] & (1 << k)){
					res += a[k][j];
				}
			}
			for(int k=0; k<(int) masks.size(); ++k){
				if(!(masks[i] & masks[k])){
					dp[i][j + 1] = max(dp[i][j + 1], dp[k][j] + res);
				}
			}
		}
	}
	int res = 0;
	for(int i=0; i<(int) masks.size(); ++i){
		res = max(res, dp[i][1 + m]);
	}
	cout << res;
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
