/*
    Author	: ~Aphrodicez
    Center	: BUU
    Lang	: CPP
    Algo	: Heap
    Status	: Accepted
*/

#include <bits/stdc++.h>
using namespace std;

priority_queue <int, vector <int>, greater <int> > pq;

int main() {
    int q;
    scanf("%d", &q);
    while(q--) {
        char opr;
        scanf(" %c", &opr);
        if(opr == 'A') {
            int val;
            scanf("%d", &val);
            pq.push(val);
            continue;
        }
        if(opr == 'B') {
            if(pq.empty()) {
                printf("-1\n");
                continue;
            }
            printf("%d\n", pq.top());
            pq.pop();
        }
    }
    return 0;
}

/*
9
A 7
A 3
A 5
A 3
B
A 4
B
B
B
*/