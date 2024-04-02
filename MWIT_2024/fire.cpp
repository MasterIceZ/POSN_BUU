#include <bits/stdc++.h>

using namespace std;

const int MxN = 1010;

vector<int> t[MxN * 2];
priority_queue<int> pq;

signed main(int argc, char *argv[]) {
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int n, answer = 0, x;
	cin >> n;
	for(int i=1; i<=n; ++i) {
		for(int j=1; j<=n; ++j) {
			cin >> x;
			t[i + j].emplace_back(x);
		}
	}
	for(int i=n+n; i>=3; --i) {
		for(auto cur: t[i]) {
			pq.emplace(cur);
		}
		answer += pq.top(); pq.pop();
	}
	cout << answer << "\n";
	return 0;
}
