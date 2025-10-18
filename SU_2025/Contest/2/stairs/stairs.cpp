#include <bits/stdc++.h>
#include "stairs.h"

using namespace std;
using ll = long long;

const int MAT_SIZE = 100;
const ll MOD = 1e9 + 7ll;

int countWays(long long N, int M, std::vector<int> S){
  matrix_t<mint, MAT_SIZE> answer, lift;
  answer[0][0] = 1ll;
  for(int i=1; i<MAT_SIZE; ++i) {
    lift[i][i - 1] = 1ll;
  }
  for(auto s: S) {
    lift[0][s - 1] = 1ll;
  }
  for(; N>0; N>>=1ll, lift=lift*lift) {
    if(N & 1ll) {
      answer = lift * answer;
    }
  }
  int res = (int) static_cast<ll> (answer[0][0]);
  return res;
}
