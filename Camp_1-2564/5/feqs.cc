#include <bits/stdc++.h>
using namespace std;

struct A{
	int v, id, c;
	bool operator < (const A& o) const {
		if(c != o.c){
			return c > o.c;
		}
		return id < o.id;
	}
	A(int x, int y, int z): v(x), id(y), c(z) {}
};

int main(){
	int n, c;
	cin >> n >> c;
	map<int, int> mp, id;
	for(int i=1, x; i<=n; ++i){
		cin >> x;
		mp[x]++;
		if(!id[x]){
			id[x] = i;
		}
	}
	vector<A> v;
	for(auto x: mp){
		v.emplace_back(x.first, id[x.first], x.second);
	}
	sort(v.begin(), v.end());
	for(auto x: v){
		while(x.c--){
			cout << x.v << " ";
		}
	}
	cout << "\n";
	return 0;
}
