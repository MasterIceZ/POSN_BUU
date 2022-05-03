/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Peat Road Build
 * ALGO		: Dijkstra
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

struct Node{
	int v, w, state;
	bool operator < (const Node& o) const {
		return w > o.w;
	}
	Node(int a, int b, int c): v(a), w(b), state(c) {}
};

struct Edge{
	int first, second, idx;
	Edge(int a, int b, int c): first(a), second(b), idx(c) {}
};

const int MxN = 1010;
vector<Edge> adj[MxN];
int n, m, mem, dist[MxN][3];
priority_queue<Node> pq;

inline int dijkstra(int maxx){
	memset(dist, 0x3f, sizeof dist);
	pq.emplace(1, 0, 1);
	dist[1][1] = 0;
	while(!pq.empty()){
		Node now = pq.top();
		pq.pop();
		for(auto x: adj[now.v]){
			if(x.idx > maxx){
				continue;
			}
			int nxt = now.w + x.second;
			if(dist[x.first][now.state ^ 1] > nxt){
				pq.emplace(x.first, dist[x.first][now.state ^ 1] = nxt, now.state ^ 1);
			}
		}
	}
	return dist[n][0];
}

inline bool ok(int x){
	int res = dijkstra(x);
	dbg(res, x);
	return mem == res;
}

inline void solution(){
	cin >> n >> m;
	for(int i=1, u, v, w; i<=m; ++i){
		cin >> u >> v >> w;
		adj[u].emplace_back(v, w, i);
		adj[v].emplace_back(u, w, i);
	}
	mem = dijkstra(m);
	dbg(mem);
	int l = 1, r = m;
	while(l < r){
		int mid = (l + r) >> 1;
		if(ok(mid)){
			r = mid;
		}
		else{
			l = mid + 1;
		}
	}
	cout << l << " " << mem ;
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
