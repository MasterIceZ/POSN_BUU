/*
    Author	: ~Aphrodicez
    Center	: BUU
    Lang	: CPP
    Algo	: Heap
    Status	: Accepted
*/

#include <bits/stdc++.h>
using namespace std;

struct HEAP {
    int id, rank, qu;
    bool operator < (const HEAP &o) const {
        if(rank != o.rank) 
            return rank < o.rank;
        return qu > o.qu;
    }
};

priority_queue <HEAP> pq;

int main() {
    int n, r;
    scanf("%d %d", &n, &r);
    for(int i = 1; i <= n; i++) {
        int opr;
        scanf("%d", &opr);
        if(opr == 1) {
            int id, rank;
            scanf("%d %d", &id, &rank);
            pq.push({id, rank, i});
        }
        if(opr == 2) {
            if(pq.empty()) {
                printf("-1\n");
                continue;
            }
            printf("%d\n", pq.top().id);
            pq.pop();
            continue;
        }
    }
    return 0;
}

/*
6 5
2
1 20 4
1 11 4
2
1 3 5
2
*/