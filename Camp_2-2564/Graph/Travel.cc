/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: toi13_travel
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
const int MxN = 10010;
vector<pair<int, int>> adj[MxN];
priority_queue<Node> pq;
int dist[3][MxN];

inline void dijkstra(int *dist, int source){
	pq.emplace(source, 0);
	dist[source] = 0;
	while(!pq.empty()){
		Node now = pq.top();
		pq.pop();
		for(auto x: adj[now.v]){
			int nxt = x.second + now.w;
			if(dist[x.first] > nxt){
				pq.emplace(x.first, dist[x.first] = nxt);
			}
		}
	}
}

inline void solution(){
	int n, m, stp, edp, expected, u, v, w;
	cin >> n >> m;
	cin >> stp >> edp >> expected;
	for(int i=1; i<=m; ++i){
		cin >> u >> v >> w;
		adj[u].emplace_back(v, w);
		adj[v].emplace_back(u, w);
	}
	memset(dist, 0x3f, sizeof dist);
	dijkstra(dist[0], stp);
	dijkstra(dist[1], edp);
	int res_2 = -1e9 - 100, res_3 = 1e9 + 100, res_1 = -1;
	for(int i=0; i<=n; ++i){
		if(dist[0][i] <= expected && dist[0][i] >= res_2 && dist[1][i] < res_3){
			res_1 = i;
			res_2 = dist[0][i];
			res_3 = dist[1][i];
		}
	}
	cout << res_1 << " " << res_2 << " " << res_3 ;
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
