#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const ll MOD = 5454541ll;
const int MxN = 110;

ll a[MxN];

signed main(int argc, char *argv[]) {
  cin.tie(nullptr)->ios::sync_with_stdio(false);
  int n;
  cin >> n;
  for(int i=0; i<n; ++i) {
    cin >> a[i];
  }
  int max_state = (1 << n) - 1;
  ll cnt = 0ll;
  for(int state=1; state<=max_state; ++state) {
    int bit_count = __builtin_popcount(state);
    ll sum = 0ll;
    for(int i=0; i<n; ++i) {
      if((1 << i) & state) {
        sum += a[i];
      }
    }
    if(sum % bit_count == 0ll) {
      cnt = (cnt + 1ll) % MOD;
    }
  }
  cout << cnt << "\n";
  return 0;
}