#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll x;

inline void solve() {
	int n;
	cin >> n;
	set<ll> st;
	for(int i=1; i<=n; ++i) {
		cin >> x;
	   	ll to_add = x;
		while(st.count(to_add)) {
			st.erase(to_add);
			to_add++;
		}
		st.emplace(to_add);
	}
	cout << *st.rbegin() - ((ll) st.size()) + 1ll << "\n";
}

signed main(int argc, char *argv[]) {
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int q;
	cin >> q;
	while(q--) {
		solve();
	}
	return 0;
}
