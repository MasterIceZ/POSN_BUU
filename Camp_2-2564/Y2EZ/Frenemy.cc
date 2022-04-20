/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Frenemy
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

const int MxN = 1010;
const int MOD = 1e9 + 7;

ll dr[MxN][MxN], ul[MxN][MxN], ur[MxN][MxN], dl[MxN][MxN];
string a[MxN];

inline void solution(){
	int n;
	cin >> n;
	for(int i=1; i<=n; ++i){
		cin >> a[i];
		a[i] = " " + a[i];
	}
	dr[1][1] = 1;
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=n; ++j){
			if(a[i][j] == '0'){
				continue;
			}
			dr[i][j] += dr[i - 1][j] + dr[i][j - 1];
			dr[i][j] %= MOD;
		}
	}
	ul[n][n] = 1;
	for(int i=n; i>=1; --i){
		for(int j=n; j>=1; --j){
			if(a[i][j] == '0'){
				continue;
			}
			ul[i][j] += ul[i + 1][j] + ul[i][j + 1];
			ul[i][j] %= MOD;
		}
	}
	dl[1][n] = 1;
	for(int i=1; i<=n; ++i){
		for(int j=n; j>=1; --j){
			if(a[i][j] == '0'){
				continue;
			}
			dl[i][j] += dl[i - 1][j] + dl[i][j + 1];
			dl[i][j] %= MOD;
		}
	}
	ur[n][1] = 1;
	for(int i=n; i>=1; --i){
		for(int j=1; j<=n; ++j){
			if(a[i][j] == '0'){
				continue;
			}
			ur[i][j] += ur[i + 1][j] + ur[i][j - 1];
			ur[i][j] %= MOD;
		}
	}
	ll res = 0;
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=n; ++j){
			if(a[i][j] == '0'){
				continue;
			}
			ll A = (dr[i][j - 1] * ul[i][j + 1]) % MOD;
			ll B = (dl[i - 1][j] * ur[i + 1][j]) % MOD;
			res += (A * B) % MOD;
			res %= MOD;
			A = (dr[i - 1][j] * ul[i + 1][j]) % MOD;
			B = (ur[i][j - 1] * dl[i][j + 1]) % MOD;
			res += (A * B) % MOD;
			res %= MOD;
		}
	}
	cout << res;
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
