#include <bits/stdc++.h>
using namespace std;

const int MxN = 1010;
const int di[] = {-1, 0, 0, 1};
const int dj[] = {0, -1, 1, 0};

int n, m;
char a[MxN][MxN];

void bfs(int start_i, int start_j) {
  queue<pair<int, int>> q;
  q.emplace(start_i, start_j);
  a[start_i][start_j] = '*';
  while (!q.empty()) {
    pair<int, int> now = q.front();
    q.pop();
    for (int k = 0; k < 4; ++k) {
      int nxt_i = now.first + di[k];
      int nxt_j = now.second + dj[k];
      if (nxt_i < 1 || nxt_j < 1 || nxt_i > n || nxt_j > m) {
        // out of bound -> not go
        continue;
      }
      if (a[nxt_i][nxt_j] == '*') {
        continue;
      }
      a[nxt_i][nxt_j] = '*';
      q.emplace(nxt_i, nxt_j);
    }
  }
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int q;
  cin >> q;
  while (q--) {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= m; ++j) {
        cin >> a[i][j];
      }
    }
    int cnt = 0;
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= m; ++j) {
        if (a[i][j] == '*') {
          continue;
        }
        bfs(i, j);
        cnt++;
      }
    }
    cout << cnt << "\n";
  }
}