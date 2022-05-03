/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Key
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

string s, t;

const int MxN = 1010;
int dp[MxN][MxN];

inline void solution(){
	string s, t, u;
	cin >> s >> t;
	int q, n = s.size(), m = t.size();
	cin >> q;
	while(q--){
	memset(dp, 0, sizeof dp);
		cin >> u;
		dp[0][0] = 1;
		for(int i=0; i<=n; ++i){
			for(int j=0; j<=m; ++j){
				if(!dp[i][j]){
					continue;
				}
				if(i < n && s[i] == u[i + j]){
					dp[i + 1][j] = 1;
				}
				if(j < m && t[j] == u[i + j]){
					dp[i][j + 1] = 1;
				}
			}
		}
		cout << (dp[n][m] ? "Yes": "No") << "\n";
	}
	return ;
}

signed main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);	
	int q = 1;
//	cin >> q;
	while(q--){
		solution();
	}
	return 0;
}
// https://github.com/MasterIceZ/archive/tree/main/cpp-template
