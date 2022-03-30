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
    int idx, days;
    bool operator < (const HEAP &o) const {
        if(days != o.days) 
            return days > o.days;
        return idx > o.idx;
    }
};

priority_queue <HEAP> pq;

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    for(int i = 1; i <= k; i++) {
        pq.push({i, 0});
    }
    for(int i = 1; i <= n; i++) {
        int t;
        scanf("%d", &t);
        HEAP top = pq.top();
        pq.pop();
        printf("%d\n", top.idx);
    /*
        top.days += t;
        pq.push(top);
    */
        pq.push({top.idx, top.days + t});
    }
    return 0;
}

/*
6 3
3
1
2
2
2
1
*/