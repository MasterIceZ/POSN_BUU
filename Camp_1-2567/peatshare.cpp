// PEATT SHARE

#include <bits/stdc++.h>

using namespace std;

const int MxN = 100010;

int a[MxN], pref_sum[MxN];

signed main(int argc, char *argv[]) {
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int q;
	cin >> q;
	while(q--) {
		int n;
		cin >> n;
		for(int i=1; i<=n; ++i) {
			cin >> a[i];
			pref_sum[i] = pref_sum[i - 1] + a[i];
		}
		if(pref_sum[n] % 2 != 0) {
			cout << "NO\n";
			continue;
		}
		int half = pref_sum[n] / 2;
		bool done = false;
		// CASE: NO NEED TO CYCLIC
		for(int i=1; i<=n; ++i) {
			if(pref_sum[i] == half) {
				cout << i << "\n";
				done = true;
				break;
			}
		}
		if(done) {
			continue;
		}
		// CASE: NEED TO CYCLIC
		for(int i=1; i<=n; ++i) {
			int idx = lower_bound(pref_sum + 1, pref_sum + n + 1, pref_sum[i] + half) - (pref_sum + 1);
			if(pref_sum[i] + half == pref_sum[idx + 1]) {
				cout << i << " " << idx + 1 << "\n";
				done = true;
				break;
			}
		}
		if(done) {
			continue;
		}
		cout << "NO\n";
	}
	return 0;
}
