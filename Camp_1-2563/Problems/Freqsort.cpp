#include<bits/stdc++.h>
using namespace std;

struct A{
	int cnt=0, idx, val;
	bool operator < (const A& o) const{
		if(cnt != o.cnt){
			return cnt > o.cnt;
		}
		return val < o.val;
	}
};

int32_t main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, c, x;
	cin >> n >> c;

	vector<A>v(c+1);
	for(int i=0; i<=n; ++i){
		v[i].val = i;
	}
	for(int i=0; i<n; ++i){
		cin >> x;
		v[x].cnt++;
		v[x].val;
	}
	sort(v.begin(), v.end());
	for(int i=0; i<=c; ++i){
		if(v[i].cnt!=0){
			while(v[i].cnt--){
				cout << v[i].val << " ";
			}
		}
	}
	cout << endl;
	return 0;
}
