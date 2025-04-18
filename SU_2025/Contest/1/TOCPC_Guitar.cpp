#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MxN = 330;
const ll INF = 1e18 + 100ll;

struct state_t {
	int v;
	ll w;
	int state;
	state_t(int _v, ll _w, int _state):
		v(_v), w(_w), state(_state) {}
	bool operator < (const state_t &o) const {
		return w > o.w;
	}
};

ll a[MxN][MxN], dist[MxN][MxN];
int n, m, k, p[MxN];
priority_queue<state_t> pq;

inline ll get_answer_k0() {
	ll sum = 0ll;
	for(int i=2; i<=m; ++i) {
		sum += a[p[i - 1]][p[i]];
	}
	return sum;
}

signed main(int argc, char *argv[]) {
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	cin >> n >> m >> k;
	if(m <= k) {
		cout << "0\n";
		exit(0);
	}
	for(int i=1; i<=n; ++i) {
		for(int j=1; j<=n; ++j) {
			cin >> a[i][j];
		}
	}
	for(int i=1; i<=m; ++i) {
		cin >> p[i];
	}
	if(k == 0) {
		cout << get_answer_k0() << "\n";
		exit(0);
	}
	memset(dist, 0x3f, sizeof dist);
	pq.emplace(0, dist[0][0] = 0, 0);
	while(!pq.empty()) {
		state_t now = pq.top();
		pq.pop();
		for(int i=now.v + 1; i<=m + 1; ++i) {
			int nxt_state = now.state + (i - (now.v + 1));
			if(nxt_state > k) {
				break;
			}
			ll nxt = now.w + a[p[now.v]][p[i]];
			if(dist[nxt_state][i] > nxt) {
				pq.emplace(i, dist[nxt_state][i] = nxt, nxt_state);
			}
		}	
	}	
	ll min_dist = INF;
	for(int i=0; i<=k; ++i) {
		min_dist = min(min_dist, dist[i][m + 1]);
	}
	cout << min_dist << "\n";
	return 0;
}
