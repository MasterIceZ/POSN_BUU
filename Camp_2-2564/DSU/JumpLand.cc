/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Jumpland
 * ALGO		: Disjoint Set Union, Sack
 * DATE		: 17 Apr 2022
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

const int MxN = 707;
int n, answer = 1;
int v[MxN * MxN], h[MxN * MxN];

struct Land{
	struct A{
		int u, v;
		double w;
		bool operator < (const A& o) const {
			return w < o.w;
		}
		A(int a, int b, double c): u(a), v(b), w(c) {}
	};
	struct DSU{
		int parent[MxN * MxN];
		inline void init(){
			for(int i=0; i<n*n; ++i){
				parent[i] = i;
			}
		}
		int find_root(int u){
			return parent[u] == u ? u: find_root(parent[u]);
		}
	} dsu;
	vector<A> t, tmp;
	int cnt[MxN * MxN];
	inline void add(int a, int b, double c){
		t.emplace_back(a, b, c);
	}
	inline void init(){
		for(int i=0; i<n*n; ++i){
			cnt[i] = 1;
		}
		dsu.init();
	}
	inline void reset(){
		reverse(tmp.begin(), tmp.end());
		for(auto x: tmp){
			cnt[x.u] -= cnt[x.v];
			dsu.parent[x.v] = x.v;
		}
		tmp.clear();
	}
	inline void merge(int a, int b){
		if(v[a] != v[b]){
			double timer = (double) (h[b] - h[a]) / (v[a] - v[b]);
			dbg(timer, a, b);
			if(timer < 0){
				return ;
			}
			add(a, b, timer);
		}
		else if(h[a] == h[b]){
			int ra = dsu.find_root(a), rb = dsu.find_root(b);
			if(ra == rb){
				return ;
			}
			dbg(ra, rb);
			answer = max(answer, cnt[ra] + cnt[rb]);
			if(cnt[ra] >= cnt[rb]){
				cnt[ra] += cnt[rb];
				dsu.parent[rb] = ra;
			}
			else{
				cnt[rb] += cnt[ra];
				dsu.parent[ra] = rb;
			}
		}
	}
	inline void calc(){
		dbg(answer, t.size());
		sort(t.begin(), t.end());
		for(auto x: t){
			dbg(x.u, x.v, x.w);
		}
		for(int i=1; i<(int) t.size(); ++i){
			if(t[i].w != t[i - 1].w){
				reset();
			}
			int ru = dsu.find_root(t[i].u), rv = dsu.find_root(t[i].v);
			dbg(ru, rv);
			if(ru == rv){
				continue; 
			}
			answer = max(answer, cnt[ru] + cnt[rv]);
			dbg(answer, cnt[ru] + cnt[rv]);
			if(cnt[ru] >= cnt[rv]){
				cnt[ru] += cnt[rv];
				dsu.parent[rv] = ru;
				tmp.emplace_back(ru, rv, 0);
			}
			else{
				cnt[rv] += cnt[ru];
				dsu.parent[ru] = rv;
				tmp.emplace_back(rv, ru, 0);
			}
		}
	}
};

Land land;

inline int id(int a, int b){
	return a * n + b;
}

inline void solution(){
	cin >> n;
	land.init();
	land.add(0, 0, -1);
	for(int i=0; i<n*n; ++i){
		cin >> h[i];
	}
	for(int i=0; i<n*n; ++i){
		cin >> v[i];
	}
	for(int i=0; i<n; ++i){
		for(int j=0; j<n; ++j){
			if(i + 1 < n){
				land.merge(id(i, j), id(i + 1, j));
			}
			if(j + 1 < n){
				land.merge(id(i, j), id(i, j + 1));
			}
		}
	}
	land.calc();
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
