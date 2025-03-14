#include <bits/stdc++.h>

using namespace std;

const int MxN = 100010;
const int MxQ = 300030;

struct edge_t {
	int u, v, w;
	edge_t(int _u, int _v, int _w):
		u(_u), v(_v), w(_w) {}
	bool operator < (const edge_t& o) const {
		return w < o.w;
	}
};

struct query_t {
	int u, v, w, idx;
	query_t(int _u, int _v, int _w, int _idx):
		u(_u), v(_v), w(_w), idx(_idx) {}
	bool operator < (const query_t& o) const {
		if(w != o.w) {
			return w < o.w;
		}
		return idx < o.idx;
	}
};

struct disjoint_set_union {
	int parent[MxN];
	void init(int n) {
		for(int i=1; i<=n; ++i) {
			parent[i] = i;
		}
	}
	int find_root(int u) {
		if(u == parent[u]) {
			return u;
		}
		return parent[u] = find_root(parent[u]);
	}
	bool unite(int u, int v) {
		int ru = find_root(u);
		int rv = find_root(v);
		if(ru == rv) {
			return false;
		}
		parent[ru] = rv;
		return true;
	}
};

vector<edge_t> edges;
vector<query_t> queries;
bool answer[MxQ];
disjoint_set_union dsu;

signed main(int argc, char *argv[]) {
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int n, m, q;
	cin >> n >> m >> q;
	for(int i=1, u, v, w; i<=m; ++i) {
		cin >> u >> v >> w;
		edges.emplace_back(u + 1, v + 1, w);
	}
	for(int i=1, u, v, w; i<=q; ++i) {
		cin >> u >> v >> w;
		queries.emplace_back(u + 1, v + 1, w, i);
	}
	sort(edges.begin(), edges.end());
	sort(queries.begin(), queries.end());
	dsu.init(n);
	int idx = 0;
	for(int i=0; i<m; ++i) {
		edge_t edge = edges[i];
		if(dsu.unite(edge.u, edge.v) == false) {
			continue;
		}
		int w = edge.w;
		if(i != m - 1) {
			w = edges[i + 1].w - 1;
		}
		while(idx < q) {
			if(queries[idx].w > w) {
				break;
			}
			answer[queries[idx].idx] = (dsu.find_root(queries[idx].u) == dsu.find_root(queries[idx].v));
			idx++;
		}
	}
	while(idx < q) {
		answer[queries[idx].idx] = (dsu.find_root(queries[idx].u) == dsu.find_root(queries[idx].v));
		idx++;
	}
	for(int i=1; i<=q; ++i) {
		cout << (answer[i] ? "Yes": "No") << "\n";
	}
	return 0;
}
