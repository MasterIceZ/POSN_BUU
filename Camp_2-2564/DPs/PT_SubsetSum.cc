/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: PT_Tree Subset
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

const int MxN = 100010;
vector<int> adj[MxN];
ll v[MxN], dp[MxN][2];
bitset<MxN> visited;

void dfs(int u){
	visited[u] = true;
	dp[u][1] = v[u];
	for(auto x: adj[u]){
		if(visited[x]){
			continue;
		}
		dfs(x);
		dp[u][0] += max(dp[x][0], dp[x][1]);
		dp[u][1] += dp[x][0];
	}
}

inline void solution(){
	int n;
	cin >> n;
	for(int i=1; i<=n; ++i){
		cin >> v[i];
	}
	for(int i=1, u, v; i<n; ++i){
		cin >> u >> v;
		adj[u].emplace_back(v);
		adj[v].emplace_back(u);
	}
	dfs(1);
	cout << max(dp[1][0], dp[1][1]);
	for(int i=1; i<=n; ++i){
		adj[i].clear();
	}	
	memset(dp, 0, sizeof dp);
	visited = 0;
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
