#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MxN = 100010;

struct state_t {
	int v;
	ll w;
	bool operator < (const state_t &o) const {
		return w > o.w;
	}
	state_t(int _v, ll _w):
		v(_v), w(_w) {}
};

vector<pair<int, ll>> adj[MxN];
ll dist[MxN], w;
priority_queue<state_t> pq;

signed main(int argc, char *argv[]) {
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for(int i=1, u, v; i<=n; ++i) {
		cin >> u >> v >> w;
		adj[u].emplace_back(v, w);
		adj[v].emplace_back(u, w);
	}
	for(int i=1; i<=n; ++i) {
		dist[i] = 1e18 + 100ll;
	}
	pq.emplace(1, dist[1] = 0ll);
	while(!pq.empty()) {
		state_t now = pq.top(); pq.pop();
		for(auto x: adj[now]) {
			ll nxt = now.w + x.second;
			if(dist[x.first] > nxt) {
				pq.emplace(x.first, dist[x.first] = nxt);
				visited[x.first] = true;
			}
		}
	}	
	cout << (dist[n] >= 1e18 + 100ll ? -1: dist[n]) << "\n";
	return 0;
}
