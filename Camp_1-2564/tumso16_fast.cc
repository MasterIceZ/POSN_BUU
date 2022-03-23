/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Fast Aid
 * ALGO		: Tarjan's Strongly Connected Components
 * DATE		: 23 Mar 2022
 * */

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>
// @==== Libary ====@ //

// @================@ //

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

const int MxN = 10010;
int n, m, timer;
bitset<MxN> visited;
vector<int> adj[MxN];
int low[MxN], idx[MxN];
vector<pair<int, int>> bridge;

void dfs(int u, int p = 0){
	visited[u] = true;
	idx[u] = low[u] = ++timer;
	for(auto x: adj[u]){
		if(x == p){
			continue ;
		}
		if(visited[x]){
			low[u] = min(low[u], idx[x]);
		}
		else{
			dfs(x, u);
			low[u] = min(low[u], low[x]);
			if(low[x] > idx[u]){
				bridge.emplace_back(min(u, x), max(u, x));
				dbg(bridge.back());
			}
		}
	}
}

inline void find_bridge(){
	timer = 0;
	memset(low, -1, sizeof low);
	memset(idx, -1, sizeof idx);
	for(int i=1; i<=n; ++i){
		if(!visited[i]){
			dfs(i);
		}
	}
}

inline void solution(){
	cin >> n >> m;
	vector<pair<int, int>> edges;
	for(int i=1, u, v; i<=m; ++i){
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
		edges.emplace_back(u, v);
	}
	find_bridge();
	if(!bridge.size()){
		cout << "OK!";
		return ;
	}
	cout << bridge[0].first << " " << bridge[0].second;
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
