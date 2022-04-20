/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: PZ_Follow
 * ALGO		: Breadth First Search
 * DATE		: 19 Apr 2022
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

const int MxN = 110;
const int MxS = 1024 + 6;

bool visited[MxN][MxS];
vector<pair<int, int>> adj[MxN];

inline void solution(){
	memset(visited, false, sizeof visited);
	int n, m, s, e;
	cin >> n >> m >> s >> e;
	for(int i=1, u, v, w; i<=m; ++i){
		cin >> u >> v >> w;
		adj[u].emplace_back(v, w);
		adj[v].emplace_back(u, w);
	}	
	queue<pair<int, int>> q;
	q.emplace(s, 0);
	visited[s][0] = true;
	while(!q.empty()){
		pair<int, int> now = q.front();
		q.pop();
		for(auto x: adj[now.first]){
			int nxt = x.second ^ now.second;
			if(visited[x.first][nxt]){
				continue;
			}
			visited[x.first][nxt] = true;
			q.emplace(x.first, nxt);
		}
	}
	int res = -1;
	for(int i=0; i<=1024; ++i){
		if(visited[e][i]){
			res = i;
			break;
		}
	}
	cout << res;
	for(int i=1; i<=100; ++i){
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
