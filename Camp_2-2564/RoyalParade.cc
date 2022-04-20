/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Royal Parade
 * ALGO		: Dijkstra
 * DATE		: 11 Apr 2022
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
	int u;
	ll w;
	bool operator < (const Node& o) const {
		return w > o.w;
	}
	Node(int a, ll b): u(a), w(b) {}
};

const int MxN = 100010;
vector<pair<int, ll>> adj[MxN];
ll dist[5][MxN];
bitset<MxN> used, visited;
priority_queue<Node> pq;

inline void dijkstra(ll dist[MxN], int source){
	visited = 0;
	pq.emplace(source, 0);
	dist[source] = 0;
	while(!pq.empty()){
		Node now = pq.top();
		pq.pop();
		visited[now.u] = true;
		for(auto x: adj[now.u]){
			if(used[x.first]){
				continue;
			}
			ll nxt = now.w + x.second;
			if(dist[x.first] >= nxt){
				pq.emplace(x.first, dist[x.first] = nxt);
			}
		}
	}
}

inline void solution(){
	int n, m, u, v, a, b;
	ll w;
	cin >> n >> m;
	for(int i=1; i<=m; ++i){
		cin >> u >> v >> w;
		adj[u].emplace_back(v, w);
		adj[v].emplace_back(u, w);
	}
	memset(dist, 0x3f, sizeof dist);
	cin >> a >> b;
	dijkstra(dist[1], a);
	dijkstra(dist[2], b);
	dbg(to_string(dist[1], 1, n));
	for(int i=1; i<=n; ++i){
		if(dist[1][b] == dist[1][i] + dist[2][i]){
			dbg(dist[1][i], dist[2][i], i);
			used[i] = true;
		}
	}
	cin >> a >> b;
	dijkstra(dist[3], a);
	cout << (!visited[b] ? -1: dist[3][b]) ;
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
