/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Up Kahn
 * ALGO		: Topological Sort, Kahn Algorithm
 * DATE		: 25 Apr 2022
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
vector<int> adj[MxN], answer;
int in[MxN];
priority_queue<int, vector<int>, greater<int>> pq;

inline void solution(){
	int n, m, u, v;
	memset(in, 0, sizeof in);
	cin >> n >> m;
	for(int i=1; i<=m; ++i){
		cin >> u >> v;
		adj[u].emplace_back(v);
		in[v]++;
	}
	for(int i=1; i<=n; ++i){
		if(!in[i]){
			pq.emplace(i);
		}
	}
	answer.clear();
	while(!pq.empty()){
		int now = pq.top();
		pq.pop();
		answer.emplace_back(now);
		for(auto x: adj[now]){
			if(--in[x] == 0){
				pq.emplace(x);
			}
		}
	}
	dbg(answer);
	if((int) answer.size() != n){
		cout << "No";
	}
	else{
		cout << "Yes";
		for(auto x: answer){
			cout << " " << x;
		}
	}
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
