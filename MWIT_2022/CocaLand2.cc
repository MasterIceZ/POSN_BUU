#include <bits/stdc++.h>
using namespace std;

struct A{
	int id, v, d, t;
	bool operator < (const A& o) const {
		if(v != o.v){
			return v > o.v;
		}
		return id > o.id;
	}
	A(int a, int b, int c, int e): id(a), v(b), d(c), t(e) {}
};

priority_queue<A> pq;

int main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int q;
	for(int i=1, opr; i<=q; ++i){
		cin >> opr;
		if(opr == 1){
			int x, y;
			cin >> x >> y;
			pq.emplace(2, x, y, 0);
		}
		else if(opr == 2){
			int x;
			cin >> x;
			pq.emplace(0, 0, 0, );
		}
	}
	return 0;
}
