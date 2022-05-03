/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Segitiga Operation
 * ALGO		: Dynamic Programming
 * DATE		: 25 Apr 2022
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

inline int convert(int a, int b){
	if(a == 0){
		return 2 - b;
	}
	if(a == 1){
		return b == 0 ? 2: 1;
	}
	return b == 1 ? 2: 1;
}

const int MxN = 260;
bool dp[MxN][MxN][4];

inline void solution(){
	int n;
	string s;
	cin >> n >> s;
	s = " " + s;
	if(s[1] != '0'){
		cout << "no";
		return ;
	}
	memset(dp, false, sizeof dp);
	for(int i=1; i<=n; ++i){
		dp[i][i][s[i] - '0'] = true;
	}
	for(int sz=2; sz<=n; ++sz){
		for(int i=1; i+sz-1<=n; ++i){
			int j = i + sz - 1;
			for(int k=i; k<j; ++k){
				for(int a=0; a<=2; ++a){
					for(int b=0; b<=2; ++b){
						if(dp[i][k][a] && dp[k + 1][j][b]){
							dp[i][j][convert(a, b)] = true;
						}
					}
				}
			}
		}
	}
	cout << (dp[1][n][0] ? "yes": "no");
	return ;
}

signed main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);	
	int q = 20;
//	cin >> q;
	while(q--){
		solution();
		cout << "\n";
	}
	return 0;
}
// https://github.com/MasterIceZ/archive/tree/main/cpp-template
