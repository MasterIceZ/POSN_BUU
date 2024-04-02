#include <stdio.h>

const int MxN = 12;

int k, n, m, stp_i, stp_j, edp_i, edp_j, dist[MxN][MxN];
char a[MxN][MxN];

const int di[] = {-1, 0, 0, 1};
const int dj[] = {0, -1, 1, 0};

void rec(int i, int j, int last_di, int last_dj, int steps) {
  // printf("now at (%d, %d) with %d steps\n", i, j, steps);
  for (int k = 0; k < 4; ++k){
    int ii = di[k] + i, jj = dj[k] + j;
    if(ii < 1 || jj < 1 || ii > n || jj > m) {
      continue;
    }
    int next_steps = (last_di == di[k] && last_dj == dj[k] ? steps + 1 : 1);
    int next_dist = dist[i][j] + 1;
    if (next_steps > ::k || a[ii][jj] == '#' || dist[ii][jj] < next_dist)
    {
      
      continue;
    }
    dist[ii][jj] = dist[i][j] + 1;
    rec(ii, jj, di[k], dj[k], next_steps);
  }
}

int main() {
  int q;
  scanf("%d %d", &q, &k);
  while(--q) {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= m; ++j) {
        scanf(" %c", &a[i][j]);
        if(a[i][j] == 's') {
          stp_i = i;
          stp_j = j;
        }
        if(a[i][j] == 'e') {
          edp_i = i;
          edp_j = j;
        }
        dist[i][j] = 1e9 + 100;
      }
    }
    dist[stp_i][stp_j] = 0;
    rec(stp_i, stp_j, -99, -99, 0);
    // for (int i = 1; i <= n; ++i) {
    //   for (int j = 1; j <= m; ++j) {
    //     printf("%d ", dist[i][j]);
    //   }
    //   printf("\n");
    // }
    printf("%d\n", dist[edp_i][edp_j]);
  }
  return 0;
}