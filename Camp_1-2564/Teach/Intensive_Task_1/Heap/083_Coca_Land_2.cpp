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
    int beauty, death, to, type;
    bool operator < (const HEAP &o) const {
        if(beauty != o.beauty)
            return beauty > o.beauty;
        return death > o.death;
    }
};

priority_queue <HEAP> pq;

int main() {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        int opr;
        scanf("%d", &opr);
        if(opr == 4) {
            while(!pq.empty() && pq.top().death <= i) {
                HEAP top = pq.top();
                pq.pop();
                if(top.type == 3) {
                    top.beauty = top.to;
                    top.death = n + 1;
                    top.to = 0;
                    top.type = 1;
                    pq.push(top);
                }
            }   
            if(pq.empty()) {
                printf("GREAN\n");
                continue;
            }
            printf("%d\n", pq.top().beauty);
            pq.pop();
            continue;
        }
        HEAP plant = {0, n + 1, 0, opr};
        if(opr == 1) {
            int beauty, death;
            scanf("%d %d", &beauty, &death);
            plant.beauty = beauty;
            plant.death = death;
        }
        if(opr == 2) {
            int beauty;
            scanf("%d", &beauty);
            plant.beauty = beauty;
        }
        if(opr == 3) {
            int beauty, death, to;
            scanf("%d %d %d", &beauty, &death, &to);
            plant.beauty = beauty;
            plant.death = death;
            plant.to = to;
        }
        pq.push(plant);
    }
    return 0;
}

/*
11
2 5
4
4
1 10 5
2 15
4
3 20 8 40
2 30
2 45
4
4
*/