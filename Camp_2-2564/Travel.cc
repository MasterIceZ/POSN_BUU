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

const int MxN = 100010;
int p[MxN], sz[MxN], value[MxN];

inline int fr(int u){
	while(p[u] != u){
		u = p[u];
	}
	return u;
}

inline void solution(){
	int n, q;
	cin >> n >> q;
	for(int i=1; i<=n; ++i){
		p[i] = i;
		sz[i] = 1;
	}
	while(q--){
		cin >> opr;
		if(opr == 1){
			int x, y, a;
			cin >> x >> y >> a;
			int rx = fr(x), ry = fr(y);
			if(sz[rx] >= sz[ry]){
				sz[rx] += sz[ry];
				p[ry] = rx;
				value[ry] = value[rx];
				value[rx] = a;
			}
			else{
				sz[ry] += sz[rx];
				p[rx] = ry;
				value[rx] = value[ry];
				value[ry] = a;
			}
		}
		else{
			
		}
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
