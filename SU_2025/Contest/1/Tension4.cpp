#include <bits/stdc++.h>

using namespace std;
using ll = long long;

inline ll my_sqrt(ll v) {
	ll l = 0, r = v;
	while(l < r) {
		ll mid = (l + r + 1ll) >> 1ll;
		if(mid <= v / mid) {
			l = mid;
		}
		else {
			r = mid - 1ll;
		}
	}
	return l;
}

signed main(int argc, char *argv[]) {
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	ll n, l ,r;
	int q;
	cin >> n >> q;
	while(q--) {
		cin >> l >> r;
		ll inclusion = my_sqrt(r) + my_sqrt(r / 2ll);
		ll exclusion = my_sqrt(l - 1ll) + my_sqrt((l - 1ll) / 2ll);
		cout << inclusion - exclusion << "\n";
	}
	return 0;
}
