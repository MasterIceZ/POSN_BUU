#include<bits/stdc++.h>
using namespace std;

struct A{
	int val, idx, cnt;
	bool operator < (const A& o) const{
		if(cnt != o.cnt){
			return cnt > o.cnt;
		}
		return idx < o.idx;
	}
};

int32_t main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	map<int, int> freq, idx;
	int n, c, x;
	cin >> n >> c;
	for(int i=1;i<=n;++i){
		cin >> x;
		freq[x]++;
		if(idx[x] == 0){
			idx[x] = i;
		}
	}
	vector<A>v;
	for(auto a : freq){
		v.push_back({a.first, idx[a.first], freq[a.first]});
	}
	sort(v.begin(), v.end());
	for(auto f: v){
		while(f.cnt--){
			cout << f.val << " ";
	
		}
	}
	cout << endl;
	return 0;
}
