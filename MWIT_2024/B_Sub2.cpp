#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const ll MOD = 5454541ll;

signed main(int argc, char *argv[]) {
	ios::sync_with_stdio(false);
	ll n;
	cin >> n;
	ll answer = 1ll, k = 2ll;
	for(; n > 0; n /= 2ll, k = (k * k) % MOD) {
		if(n % 2ll == 1ll) {
			answer = (answer * k) % MOD;
		}
	}
	answer = ((answer - 1ll) + MOD) % MOD;
	cout << answer << "\n";
	return 0;
}
