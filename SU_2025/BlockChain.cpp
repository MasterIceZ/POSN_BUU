#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int> > input_tree() {
  int n;
  cin >> n;
  vector<pair<int, int> > edges;
  for (int i = 2, u, v; i <= n; ++i) {
    cin >> u >> v;
    edges.emplace_back(min(u, v), max(u, v));
  }
  sort(edges.begin(), edges.end());
  return edges;
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int t, q;
  cin >> t >> q;
  map<vector<pair<int, int> >, int> cnt;
  for (int i = 1; i <= t; ++i) {
    vector<pair<int, int> > edges = input_tree();
    cnt[edges]++;
  }
  for (int i = 1; i <= q; ++i) {
    vector<pair<int, int> > edges = input_tree();
    cout << cnt[edges] << "\n";
  }
}