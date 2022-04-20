/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Longest
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

const int MxN = 1010;
int l[MxN][MxN], r[MxN][MxN], u[MxN][MxN], d[MxN][MxN];
string s[MxN];

inline void solution(){
	memset(l, 0, sizeof l);
	memset(r, 0, sizeof l);
	memset(d, 0, sizeof l);
	memset(u, 0, sizeof l);
	int n, m;
	cin >> n >> m;
	for(int i=1; i<=n; ++i){
		cin >> s[i];
		s[i] = " " + s[i];
	}
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=m; ++j){
			if(s[i][j] - '0'){
				l[i][j] = l[i][j - 1] + 1;
				u[i][j] = u[i - 1][j] + 1;
			}
		}
	}
	for(int i=n; i>=1; --i){
		for(int j=m; j>=1; --j){
			if(s[i][j] - '0'){
				r[i][j] = r[i][j + 1] + 1;
				d[i][j] = d[i + 1][j] + 1;
			}
		}
	}
	int answer = 0;
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=m; ++j){
			answer = max({answer, max({
				u[i][j] + l[i][j],
				d[i][j] + r[i][j],
				d[i][j] + l[i][j],
				u[i][j] + r[i][j]
			}) - 1});
		}
	}
	cout << answer ;
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
