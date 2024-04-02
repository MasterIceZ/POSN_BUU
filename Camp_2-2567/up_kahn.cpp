// Up Kahn

#include <bits/stdc++.h>

using namespace std;

const int MxN = 100010;

vector<int> adj[MxN];
int in[MxN];
priority_queue<int, vector<int>, greater<int>> pq;

signed main(int argc, char *argv[]) {
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int q, n, m, u, v;
	cin >> q;
	while(q--) {
		cin >> n >> m;
		for(int i=1; i<=m; ++i) {
			cin >> u >> v;
			adj[u].emplace_back(v);
			in[v]++;
		}
		for(int i=1; i<=n; ++i) {
			if(in[i] == 0) {
				pq.emplace(i);
			}
		}
		vector<int> order;
		while(!pq.empty()) {
			int now = pq.top(); pq.pop();
			order.emplace_back(now);
			for(auto x: adj[now]) {
				--in[x];
				if(in[x] == 0) {
					pq.emplace(x);
				}
			}
		}
		if((int) order.size() == n) {
			cout << "Yes ";
			for(auto x: order) {
				cout << x << " ";
			}
		}
		else {
			cout << "No";
		}
		cout << "\n";
		for(int i=1; i<=n; ++i) {
			adj[i].clear();
			in[i] = 0;
		}
	}
}
