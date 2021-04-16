#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n, q;
	cin >> n >> q;
	vector<int>v(n);
	for(auto&x : v){
		cin >> x;
	}
	sort(v.begin(), v.end());
	while(q--){
		int f;
		cin >> f;
		cout << upper_bound(v.begin(), v.end(), f) - v.begin();
		cout << endl;
	}
	return 0;
}
