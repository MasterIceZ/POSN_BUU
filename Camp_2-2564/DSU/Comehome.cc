/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: PN_Comehome
 * ALGO		: Disjoint Set Union
 * DATE		: 17 Apr 2022
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

const int MxN = 300030;
int p[MxN];
bitset<MxN> visited;

int fr(int u){
	return u == p[u]? u: p[u] = fr(p[u]);
}

inline void solution(){
	int n, m;
	cin >> n >> m;
	for(int i=1; i<=m; ++i){
		p[i] = i;
	}
	for(int i=1, u, v; i<=n; ++i){
		bool ok = false;
		cin >> u >> v;
		int ru = fr(u), rv = fr(v);
		if(!visited[u]){
			ok = visited[u] = true;
			p[ru] = rv;
		}
		else if(!visited[v]){
			ok = visited[v] = true;
			p[rv] = ru;
		}
		else if(!visited[ru]){
			ok = visited[ru] = true;
			p[ru] = rv;
		}
		else if(!visited[rv]){
			ok = visited[rv] = true;
			p[rv] = ru;
		}
		cout << (ok ? "Yes": "No") << "\n";
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
