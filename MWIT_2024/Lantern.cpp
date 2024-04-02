#include <bits/stdc++.h>

using namespace std;

const int MxN = 100010;

vector<int> adj[MxN];
int dist[MxN];
queue<int> q;

signed main(int argc, char *argv[]) {
	int answer = 1, n, m, k;
	cin >> n >> m >> k;
	memset(dist, -1, sizeof dist);
	for(int i=1, x; i<=k; ++i) {
		cin >> x;
		q.emplace(x);
		dist[x] = 0;
	}
	for(int i=1, u, v; i<=m; ++i) {
		cin >> u >> v;
		adj[u].emplace_back(v);
		adj[v].emplace_back(u);
	}
	while(!q.empty()) {
		int now = q.front(); q.pop();
		for(auto x: adj[now]) {
			if(dist[x] != -1) {
				continue;
			}
			q.emplace(x);
			dist[x] = dist[now] + 1;
			answer = max(answer, dist[x]);
		}
	}
	for(int i=1; i<=n; ++i) {
		for(auto x: adj[i]) {
			if(dist[x] != dist[i]) {
				continue;
			}
			answer = max(answer, dist[i] + 1);
		}
	}
	cout << answer << "\n";
}
