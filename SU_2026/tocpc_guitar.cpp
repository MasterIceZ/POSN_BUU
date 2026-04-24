#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>

const int MxN = 330;
const long long INF = 1e18 + 100ll;

struct state_t {
	int v;
	long long w;
	int skip;
	
	state_t(int _v, long long _w, int _skip):
		v(_v), w(_w), skip(_skip) {}

	bool operator < (const state_t &o) const {
		return w > o.w;
	}
};

int s[MxN];
long long a[MxN][MxN], dist[MxN][MxN];

int main(int argc, char *argv[]) {
	std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);
	int n, m, k;
	std::cin >> n >> m >> k;
	for(int i=1; i<=n; ++i) {
		for(int j=1; j<=n; ++j) {
			std::cin >> a[i][j];
		}
	}
	for(int i=1; i<=m; ++i) {
		std::cin >> s[i];
	}
	memset(dist, 0x3f, sizeof dist);
	int source = 0, sink = m + 1;
	std::priority_queue<state_t> pq;
	pq.emplace(source, dist[0][source] = 0, 0);
	while(!pq.empty()) {
		state_t cur = pq.top();
		pq.pop();
		for(int nxt_v=cur.v + 1; nxt_v<=sink; ++nxt_v) {
			int now_skipping = nxt_v - cur.v - 1;
			int nxt_skip = cur.skip + now_skipping;
			if(nxt_skip > k) {
				break;
			}
			long long nxt = cur.w + a[s[cur.v]][s[nxt_v]];
			if(dist[nxt_skip][nxt_v] > nxt) {
				pq.emplace(nxt_v, dist[nxt_skip][nxt_v] = nxt, nxt_skip);
			}
		}
	}
	long long answer = INF;
	for(int i=0; i<=k; ++i) {
		answer = std::min(answer, dist[i][sink]);
	}
	std::cout << answer << "\n";
	return 0;
}
