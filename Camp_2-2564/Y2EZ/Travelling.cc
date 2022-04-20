/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Travelling
 * ALGO		: Dijkstra, Bitmasks
 * DATE		: 15 Apr 2022
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
	int bit;
	bool operator < (const Node& o) const {
		return w > o.w;
	}
	Node(int a, ll b, int c): u(a), w(b), bit(c) {}
};

const int MxN = 220;
ll w, dist[1 << 16][MxN], fw[MxN][MxN];
vector<pair<int, ll>> adj[MxN];
int special[MxN];

inline void solution(){
	int u, v, n, m, k;
	cin >> n >> m >> k;
	vector<int> pth;
	for(int i=0, x; i<k; ++i){
		cin >> x;
		special[x] = i + 1;
		pth.push_back(x);
	}
	memset(fw, 0x3f, sizeof fw);
	for(int i=1; i<=n; ++i){
		fw[i][i] = 0;
	}
	for(int i=1; i<=m; ++i){
		cin >> u >> v >> w;
		fw[u][v] = fw[v][u] = min(fw[v][u], w);
	}
	for(int k=1; k<=n; ++k){
		for(int i=1; i<=n; ++i){
			for(int j=1; j<=n; ++j){
				fw[i][j] = min(fw[i][j], fw[i][k] + fw[k][j]);
			}
		}
	}
	for(auto x: pth){
		adj[1].emplace_back(x, fw[1][x]);
		adj[x].emplace_back(1, fw[1][x]);
		adj[n].emplace_back(x, fw[x][n]);
		adj[x].emplace_back(n, fw[x][n]);
	}
	for(int i=0; i<(int) pth.size(); ++i){
		for(int j=i+1; j<(int) pth.size(); ++j){
			int u = pth[i], v = pth[j];
			adj[u].emplace_back(v, fw[u][v]);
			adj[v].emplace_back(u, fw[u][v]);
		}
	}
	memset(dist, 0x3f, sizeof dist);
	priority_queue<Node> pq;
	pq.emplace(1, 0, 0);
	dist[0][1] = 0;
	while(!pq.empty()){
		Node now = pq.top();
		pq.pop();
		dbg(now.u, now.w, now.bit);
		for(auto x: adj[now.u]){
			dbg(x.first);
			ll nxt = x.second + now.w;
			int nxt_bit = now.bit;
			if(special[x.first]){
				nxt_bit |= (1 << (special[x.first] - 1));
			}
			if(dist[nxt_bit][x.first] > nxt){
				dbg(now.u, x.first, nxt_bit);
				pq.emplace(x.first, dist[nxt_bit][x.second] = nxt, nxt_bit);
			}
		}
	}
	cout << dist[(1 << (1 + k)) - 1][n];
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
