/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		:
 * ALGO		:
 * DATE		:
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
ll sum, res, val[MxN];

void dfs(int u, int p){
	for(auto x: adj[u]){
		if(x == p){
			continue;
		}
		dfs(x, u);
		val[u] += val[x];
	}
	res = min(res, abs(sum - 2 * val[u]));
}

inline void solution(){
	int n, m;
	cin >> n;
	for(int i=1, u, v; i<n; ++i){
		cin >> u >> v;
		adj[u].emplace_back(v);
		adj[v].emplace_back(u);
	}
	for(int i=1; i<=n; ++i){
		cin >> val[i];
	}
	sum = accumulate(val + 1, val + n + 1, 0ll);
	res = 1e18;
	dfs(1, 0);
	cout << res;
	for(int i=1; i<=n; ++i){
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
