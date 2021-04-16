#include<bits/stdc++.h>
using namespace std;

int main () {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	vector<int>v(n);
	for(auto &x : v){
		cin >> x;
	}
	while(m--){
		int x;
		cin >> x;
		int id = upper_bound(v.begin(), v.end(), x) - v.begin();
		cout << (n-id+1) << endl;
	}
	return 0;
}
