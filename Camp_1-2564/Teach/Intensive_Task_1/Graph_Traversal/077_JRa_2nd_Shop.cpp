/*
    Author	: ~Aphrodicez
    Center	: BUU
    Lang	: CPP
    Algo	: Depth First Search
    Status	: Accepted
*/

#include <bits/stdc++.h>
using namespace std;

vector <int> g[20];
int mark[20];

vector <int> ans;

void dfs(int u, int val) {
    if(mark[u] && u == 2) {
        ans.push_back(val);
        return;
    }
    for(auto x : g[u]) {
        if(mark[x])
            continue;
        mark[x] = 1;
        dfs(x, val * 10 + x);
        mark[x] = 0;
    }
}

int main() {
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(2, 2);
    sort(ans.begin(), ans.end());
    for(auto x : ans) {
        printf("%d\n", x);
    }
    return 0;
}

/*
6
1 2
1 3
1 4
2 3
3 4
3 5
*/