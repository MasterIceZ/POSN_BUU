/*
    Author	: ~Aphrodicez
    Center	: BUU
    Lang	: CPP
    Algo	: Breadth First Search
    Status	: Accepted
*/

#include <bits/stdc++.h>
using namespace std;

const int di[] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int dj[] = {0, 1, 1, 1, 0, -1, -1, -1};

struct GRAPH {
    int i, j;
};

char a[2010][2010];
queue <GRAPH> qu;

int main() {
    int r, c;
    scanf("%d %d", &r, &c);
    for(int i = 1; i <= r; i++) {
        scanf(" %s", a[i] + 1);
    }
    int ans = 0;
    for(int i = 1; i <= r; i++) {
        for(int j = 1; j <= c; j++) {
            if(a[i][j] == '1') {
                ans++;
                a[i][j] = '0';
                qu.push({i, j});
                while(!qu.empty()) {
                    int i = qu.front().i;
                    int j = qu.front().j;
                    qu.pop();
                    for(int k = 0; k < 8; k++) {
                        int ii = i + di[k];
                        int jj = j + dj[k];
                        if(ii < 1 || jj < 1 || ii > r || jj > c)
                            continue;
                        if(a[ii][jj] != '1')
                            continue;
                        a[ii][jj] = '0';
                        qu.push({ii, jj});
                    }
                }
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}

/*
4 5
10011
00001
01100
10011

4 4
0010
1010
0100
1111
*/