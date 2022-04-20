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

struct Edge{
	int u, v;
	ll w;
	bool operator < (const Edge& o) const {
		return w < o.w;
	}
	Edge(int a, int b, ll c): u(a), v(b), w(c) {}
};

priority_queue<Edge> edges;
int parent[200020];

int fr(int u){
	return u == parent[u]? u: parent[u] = fr(parent[u]);
}

inline void solution(){
	int n, m, u, v;
	ll w;
	cin >> n >> m;
	iota(parent + 1, parent + n + 1, 1);
	dbg(to_string(parent, 1, 5));
	for(int i=1; i<=m; ++i){
		cin >> u >>	v >> w;
		edges.emplace(u, v, w);
	}
	ll sum = 0ll;
	while(!edges.empty()){
		Edge now = edges.top();
		edges.pop();
		int ru = fr(now.u), rv = fr(now.v);
		if(ru == rv){
			continue;
		}
		sum += now.w - 1ll;
		parent[ru] = rv;
	}
	cout << sum;
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
