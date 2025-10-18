/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: o64_feb_c2_kon
 * ALGO		: Math
 * DATE		: 16 Jan 2022
 * */
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int query[] = {9,      30, 1219, 50220,  124609, 508394,
                     649424, 882660, 945595, 1000000};

vector<int> v;

void c(int& n, int i) {
  while (n % i == 0) {
    n /= i;
    v.push_back(i);
  }
}

void solve(int n) {
  v.clear();
  c(n, 4);
  c(n, 6);
  for (int i = 2; i <= sqrt(n); ++i) {
    if (n % i == 0) {
      c(n, i);
    }
  }
  if (n != 1) {
    v.push_back(n);
  }
  sort(v.begin(), v.end());
  for (auto x : v) {
    cout << "AC";
    for (int i = 1; i <= x; ++i) {
      cout << "V";
    }
  }
  return;
}

int main() {
  cin.tie(nullptr)->ios::sync_with_stdio(false);
  cout << "10\n";
  for(int i=0; i<10; ++i) {
    cout << i + 1 << "\n";
    solve(query[i]);
    cout << "\n";
  }
  return 0;
}