#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MxN = 2550;
const ll INF = 1e18 + 100;

struct edge_t {
	int u, v;
	ll w;
	edge_t(int _u, int _v, ll _w):
		u(_u), v(_v), w(_w) {}
};

int backtrack[MxN];
ll w, dist[MxN];

signed main(int argc, char *argv[]) {
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	vector<edge_t> edges;
	for(int i=1, u, v; i<=m; ++i) {
		cin >> u >> v >> w;
		edges.emplace_back(u, v, w);
	}
	memset(dist, 0x3f, sizeof dist);
	dist[1] = 0;
	int done = -1;
	for(int r=1; r<=n; ++r) {
		done = -1;
		for(auto edge: edges) {
			ll nxt = dist[edge.u] + edge.w;
			if(dist[edge.v] > nxt) {
				dist[edge.v] = max(nxt, -INF);
				backtrack[edge.v] = edge.u;
				done = edge.v;
			}
		}
	}
	if(done == -1) {
		cout << "NO\n";
		exit(0);
	}
	cout << "YES\n";
	int start_cycle = done;
	for(int i=1; i<=n; ++i) {
		start_cycle = backtrack[start_cycle];
	}
	stack<int> trace;
	int cur = start_cycle;
	while(true) {
		trace.emplace(cur);
		if(cur == start_cycle && (int) trace.size() > 1) {
			break;
		}
		cur = backtrack[cur];
	}
	while(!trace.empty()) {
		cout << trace.top() << " ";
		trace.pop();
	}
	cout << "\n";
	return 0;
}
