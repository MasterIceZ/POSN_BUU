#include <bits/stdc++.h>

using namespace std;

const int MxN = 1010;

vector<int> adj[MxN];
int it = 0, level[MxN], rt[MxN], visited[MxN];

void dfs(int u, int p) {
	visited[u] = it;
	for(auto x: adj[u]) {
		if(x == p || level[x] < level[u]) {
			continue;
		}
		dfs(x, u);
	}
}

signed main(int argc, char *argv[]) {
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int n, m, t, u, v;
	cin >> n >> m >> t;
	for(int i=1; i<=m; ++i) {
		cin >> u >> v;
		adj[u].emplace_back(v);
		adj[v].emplace_back(u);
	}
	memset(level, -1, sizeof level);
	queue<int> q;
	for(int i=1; i<=t; ++i) {
		cin >> rt[i];
		level[rt[i]] = 0;
		q.emplace(rt[i]);
		while(!q.empty()) {
			int now = q.front(); q.pop();
			for(auto x: adj[now]) {
				if(level[x] != -1) {
					continue;
				}
				level[x] = level[u] + 1;
				q.emplace(x);
			}
		}
	}
	int _;
	cin >> _;
	while(_--) {
		cin >> u >> v;
		++it;
		dfs(v, 0);
		cout << (visited[u] == it ? "YES": "NO") << "\n";
	}
}
