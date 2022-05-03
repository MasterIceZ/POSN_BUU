/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Durian Binary Tree
 * ALGO		: Dynamic Programming on Tree
 * DATE		: 27 Apr 2022
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

const int MxN = 105;
vector<pair<int, int>> adj[MxN];
int parent[MxN], dp[MxN][MxN];
vector<int> child[MxN];

void dfs(int u){
	for(auto x: adj[u]){
		if(parent[x.first] != -1){
			continue;
		}
		parent[x.first] = x.second;
		child[u].emplace_back(x.first);
		dfs(x.first);
	}
}

int query(int u, int k){
	if(dp[u][k] != -1){
		return dp[u][k];
	}
	if(k == 0){
		return 0;
	}
	if(child[u].empty()){
		return parent[u];
	}
	if(child[u].size() == 1){
		return dp[u][k] = query(child[u][0], k - 1) + parent[u];
	}
	int maxx = -1;
	for(int i=0; i<k; ++i){
		maxx = max(maxx, query(child[u][0], i) + query(child[u][1], k - i - 1) + parent[u]);
	}
	return dp[u][k] = maxx;
}

inline void solution(){
	int u, v, w, n, k;
	cin >> n >> k;
	memset(parent, -1, sizeof parent);
	memset(dp, -1, sizeof dp);
	for(int i=1; i<n; ++i){
		cin >> u >> v >> w;
		adj[u].emplace_back(v, w);
		adj[v].emplace_back(u, w);
	}	
	parent[1] = 0;
	dfs(1);
	cout << query(1, k + 1);
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
