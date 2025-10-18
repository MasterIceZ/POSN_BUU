#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MxN = 100010;
const ll INF = 1e18 + 100ll;

struct state_t {
	int v;
	ll w;
	state_t(int _v, ll _w):
		v(_v), w(_w) {}
	bool operator < (const state_t &o) const {
		return w > o.w;
	}
};

vector<pair<int, ll>> adj[MxN];
priority_queue<state_t> pq;
ll w, dist[MxN];
bitset<MxN> visited;

signed main(int argc, char *argv[]) {
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for(int i=1, u, v; i<=m; ++i) {
		cin >> u >> v >> w;
		adj[u].emplace_back(v, w);
		adj[v].emplace_back(u, w);
	}
	memset(dist, 0x3f, sizeof dist);
	pq.emplace(1, dist[1] = 0ll);
	while(!pq.empty()) {
		auto [u, d] = pq.top();
		pq.pop();
		if(dist[u] > d) {
			continue;
		}
		visited[u] = true;
		for(auto [v, w]: adj[u]) {
			if(dist[v] > w && !visited[v]) {
				pq.emplace(v, dist[v] = w);
			}
		}
	}
	cout << (*max_element(dist + 1, dist + n + 1) < INF 
				? to_string(accumulate(dist + 1, dist + n + 1, 0ll)) 
				: "IMPOSSIBLE"
			) << "\n";
	return 0;
}
