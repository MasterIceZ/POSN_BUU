/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: toi12_cablecar
 * ALGO		: Minimum Spanning Tree
 * DATE		: 18 Apr 2022
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

struct Edge{
	int u, v, w;
	bool operator < (const Edge& o) const {
		return w < o.w;
	}
	Edge(int a, int b, int c): u(a), v(b), w(c) {}
};
priority_queue<Edge> edges;

int p[2550];

int fr(int u){
	return u==p[u]?u: p[u]=fr(p[u]);
}

inline void solution(){
	int n, m, u, v, w;
	cin >> n >> m;
	iota(p + 1, p + n + 1, 1);
	for(int i=1; i<=m; ++i){
		cin >> u >> v >> w;
		edges.emplace(u, v, w);
	}
	int s, d, x;
	cin >> s >> d >> x;
	while(!edges.empty()){
		Edge now = edges.top();
		edges.pop();
		int ru = fr(now.u), rv = fr(now.v);
		if(ru == rv){
			continue;
		}
		p[ru] = rv;
		int rd = fr(d), rs = fr(s);
		if(rd == rs){
			cout << fixed << setprecision(0) << ceil((double) x / (now.w - 1));
			return ;
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
