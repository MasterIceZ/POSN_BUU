#include<bits/stdc++.h>
using namespace std;

struct A{
	int id, day;
	bool operator < (const A&o) const{
		if(day!=o.day){
			return day > o.day;
		}
		return id > o.id;
	}
};

int main (){

	int n, k;
	scanf("%d %d", &n, &k);
	priority_queue<A>pq;
	for(int i=1; i<=k; ++i){
		pq.push({i, 0});
	}	
	for(int i=0; i<n; ++i){
		int x;
		scanf("%d", &x);
		auto now = pq.top();
		pq.pop();
		printf("%d\n", now.id);
		now.day += x;
		pq.push(now);
	}

	return 0;
}
