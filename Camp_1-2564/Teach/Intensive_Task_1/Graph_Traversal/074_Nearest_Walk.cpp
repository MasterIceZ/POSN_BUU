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
const int dj[] = {0, 1, 0, -1};

struct GRAPH {
    int i, j, w;
};

char a[1010][1010];
queue <GRAPH> qu;
int mark[1010][1010];

int main() {
    int q;
    scanf("%d", &q);
    while(q--) {
        memset(mark, -1, sizeof mark);
        int r, c;
        scanf("%d %d", &r, &c);
        int sti, stj, eni, enj;
        for(int i = 1; i <= r; i++) {
            scanf(" %s", a[i] + 1);
            for(int j = 1; j <= c; j++) {
                if(a[i][j] == 'A')
                    sti = i, stj = j;
                if(a[i][j] == 'B')
                    eni = i, enj = j;
            }
        }
        mark[sti][stj] = 0;
        qu.push({sti, stj, 0});
        while(!qu.empty()) {
            int i = qu.front().i;
            int j = qu.front().j;
            int w = qu.front().w;
            qu.pop();
            if(i == eni && j == enj) {
                break;
            }
            for(int k = 0; k < 4; k++) {
                int ii = i + di[k];
                int jj = j + dj[k];
                if(ii < 1 || jj < 1 || ii > r || jj > c)
                    continue;
                if(a[ii][jj] == '#')
                    continue;
                if(mark[ii][jj] != -1)
                    continue;
                mark[ii][jj] = mark[i][j] + 1;
                qu.push({ii, jj, mark[ii][jj]});
            }
        }
        printf("%d\n", mark[eni][enj]);
        while(!qu.empty())
            qu.pop();
    }
    return 0;
}

/*
2
4 5
#A.#.
..#.B
.#..#
....#
4 5
#A.#.
..#.B
.#..#
..#.#
*/