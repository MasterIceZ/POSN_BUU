/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: toi10_map
 * ALGO		: Breadth First Search 
 * DATE		: 20 Apr 2022
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

struct Cell{
	int i, j, value;
	bool operator < (const Cell& o) const {
		if(i == o.i){
			return j < o.j;
		}
		return i > o.i; 
	}
};

struct Node{
	int i, j, value;
	Node(int a, int b, int c): i(a), j(b), value(c) {}
};

const int MxN = 40040;
char opr;
Cell table[MxN];
const int di[] = {0, 0, -1, 1};
const int dj[] = {1, -1, 0, 0};
vector<Node> adj[MxN];
bitset<MxN> visited;

int dir(char a){
	if(a == 'U'){
		return 3;
	}
	return 1;
}

inline void solution(){
	int n, m;
	cin >> n >> m;
	int sz = n * m - 1;	
	for(int i=0; i<=sz; ++i){
		table[i].value = i;
	}
	for(int i=1, u, v; i<=sz; ++i){
		cin >> u >> opr >> v;
		int d = dir(opr);
		adj[u].emplace_back(di[d - 1], dj[d - 1], v);
		adj[v].emplace_back(di[d], dj[d], u);
	}
	table[0].i = 0, table[0].j = 0;
	queue<int> q;
	q.emplace(0);
	visited[0] = true;
	while(!q.empty()){
		int now = q.front();
		q.pop();
		visited[now] = true;
		for(auto x: adj[now]){
			int ii = x.i, jj = x.j;
			if(visited[x.value]){
				continue;
			}
			visited[x.value] = true;
			table[x.value].i = table[now].i + ii;
			table[x.value].j = table[now].j + jj;
			q.emplace(x.value);
		}
	}
	sort(table, table + sz + 1);
	for(int i=0; i<n; ++i){
		for(int j=0; j<m; ++j){
		cout << table[i * m + j].value << " " ;
		}
		cout << "\n";
	}
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
