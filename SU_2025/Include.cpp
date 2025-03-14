#include <bits/stdc++.h>

using namespace std;

const int MxN = 1010;

int visited[MxN];
vector<int> adj[MxN];

bool dfs(int u, int it) {
	if(visited[u] == it) {
		return true;
	}
	visited[u] = it;
	bool status = false;
	for(auto v: adj[u]) {
		status |= dfs(v, it);
	}
	return status;
}

signed main(int argc, char *argv[]) {
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for(int i=1, t; i<=n; ++i) {
		cin >> t;
		for(int j=1, x; j<=t; ++j) {
			cin >> x;
			adj[i].emplace_back(x);
		}
	}
	for(int i=1; i<=n; ++i) {
		cout << (dfs(i, i) ? "YES": "NO") << "\n";
	}
}
