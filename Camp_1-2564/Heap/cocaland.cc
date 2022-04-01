#include <bits/stdc++.h>
using namespace std;

struct Plant{
	int beauty, type, expire, next;
	Plant(int a, int b, int c, int d=-1): beauty(a), type(b), expire(c), next(d) {}
	bool operator < (const Plant& o) const {
		if(beauty != o.beauty){
			return beauty > o.beauty;
		}
		return expire < o.expire;
	}
};

signed main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int q;
	cin >> q;
	priority_queue<Plant> pq;
	for(int i=1, opr, x, y, z; i<=q; ++i){
		cin >> opr;
		if(opr == 1){
			cin >> x >> y;
			pq.emplace(x, 1, y);
		}
		else if(opr == 2){
			cin >> x;
			pq.emplace(x, 2, q + 10);
		}
		else if(opr == 3){
			cin >> x >> y >> z;
			pq.emplace(x, 3, y, z);
		}
		else{
			while(!pq.empty() && pq.top().expire < i){
				Plant now = pq.top();
				pq.pop();
				if(now.type == 3){
					pq.emplace(now.next, 1, q + 10);
				}
			}
			if(pq.empty()){
				cout << "GREAN";
			}
			else{
				cout << pq.top().beauty ;
				pq.pop();
			}
			cout << "\n";
		}
	}
	return 0;
}
