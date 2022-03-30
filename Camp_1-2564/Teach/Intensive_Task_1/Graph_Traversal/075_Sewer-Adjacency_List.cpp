/*
    Author	: ~Aphrodicez
    Center	: BUU
    Lang	: CPP
    Algo	: Breadth First Search
    Status	: Accepted
*/

#include <bits/stdc++.h>
using namespace std;

struct GRAPH {
    int i, j, w;
};

char a[110][110];
vector <GRAPH> g[110][110];
queue <GRAPH> qu;
int mark[110][110];

int main() {
    int r, c;
    scanf("%d %d", &r, &c);
    for(int i = 1; i <= r; i++) {
        for(int j = 1; j <= c; j++) {
            scanf(" %c", &a[i][j]);
            if(a[i][j] == 'D' || a[i][j] == 'B') {
                g[i][j].push_back({i + 1, j});
                g[i + 1][j].push_back({i, j});
            }
            if(a[i][j] == 'R' || a[i][j] == 'B') {
                g[i][j].push_back({i, j + 1});
                g[i][j + 1].push_back({i, j});
            }
        }
    }
    memset(mark, -1, sizeof mark);
    mark[1][1] = 1;
    qu.push({1, 1, 1});
    while(!qu.empty()) {
        int i = qu.front().i;
        int j = qu.front().j;
        int w = qu.front().w;
        qu.pop();
        for(auto x : g[i][j]) {
            int ii = x.i;
            int jj = x.j;
            if(ii < 1 || jj < 1 || ii > r || jj > c)
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
B R D N
D R B D
R R R D
N N N N

3 4
B B B D
D N R B
R R R N
*/