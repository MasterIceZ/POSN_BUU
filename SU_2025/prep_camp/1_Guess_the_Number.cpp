#include <bits/stdc++.h>

using namespace std;
using ll = long long;

bool ask(int x) {
  cout << x << endl;
  string res;
  cin >> res;
  return (res == ">=");
}

void answer(int x) {
  cout << "! " << x << endl;
  exit(0);
}

signed main(int argc, char *argv[]) {
  int l = 1, r = 1000000;
  while(l < r) {
    int mid = (l + r + 1ll) >> 1;
    if(ask(mid)) {
      l = mid;
    }
    else {
      r = mid - 1ll;
    }
  }
  answer(l);
  return 0;
}