#include <bits/stdc++.h>

using namespace std;
using ll = long long;

multiset<ll> ms;
vector<ll> v, mem, answer;

inline void solve() {
	int n, cnt;
	cin >> n;
	cnt = (1 << n);
	v.resize(cnt);
	mem.clear();
	answer.clear();
	ms.clear();
	for(auto &x: v) {
		cin >> x;
	}
	sort(v.begin(), v.end());
	for(int i=1; i<cnt; ++i) {
		ll want = -1;
		if(!ms.empty()) {
			want = *ms.begin();
		}
		if(v[i] == want) {
			// done
			ms.erase(ms.begin());
		}
		else {
			answer.emplace_back(v[i]);
			int cur_sz = (int) mem.size();
			for(int j=0; j<cur_sz; ++j) {
				ms.emplace(v[i] + mem[j]);
				mem.emplace_back(v[i] + mem[j]);
			}
			mem.emplace_back(v[i]);
		}
	}
	for(auto x: answer) {
		cout << x << " ";
	}
	return ;
}

signed main(int argc, char *argv[]) {
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--) {
		solve();
		cout << "\n";
	}
	return 0;
}
