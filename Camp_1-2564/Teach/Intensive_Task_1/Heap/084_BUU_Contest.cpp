/*
    Author	: ~Aphrodicez
    Center	: BUU
    Lang	: CPP
    Algo	: Heap
    Status	: Accepted
*/

#include <bits/stdc++.h>
using namespace std;

priority_queue <long long> pq;

int main() {
    long long d, k;
    scanf("%lld %lld", &d, &k);
    long long ans = 0;
    for(long long days = 0; days < d; days++) {
        int n, b;
        scanf("%d %d", &n, &b);
        for(int i = 1; i <= n; i++) {
            long long val;
            scanf("%lld", &val);
            pq.push(val - days * k);
        }
        while(!pq.empty() && b--) {
            ans += pq.top() + days * k;
            pq.pop();
        }
    }
    printf("%lld\n", ans);
    return 0;
}

/*
3 10
5 2
8 4 5 1 10
4 3
14 4 9 14
2 1
20 7
*/