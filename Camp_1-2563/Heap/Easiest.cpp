#include<bits/stdc++.h>
using namespace std;

int main (){
	int q;
	scanf("%d", &q);
	priority_queue<int, vector<int>, greater<int>>pq;
	while(q--){
		char opr;
		scanf(" %c", &opr);
		if(opr=='A'){
			int x;
			scanf("%d", &x);
			pq.push(x);
		}
		else{
			if(pq.empty()){
				printf("-1\n");
			}
			else{
				printf("%d\n", pq.top());
				pq.pop();
			}
		}
		
	}	

	return 0;
}
