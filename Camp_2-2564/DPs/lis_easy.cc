/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		:
 * ALGO		:
 * DATE		:
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
int a[MxN], from[MxN], to[MxN], keep[MxN], len[MxN];

inline void solution(){
	int n;
	cin >> n;
	for(int i=1; i<=n; ++i){
		cin >> a[i];
		len[i] = 1;
		from[i] = i;
	}
	for(int i=2; i<=n; ++i){
		for(int j=1; j<i; ++j){
			if(a[i] > a[j] && len[i] < len[j] + 1){
				len[i] = len[j] + 1;
				from[i] = j;
			}
		}
	}
	int maxx = 0, at = 0;
	for(int i=1; i<=n; ++i){
		if(len[i] > maxx){
			maxx = len[i];
			at = i;
		}
	}
	cout << maxx << "\n";
	for(int i=1; i<=n; ++i){
		keep[i] = a[at];
		at = from[at];
	}
	for(int i=maxx; i>=1; --i){
		cout << keep[i] << " " ;
	}
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
