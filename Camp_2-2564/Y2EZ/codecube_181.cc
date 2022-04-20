/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Copying is not permitted
 * ALGO		: Disjoint Set Union
 * DATE		: 13 Apr 2022
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
	int u, v, w;
	bool operator < (const Edge& o) const {
		return w < o.w;
	}
	Edge(int a, int b, int c): u(a), v(b), w(c) {}
};

const int MxN = 40040;
int parent[MxN];
vector<Edge> edges;
vector<pair<int, int>> copying;

inline void clear_dsu(){
	for(int i=1; i<=40000; ++i){
		parent[i] = i;
	}
}

int fr(int u){
	return u == parent[u]? u: parent[u] = fr(parent[u]);
}

inline bool ok(int x){
	clear_dsu();
	for(auto edge: edges){
		// since we sorted edges
		if(edge.w >= x){
			break;
		}
		parent[fr(edge.u)] = fr(edge.v);
	}
	bool ok = true;
	for(auto edge: copying){
		if(fr(edge.first) == fr(edge.second)){
			ok = false;
			break;
		}
	}
	return ok;
}

inline void solution(){
	int n, m, p;
	cin >> n >> m >> p;
	for(int i=1, u, v, w; i<=m; ++i){
		cin >> u >> v >> w;
		edges.emplace_back(u, v, w);
	}
	for(int i=1, u, v; i<=p; ++i){
		cin >> u >> v;
		copying.emplace_back(u, v);
	}
	sort(edges.begin(), edges.end());
	int l = 0, r = 1e9 + 100;
	while(l < r){
		int mid = (l + r) >> 1;
		bool _ok = ok(mid);
		dbg(l, r, mid, _ok);
		if(_ok){
			l = mid + 1;
		}
		else{
			r = mid;
		}
	}
	cout << (r == 1e9 + 100 ? -1: l - 1);

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
