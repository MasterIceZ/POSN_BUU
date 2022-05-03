/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: PZ_Fair
 * ALGO		: Dijkstra, Greedy
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
	int v;
	ll w;
	bool operator < (const Node& o) const {
		return w > o.w;
	}
	Node(int a, ll b): v(a), w(b) {}
};

const int MxN = 50050;
const int MxS = 110;
vector<int> shop[MxS];
ll sh[MxN], dist[MxS][MxN];
vector<pair<int, ll>> adj[MxN];
priority_queue<Node> pq;

inline void dijkstra(ll *dist, int i){
	for(auto x: shop[i]){
		pq.emplace(x, 0);
		dist[x] = 0;
	}
	while(!pq.empty()){
		Node now = pq.top();
		pq.pop();
		for(auto x: adj[now.v]){
			ll nxt = now.w + x.second;
			if(dist[x.first] > nxt){
				pq.emplace(x.first, dist[x.first] = nxt);
			}
		}
	}
}

inline void solution(){
	int n, m, a, u, v;
	ll w;
	cin >> n >> m >> a;
	for(int i=1; i<=n; ++i){
		cin >> sh[i];
		shop[sh[i]].emplace_back(i);
	}	
	for(int i=1; i<=m; ++i){
		cin >> u >> v >> w;
		adj[u].emplace_back(v, w);
		adj[v].emplace_back(u, w);
	}
	memset(dist, 0x3f, sizeof dist);
	for(int i=1; i<=100; ++i){
		dijkstra(dist[i], i);
	}
	ll answer = 1e18;
	vector<ll> t;
	for(int i=1; i<=n; ++i){
		t.clear();
		for(int j=1; j<=100; ++j){
			t.emplace_back(dist[j][i]);
		}
		sort(t.begin(), t.end());
		ll sum = 0;
		for(int j=0; j<a; ++j){
			if(t[j] >= 1e18){
				sum = 1e18;
				break;
			}
			sum += t[j];
		}
		answer = min(answer, sum);
	}
	cout << (answer >= 1e18? -1: answer) ;
	for(int i=1; i<=n; ++i){
		adj[i].clear();
	}
	for(int i=1; i<=100; ++i){
		shop[i].clear();
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
