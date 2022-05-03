/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: AP_Table
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

struct Edge{
	int i, j, w;
	Edge(int a, int b, int c): i(a), j(b), w(c) {}
};

struct Node{
	int i, j, w;
	bool operator < (const Node& o) const {
		return w > o.w;
	}
	Node(int a, int b, int c): i(a), j(b), w(c) {}
};

const int MxN = 33;
char a[MxN][MxN];
vector<Edge> adj[MxN][MxN];
priority_queue<Node> pq;
int n, x, y, dist[MxN][MxN];
bitset<MxN> visited[MxN];

inline int dijkstra(int i, int j){
	pq.emplace(i, j, 0);
	memset(dist, 0x3f, sizeof dist);
	dist[i][j] = 0;
	memset(visited, false, sizeof visited);
	while(!pq.empty()){
		Node now = pq.top();
		pq.pop();
		visited[now.i][now.j] = true;
		for(auto x: adj[now.i][now.j]){
			int nxt = x.w + now.w;
			if(dist[x.i][x.j] > nxt){
				pq.emplace(x.i, x.j, dist[x.i][x.j] = nxt);
			}
		}
	}
	int res = 0;
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=n; ++j){
			if(!visited[i][j]){
				continue;
			}
			res = max(res, dist[i][j]);
		}
	}
	return res;
}

inline void solution(){
 	cin >> n >> x >> y;
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=n; ++j){
			cin >> a[i][j];
		}
	}	
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=n; ++j){
			if(i - 1 >= 1){
				adj[i][j].emplace_back(i - 1, j, a[i][j] == a[i - 1][j] ? x: y);
			}
			if(j - 1 >= 1){
				adj[i][j].emplace_back(i, j - 1, a[i][j] == a[i][j - 1] ? x: y);
			}
			if(i + 1 <= n){
				adj[i][j].emplace_back(i + 1, j, a[i][j] == a[i + 1][j] ? x: y);
			}
			if(j + 1 <= n){
				adj[i][j].emplace_back(i, j + 1, a[i][j] == a[i][j + 1] ? x: y);
			}
		}
	}
	int answer = 0;
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=n; ++j){
			answer = max(answer, dijkstra(i, j));
		}
	}
	cout << answer ;
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=n; ++j){
			adj[i][j].clear();
		}
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
