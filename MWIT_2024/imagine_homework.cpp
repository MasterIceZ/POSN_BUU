#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MxN = 100010;

priority_queue<ll> pq;
vector<int> t[MxN];

signed main(int argc, char *argv[]) {
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int d, n, m;
	ll a;
	cin >> n >> m;
	for(int i=1; i<=m; ++i) {
		cin >> a >> d;
		t[d].emplace_back(a);
	}
	ll answer = 0ll;
	for(int i=n; i>=1; --i) {
		for(auto h: t[i]) {
			pq.emplace(h);
		}
		if(!pq.empty()) {
			answer += pq.top(); pq.pop();
		}
	}
	cout << answer << "\n";
	return 0;
}
