#include <bits/stdc++.h>

using namespace std;

const int MxN = 100010;

struct kosaraju {
	vector<int> adj[MxN], rev_adj[MxN];
	stack<int> st;
	bitset<MxN> visited;
	int c_id, component[MxN];
	void add_edge(int u, int v) {
		adj[u].emplace_back(v);
		rev_adj[v].emplace_back(u);
	}
	void dfs_1(int u, int p) {
		visited[u] = true;
		for(auto v: adj[u]) {
			if(v == p || visited[v]) {
				continue;
			}
			dfs_1(v, u);
		}
		st.emplace(u);
	}
	void dfs_2(int u, int p, int c) {
		component[u] = c;
		visited[u] = true;
		for(auto v: rev_adj[u]) {
			if(v == p || visited[v]) {
				continue;
			}
			dfs_2(v, u, c);
		}
	}
	int compute_scc(int n) {
		visited = 0;
		for(int i=1; i<=n; ++i) {
			if(visited[i]) {
				continue;
			}
			dfs_1(i, 0);
		}
		c_id = 0;
		visited = 0;
		while(!st.empty()) {
			int u = st.top();
			st.pop();
			if(visited[u]) {
				continue;
			}
			dfs_2(u, 0, ++c_id);
		}
		return c_id;
	}
	vector<vector<int>> compress_graph(int n) {
		int component_count = compute_scc(n);
		vector<vector<int>> new_adj(component_count + 1);
		for(int u=1; u<=n; ++u) {
			for(auto v: adj[u]) {
				if(component[u] != component[v]) {
					continue;
				}
				int cu = component[u], cv = component[v];
				new_adj[cu].emplace_back(cv);
			}
		}
		return new_adj;
	}
} scc;

int height[MxN];

void dfs(int u, int lv, const vector<vector<int>> &adj) {
	height[u] = lv;
	for(auto v: adj[u]) {
		if(height[v] > lv) {
			continue;
		}
		dfs(v, lv + 1, adj);
	}
}

signed main(int argc, char *argv[]) {
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for(int i=1, u, v; i<=m; ++i) {
		char x;
		cin >> u >> v >> x;
		if(x == '<' || x == '=') {
			scc.add_edge(u, v);
		}
		if(x == '>' || x == '=') {
			scc.add_edge(v, u);
		}
	}
	vector<vector<int>> adj = scc.compress_graph(n);
	cerr << "D: " << scc.c_id << "\n";
	for(int i=1; i<=scc.c_id; ++i) {
		if(height[i]) {
			continue;
		}
		dfs(i, 0, adj);
	}	
	for(int u=1; u<=n; ++u) {
		cout << height[scc.component[u]] << "\n";
	}
	return 0;
}
