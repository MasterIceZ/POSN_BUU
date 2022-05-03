/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Turbo Programming
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
	int v, w;
	bool operator < (const Node& o) const {
		return w > o.w;
	}
	Node(int a, int b): v(a), w(b) {}
};

const int MxN = 1010;
vector<pair<int, int>> adj[MxN];
ll dist[MxN];
bitset<MxN> visited;

inline void solution(){
	int n, m, q;
	cin >> n >> m >> q;
	for(int i=1, u, v, w; i<=m; ++i){
		cin >> u >> v >> w;
		adj[u].emplace_back(v, w);
	}
	memset(dist, 0x3f, sizeof dist);
	priority_queue<Node> pq;
	dist[1] = 0;
	pq.emplace(1, 0);
	while(!pq.empty()){
		Node now = pq.top();
		pq.pop();
		visited[now.v] = true;
		for(auto x: adj[now.v]){
			int nxt = x.second + now.w;
			if(dist[x.first] > nxt){
				pq.emplace(x.first, dist[x.first] = nxt);
			}
		}
	}
	while(q--){
		int x;
		cin >> x;
		cout << (!visited[x] ? -1: dist[x]) << "\n";
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
