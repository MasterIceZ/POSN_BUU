// Matrix Expo

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MxN = 7;
const int MxS = 66; // log2(1e18)

struct matrix_t {
	ll a[MxN][MxN];
};

ll n, MOD;
matrix_t base[MxS];

matrix_t mul(matrix_t a, matrix_t b) {
	matrix_t r;
	for(int i=1; i<=n; ++i) {
		for(int j=1; j<=n; ++j) {
			r.a[i][j] = 0ll;
			for(int k=1; k<=n; ++k) {
				r.a[i][j] += a.a[i][k] * b.a[k][j];
				r.a[i][j] %= MOD;
			}
		}
	}
	return r;
}

signed main(int argc, char *argv[]) {
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	cin >> n;
	for(int i=1; i<=n; ++i) {
		for(int j=1; j<=n; ++j) {
			cin >> base[0].a[i][j];
		}
	}
	ll b;
	cin >> b >> MOD;
	matrix_t answer;
	for(int i=1; i<=n; ++i) {
		for(int j=1; j<=n; ++j) {
			if(i == j) {
				answer.a[i][j] = 1ll % MOD;
			}
			else {
				answer.a[i][j] = 0ll;
			}
		}
	}
	for(int i=1; i<=63; ++i) {
		base[i] = mul(base[i - 1], base[i - 1]);
	}
	for(ll i=0; i<=63ll; ++i) {
		if((1ll << i) & b) {
			answer = mul(base[i], answer);
		}
	}
	for(int i=1; i<=n; ++i) {
		for(int j=1; j<=n; ++j) {
			cout << answer.a[i][j] << " " ;
		}
		cout << "\n";
	}
	return 0;
}
