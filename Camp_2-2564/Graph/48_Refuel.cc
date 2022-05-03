/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: 48_Refuel
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
	int v, w, f;
	bool operator < (const Node& o) const {
		return w > o.w;
	}
	Node(int a, int b, int c): v(a), w(b), f(c) {}
};

const int MxN = 1010;
vector<pair<int, int>> adj[MxN];
int dist[MxN][110], p[MxN];

inline void solution(){
	int n, m, u, v, w, c, s, e;
	cin >> n >> m;
	for(int i=1; i<=n; ++i){
		cin >> p[i];
	}
	for(int i=1; i<=m; ++i){
		cin >> u >> v >> w;;
		u++, v++;
		adj[u].emplace_back(v, w);
		adj[v].emplace_back(u, w);
	}
	cin >> c >> s >> e;
	s++, e++;
	memset(dist, 0x3f, sizeof dist);
	dist[s][0] = 0;
	priority_queue<Node> pq;
	pq.emplace(s, 0, 0);
	while(!pq.empty()){
		Node now = pq.top();
		pq.pop();
		int nxt = now.w + p[now.v];
		if(now.f < c && dist[now.v][now.f + 1] > nxt){
			pq.emplace(now.v, dist[now.v][now.f + 1] = nxt, now.f + 1);
		}
		for(auto x: adj[now.v]){
			int nxt = now.w;
			if(now.f >= x.second && dist[x.first][now.f - x.second] > nxt){
				pq.emplace(x.first, dist[x.first][now.f - x.second] = nxt, now.f - x.second);
			}
		}
	}
	int res = 1e9 + 100;
	for(int i=0; i<=c; ++i){
		res = min(res, dist[e][i]);
	}
	cout << (res > 1e9? -99: res);
	for(int i=0; i<=n; ++i){
		adj[i].clear();
	}
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
