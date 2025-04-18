#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int asking_primes[] = {
  2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47
};
const int asking_prime_squares[] = {
  4, 9, 25, 49
};

bool ask(int x) {
  cout << x << endl;
  string t;
  cin >> t;
  return t == "yes";
}

void answer(int cnt) {
  if(cnt <= 1) {
    cout << "prime" << endl;
  }
  else {
    cout << "composite" << endl;
  }
  exit(0);
}

signed main(int argc, char *argv[]) {
  vector<int> all_asking;
  all_asking.insert(all_asking.end(), begin(asking_primes), end(asking_primes));
  all_asking.insert(all_asking.end(), begin(asking_prime_squares), end(asking_prime_squares));
  int cnt_divisible = 0;
  for(auto asking: all_asking) {
    bool q = ask(asking);
    cnt_divisible += (q == true);
    if(cnt_divisible == 2) {
      break;
    }
  }
  answer(cnt_divisible);
  return 0;
}