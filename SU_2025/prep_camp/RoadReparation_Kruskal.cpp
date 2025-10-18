#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct edge_t {
	int u, v;
	ll w;
	edge_t(int _u, int _v, ll _w):
		u(_u), v(_v), w(_w) {}
	bool operator < (const edge_t &o) const {
		return w < o.w;
	}
};

struct disjoint_set_union {
	int *p, n, c;
	disjoint_set_union(int _n): n(_n) {
		p = (int *) calloc(n + 1, sizeof (int));
		init();
	}
	void init() {
		iota(p + 1, p + n + 1, 1);
		c = n;
	}
	int find_root(int u) {
		if(p[u] == u) {
			return u;
		}
		return p[u] = find_root(p[u]);
	}
	bool unite(int u, int v) {
		int ru = find_root(u), rv = find_root(v);
		if(ru == rv) {
			return false;
		}
		c--;
		p[ru] = rv;
		return true;
	}
};

ll sum = 0ll, w;

signed main(int argc, char *argv[]) {
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	disjoint_set_union dsu(n);
	vector<edge_t> edges;
	for(int i=1, u, v; i<=m; ++i) {
		cin >> u >> v >> w;
		edges.emplace_back(u, v, w);
	}
	sort(edges.begin(), edges.end());
	for(auto edge: edges) {
		if(!dsu.unite(edge.u, edge.v)) {
			continue;
		}
		sum += edge.w;
	}
	cout << (dsu.c == 1 ? to_string(sum) : "IMPOSSIBLE")<< "\n";
	return 0;
}
