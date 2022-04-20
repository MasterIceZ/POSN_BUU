/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: toi15_budget
 * ALGO		: Minimum Sapnning Tree
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

struct Edge{
	int u, v, w;
	bool operator < (const Edge& o) const {
		return w > o.w;
	}
	Edge(int a, int b, int c): u(a), v(b), w(c) {}
};

priority_queue<Edge> pq;
int p[3030];

int fr(int u){
	return u==p[u]? u: p[u] = fr(p[u]);
}

inline void solution(){
	int n, m, u, v, w, t;
	cin >> n >> m;
	for(int i=1; i<=n; ++i){
		p[i] = i;
	}
	for(int i=1; i<=m; ++i){
		cin >> u >> v >> w >> t;
		pq.emplace(u, v, t == 1 ? 0: w);
	}
	int x;
	cin >> x;
	vector<pair<int, int>> cst;
	for(int i=1, u, v; i<=x; ++i){
		cin >> u >> v;
		cst.emplace_back(u, v);
	}
	cst.emplace_back(0, 0);
	sort(cst.begin(), cst.end());
	for(int i=x-1; i>=0; --i){
		cst[i].second = min(cst[i].second, cst[i + 1].second);
	}
	int answer = 0;
	while(pq.size()){
		Edge now = pq.top();
		pq.pop();
		dbg(pq.size(), now.u, now.v, now.w);
		int ru = fr(now.u), rv = fr(now.v);
		dbg(ru, rv);
		if(ru == rv){
			continue;
		}
		p[ru] = rv;
		answer += (lower_bound(cst.begin(), cst.end(), make_pair(now.w, INT_MIN)))->second;
	}
	cout << answer;
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
