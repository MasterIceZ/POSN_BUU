/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: PT_Town Center
 * ALGO		: Minimum Spanning Tree
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

struct Edge{
	int u, v, w;
	bool operator < (const Edge& o) const {
		return w > o.w;
	}
	Edge(int a, int b, int c): u(a), v(b), w(c) {}
};

const int MxN = 1010;
int parent[MxN], deg[MxN];

int fr(int u){
	return u == parent[u]? u: parent[u] = fr(parent[u]);
}

inline void solution(){
	memset(deg, 0, sizeof deg);
	int n, w;
	cin >> n;
	iota(parent + 1, parent + n + 1, 1);
	priority_queue<Edge> edges;
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=n; ++j){
			cin >> w;
			if(j > i){
				edges.emplace(i, j, w);
			}
		}
	}
	while(!edges.empty()){
		Edge now = edges.top();
		edges.pop();
		dbg(now.u, now.v, now.w);
		int ru = fr(now.u), rv = fr(now.v);
		if(ru == rv){
			continue;
		}
		parent[ru] = rv;
		deg[now.u]++, deg[now.v]++;
	}
	int maxx = 0, it = 0;
	for(int i=1; i<=n; ++i){
		if(deg[i] > maxx){
			maxx = deg[i];
			it = i;
		}
	}
	cout << it << " " << maxx ;
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
