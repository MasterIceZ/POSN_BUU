#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;

signed main(int argc, char *argv[]) {
  registerGen(argc, argv, 1);
  int N = opt<int> ("n");
  int MIN_X = opt<int> ("min-x");
  int MAX_X = opt<int> ("max-x");
  
  cout << N << "\n";
  for(int i=1; i<=N; ++i) {
    int x = rnd.next(MIN_X, MAX_X);
    cout << x << " \n"[i == N];
  }
  return 0;
}