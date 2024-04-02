// Turbo Programming

#include <bits/stdc++.h>

using namespace std;

const int MxN = 1010;

struct state_t {
	int v, w;
	bool operator < (const state_t &o) const {
		return w > o.w;
	}
	state_t(int _v, int _w):
		v(_v), w(_w) {}
};

vector<pair<int, int>> adj[MxN];
priority_queue<state_t> pq;
int dist[MxN];

signed main(int argc, char *argv[]) {
	int n, m, q;
	cin >> n >> m >> q;
	for(int i=1, u, v, w; i<=m; ++i) {
		cin >> u >> v >> w;
		adj[u].emplace_back(v, w);
	}
	memset(dist, 0x3f, sizeof dist);
	pq.emplace(1, dist[1] = 0);
	while(!pq.empty()) {
		state_t now = pq.top(); pq.pop();
		for(auto x: adj[now.v]) {
			int nxt = now.w + x.second;
			if(dist[x.first] > nxt) {
				pq.emplace(x.first, dist[x.first] = nxt);
			}
		}
	}
	while(q--) {
		int x;
		cin >> x;
		cout << (dist[x] >= 1e9 + 100 ? -1: dist[x]) << "\n";
	}
	return 0;
}
