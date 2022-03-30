/*
    Author	: ~Aphrodicez
    Center	: BUU
    Lang	: CPP
    Algo	: Breadth First Search
    Status	: Accepted
*/

#include <bits/stdc++.h>
using namespace std;

const int di[] = {-1, 0, 1, 0};
const int dj[] = {0, -1, 0, 1};
const char dc[] = {'D', 'R', 'D', 'R'};

struct GRAPH {
    int i, j, w;
};

char a[110][110];
queue <GRAPH> qu;
int mark[110][110];

int main() {
    int r, c;
    scanf("%d %d", &r, &c);
    for(int i = 1; i <= r; i++) {
        scanf(" %s", a[i] + 1);
    }
    memset(mark, -1, sizeof mark);
    mark[1][1] = 1;
    qu.push({1, 1});
    while(!qu.empty()) {
        int i = qu.front().i;
        int j = qu.front().j;
        int w = qu.front().w;
        qu.pop();
        for(int k = 0; k < 4; k++) {
            int ii = i + di[k];
            int jj = j + dj[k];
            int chi = ii, chj = jj;
            if(k >= 2)
                chi = i, chj = j;
            if(ii < 1 || jj < 1 || ii > r || jj > c)
                continue;
            if(a[chi][chj] != dc[k] && a[chi][chj] != 'B')
                continue;
            if(mark[ii][jj] == mark[i][j] + 1) {
                printf("%d\n", mark[ii][jj]);
                printf("%d %d\n", ii, jj);
                return 0;
            }
            if(mark[ii][jj] != -1)
                continue;
            mark[ii][jj] = mark[i][j] + 1;
            qu.push({ii, jj, mark[ii][jj]});
        }
    }
    return 0;
}

/*
4 4
BRDN
DRBD
RRRD
NNNN

3 4
BBBD
DNRB
RRRN
*/