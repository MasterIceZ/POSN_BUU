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
const int diBox[] = {0, 0, 1, 1};
const int djBox[] = {0, 1, 0, 1};

struct GRAPH {
    int i, j;
};

char a[40][40];
queue <GRAPH> qu;
int mark[40][40];

int r, c;

bool isValid(int i, int j) {
    bool ch = true;
    for(int k = 0; k < 4; k++) {
        ch = false;
        int ii = i + diBox[k];
        int jj = j + djBox[k];
        if(ii < 1 || jj < 1 || ii > r || jj > c)
            continue;
        if(a[ii][jj] != '.')
            continue;
        ch = true;
    }
    return ch;
}

int main() {
    scanf("%d %d", &r, &c);
    for(int i = 1; i <= r; i++) {
        scanf(" %s", a[i] + 1);
    }
    int i = 1;
    for(int j = 1; j <= c - 1; j++) {
        if(a[i][j] != '.')
            continue;
        if(isValid(i, j)) {
            mark[i][j] = 1;
            qu.push({i, j});
        }
    }
    bool ans = false;
    while(!qu.empty()) {
        int i = qu.front().i;
        int j = qu.front().j;
        qu.pop();
        if(i == r - 1) {
            ans = true;
            break;
        }
        for(int k = 0; k < 4; k++) {
            int ii = i + di[k];
            int jj = j + dj[k];
            if(ii < 1 || jj < 1 || ii > r || jj > c)
                continue;
            if(a[ii][jj] != '.')
                continue;
            if(mark[ii][jj])
                continue;
            if(isValid(ii, jj)) {
                mark[ii][jj] = 1;
                qu.push({ii, jj});
            }
        }
    }
    if(ans)
        printf("YES\n");
    else
        printf("NO\n");
    while(!qu.empty())
        qu.pop();
    return 0;
}

/*
7 14
##..##...#.#..
##..##...#.#..
##.####..#.#..
#...#....#####
..........###.
####...######.
...#..##..###.

7 14
##..##...#.#..
##..##...#.#..
##.####..#.#..
#...#....#####
........#####.
####...######.
...#..##..###.
*/