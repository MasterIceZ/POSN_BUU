#include <bits/stdc++.h>

using namespace std;

const int MxN = 500050;

long long a[MxN], b[MxN], c[MxN];

signed main(int argc, char *argv[]) {
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for(int i=1; i<=n; ++i) {
		cin >> a[i];
	}
	for(int i=1; i<=n; ++i) {
		cin >> b[i];
	}
	sort(a + 1, a + n + 1);
	sort(b + 1, b + n + 1, greater<long long>());
	for(int i=1; i<=n; ++i) {
		c[i] = a[i] + b[i];
	}
	cout << *max_element(c + 1, c + n + 1) - *min_element(c + 1, c + n + 1) << "\n";
	return 0;
}
