#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <numeric>
#include <vector>

const int MxN = 3030;

struct edge_t {
	int u, v, w;

	edge_t(int _u, int _v, int _w):
		u(_u), v(_v), w(_w) {}

	bool operator < (const edge_t &o) const {
		return w < o.w;
	}
};

int e[MxN][MxN], parent[MxN], dist[MxN];
std::vector<std::pair<int, int>> adj[MxN];

int find_root(int u) {
	if(u == parent[u]) {
		return u;
	}
	return parent[u] = find_root(parent[u]);
}

void dfs(int u, int p) {
	for(auto x: adj[u]) {
		if(x.first == p) {
			continue;
		}
		dist[x.first] = dist[u] + x.second;
		dfs(x.first, u);
	}
}

int main(int argc, char *argv[]) {
	std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);
	int n;
	std::cin >> n;
	std::vector<edge_t> edges;
	for(int i=1; i<=n; ++i) {
		for(int j=i+1; j<=n; ++j) {
			std::cin >> e[i][j];
			edges.emplace_back(i, j, e[i][j]);
		}
	}
	std::iota(parent + 1, parent + n + 1, 1);
	std::sort(edges.begin(), edges.end());
	for(auto &[u, v, w]: edges) {
		int ru = find_root(u), rv = find_root(v);
		if(ru == rv) {
			continue;
		}
		parent[ru] = rv;
		adj[u].emplace_back(v, w);
		adj[v].emplace_back(u, w);
	}
	std::queue<int> q;
	for(int i=1; i<=n; ++i) {
		memset(dist, -1, sizeof dist);
		dist[i] = 0;
		dfs(i, 0);
		for(int j=1; j<=n; ++j) {
			std::cout << dist[i] << " \n"[j == n];
		}
		for(int j=1; j<=n; ++j) {
			if(i == j || dist[j] == e[i][j]) {
				continue;
			}
			std::cout << "No\n";
			return 0;
		}
	}
	std::cout << "Yes\n";
	return 0;
}
