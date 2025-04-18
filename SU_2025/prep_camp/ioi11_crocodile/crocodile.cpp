#include "crocodile.h"
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MxN = 100010;
const ll INF = 1e18 + 100;

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
ll dist[2][MxN];
bitset<MxN> visited;

int travel_plan(int N, int M, int R[][2], int L[], int K, int P[]) {
	for(int i=0; i<M; ++i) {
		int u = R[i][0], v = R[i][1];
		ll w = (ll) L[i];
		adj[u].emplace_back(v, w);
		adj[v].emplace_back(u, w);
	}
	memset(dist, 0x3f, sizeof dist);
	for(int i=0; i<K; ++i) {
		int u = P[i];
		pq.emplace(u, dist[0][u] = 0ll);
	}
	while(!pq.empty()) {
		state_t now = pq.top();
		pq.pop();
		if(visited[now.v]) {
			continue;
		}
		visited[now.v] = true;
		for(auto x: adj[now.v]) {
			ll nxt = now.w + x.second;
			if(dist[1][x.first] > nxt) {
				dist[1][x.first] = nxt;
				if(dist[1][x.first] < dist[0][x.first]) {
					swap(dist[1][x.first], dist[0][x.first]);
				}
				if(dist[1][x.first] < INF) {
					pq.emplace(x.first, dist[1][x.first]);
				}
			}
		}
	}
	return dist[1][0];
}
