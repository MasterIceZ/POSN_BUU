#include<bits/stdc++.h>
using namespace std;

queue<int>q[100100];
priority_queue<int>pq;

int main (){

	int n, r;
	scanf("%d %d", &n, &r);
	while(n--){
		int opr;
		scanf("%d", &opr);
		if(opr == 2){
			printf("%d\n", pq.empty()?-1:q[pq.top()].front());
			if(!pq.empty()){
				q[pq.top()].pop();
				if(q[pq.top()].empty()){
					pq.pop();
				}
			}
		}
		else{
			int x, y;
			scanf("%d %d", &x, &y);
			q[y].push(x);
			if(q[y].size() == 1){
				pq.push(y);
			}
		}
	}
	return 0;
}
