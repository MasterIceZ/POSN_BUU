#include <bits/stdc++.h>
using namespace std;

char a[1010][1010];
int dp[1010][1010];

// dp[i][j] = size of largest square which have (i, j) at bottom right

// dp[i][j] = 1 + min(dp[i - 1][j - 1], dp[i][j - 1], dp[i - 1][j])

int main() {
  int n, m, i, j, maxx = 0;
  scanf("%d %d", &n, &m);
  for (i = 1; i <= n; ++i) {
    for (j = 1; j <= m; ++j) {
      scanf(" %c", &a[i][j]);
    }
  }
  for (i = 1; i <= n; ++i) {
    for (j = 1; j <= m; ++j) {
      if(a[i][j] == '#') {
        dp[i][j] = 0;
      }
      else {
        dp[i][j] = 1 + min({dp[i - 1][j - 1], 
                          dp[i][j - 1], 
                          dp[i - 1][j]
                      });
      }
      maxx = max(maxx, dp[i][j]);
    }
  }
  printf("%d\n", maxx);

  return 0;
}