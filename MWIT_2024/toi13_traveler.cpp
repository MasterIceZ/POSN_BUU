#include <bits/stdc++.h>

using namespace std;

const int MxN = 10010;

struct state_t {
	int v, w;
	bool operator < (const state_t &o) const {
		return w > o.w;
	}
	state_t(int _v, int _w):
		v(_v), w(_w) {}
};

vector<pair<int, int>> adj[MxN];
int dist[2][MxN];
priority_queue<state_t> pq;

void dijkstra(int stp, int *dist) {
	pq.emplace(stp, dist[stp] = 0);
	while(!pq.empty()) {
		state_t now = pq.top(); pq.pop();
		for(auto x: adj[now.v]) {
			int nxt = now.w + x.second;
			if(dist[x.first] > nxt) {
				pq.emplace(x.first, dist[x.first] = nxt);
			}
		}
	}	
}

signed main(int argc, char *argv[]) {
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int n, m, x, y, z;
	cin >> n >> m >> x >> y >> z;
	for(int i=1, u, v, w; i<=m; ++i) {
		cin >> u >> v >> w;
		adj[u].emplace_back(v, w);
		adj[v].emplace_back(u, w);
	}
	memset(dist, 0x3f, sizeof dist);
	dijkstra(x, dist[0]);
	dijkstra(y, dist[1]);
	int from_start = -1e9 - 100, from_end = 1e9 + 100, index = -1;
	for(int i=0; i<=n; ++i) {
		if(dist[0][i] <= z && dist[0][i] >= from_start && dist[1][i] <= from_end) {
			index = i;
			from_start = dist[0][i];
			from_end = dist[1][i];
		}	
	}
	cout << index << " " << from_start << " " << from_end << "\n";
	return 0;
}
