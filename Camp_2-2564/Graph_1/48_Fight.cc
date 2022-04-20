/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: 48_Fight
 * ALGO		: Depth First Search, Binary Search
 * DATE		: 18 Apr 2022
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
vector<int> adj[3 * MxN];
int n, m, color[3 * MxN], u[3 * MxN], v[3* MxN];

bool dfs(int u, int c){
	if(color[u]){
		return color[u] == c;
	}
	color[u] = c;
	for(auto x: adj[u]){
		if(!dfs(x, 3 - c)){
			return false;
		}
	}
	return true;
}

inline bool ok(int x){
	memset(color, 0, sizeof color);
	bool res = true;
	for(int i=1; i<=x; ++i){
		adj[u[i]].emplace_back(v[i]);
		adj[v[i]].emplace_back(u[i]);
	}
	for(int i=1; i<=n; ++i){
		if(!color[i]){
			res &= dfs(i, 1);
		}
	}
	for(int i=1; i<=x; ++i){
		adj[i].clear();
	}
	return res;
}

inline void solution(){
	cin >> n >> m;
	for(int i=1, a, b; i<=m; ++i){
		cin >> a >> b;
		u[i] = a, v[i] = b;
	}
	int l = 1, r = m;
	while(l < r){
		int mid = (l + r) >> 1;
		dbg(l, mid, r);
		if(ok(mid)){
			l = mid + 1;
		}
		else{
			r = mid;
		}
	}
	cout << l;
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
