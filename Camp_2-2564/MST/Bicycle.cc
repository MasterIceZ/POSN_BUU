/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: 48_Bicycle
 * ALGO		: Minimum Spanning Tree
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

struct Edge{
	int u, v, w;
	bool operator < (const Edge& o) const {
		return w < o.w;
	}	
	Edge(int a, int b, int c): u(a), v(b), w(c) {}
};

unordered_map<int, int> mp;
priority_queue<Edge> pq;
int parent[70070];

int fr(int u){
	return u == parent[u] ? u: parent[u] = fr(parent[u]);
}

inline void solution(){
	mp.clear();
	int n, m;
	cin >> n >> m;
	iota(parent + 1, parent + n + 1, 1);
	for(int i=1, x; i<=n; ++i){
		cin >> x;
		mp[x] = i;
	}
	int sum = 0;
	for(int i=1, u, v, w; i<=m; ++i){
		cin >> u >> v >> w;
		pq.emplace(mp[u], mp[v], w);
		sum += w;
	}
	while(!pq.empty()){
		Edge now = pq.top();
		pq.pop();
		int ru = fr(now.u), rv = fr(now.v);
		if(ru == rv){
			continue;
		}
		parent[ru] = rv;
		sum -= now.w;
	}
	cout << sum;
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
