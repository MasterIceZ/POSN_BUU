// Matrix Expo

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MxN = 3;
const int MxS = 66; // log2(1e18)
const ll MOD = 1e9 + 7ll;

struct matrix_t {
	ll a[MxN][MxN];
	matrix_t() {
		memset(a, 0, sizeof a); 
	}
};

matrix_t base[MxS];

matrix_t mul(matrix_t a, matrix_t b) {
	matrix_t r;
	for(int i=1; i<=2; ++i) {
		for(int j=1; j<=2; ++j) {
			r.a[i][j] = 0ll;
			for(int k=1; k<=2; ++k) {
				r.a[i][j] += a.a[i][k] * b.a[k][j];
				r.a[i][j] %= MOD;
			}
		}
	}
	return r;
	}

ll calc(ll idx) {
	matrix_t answer;
	answer.a[1][1] = 9; answer.a[1][2] = 0;
	answer.a[2][1] = 6; answer.a[2][2] = 0;
	for(ll i=63; i>=0; --i) {
		if(idx & (1ll << i)) {
			answer = mul(base[i], answer);
		}
	}
	return answer.a[2][1];
}

signed main(int argc, char *argv[]) {
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	base[0].a[1][1] = 1; base[0].a[1][2] = 1;
	base[0].a[2][1] = 1; base[0].a[2][2] = 0;
	for(int i=1; i<=63; ++i) {
		base[i] = mul(base[i - 1], base[i - 1]);
	}
	int q;
	cin >> q;
	while(q--) {
		ll l, r;
		cin >> l >> r;
		r++;
		cout << ((calc(r) - calc(l)) % MOD + MOD) % MOD << "\n";
	}
	return 0;
}
