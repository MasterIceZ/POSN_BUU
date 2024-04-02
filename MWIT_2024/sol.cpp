#include <bits/stdc++.h>

// is `v` ancestor of `u`

using namespace std;
using ll = long long;

const int MxN = 100010;

vector<int> adj[MxN], roots;
int it = 0, in[MxN], out[MxN];

void dfs(int u, int p) {
  in[u] = ++it;
  for(auto x: adj[u]) {
    if(x == p) {
      continue;
    }
    dfs(x, u);
  }
  out[u] = ++it;
}

signed main(int argc, char *argv[]) {
  cin.tie(nullptr)->ios::sync_with_stdio(false);
  int n, m, t;
  cin >> n >> m >> t;
  for(int i=1, u, v; i<=m; ++i) {
    cin >> u >> v;
    adj[u].emplace_back(v);
    adj[v].emplace_back(u);
  }
  for(int i=1, x; i<=t; ++i) {
    cin >> x;
    roots.emplace_back(x);
  }
  for(auto x: roots) {
    dfs(x, 0);
  }
  int q, u, v;
  cin >> q;
  while(q--) {
    cin >> u >> v;
	cerr << "u: " << in[u] << " " << out[u] << "\n";
	cerr << "v: " << in[v] << " " << out[v] << "\n";
    cout << ((in[v] < in[u] && out[u] < out[v]) ? "YES": "NO") << "\n";
  }
  return 0;
}
