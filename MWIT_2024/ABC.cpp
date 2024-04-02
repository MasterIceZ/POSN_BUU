#include <bits/stdc++.h>

using namespace std;
using ll = long long;

signed main(int argc, char *argv[]) {
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int q;
	cin >> q;
	while(q--) {
		string s;
		cin >> s;
		int n = s.size();
		s = " " + s;
		vector<ll> a(n + 1, 0ll), c(n + 1, 0ll);
		for(int i=1; i<=n; ++i) {
			a[i] = (s[i] == 'A');
			c[i] = (s[i] == 'C');
			a[i] += a[i - 1];
			c[i] += c[i - 1];
		}
		ll answer = 0ll;
		for(int i=1; i<=n; ++i) {
			if(s[i] != 'B') {
				continue;
			}
			answer += (a[i - 1]) * (c[n] - c[i]);
		}
		cout << answer << "\n";
	}
}
