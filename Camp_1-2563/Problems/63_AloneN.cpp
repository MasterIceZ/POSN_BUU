#include<bits/stdc++.h>
using namespace std;
int main () {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int q;

	cin >> q;
	while(q--){
		int n, x;
		cin >> n;
		map<int, int> mp;
		vector<int>v(n);
		for(int i=0; i<n; ++i){
			cin >> v[i];
			mp[v[i]]++;
		}
		bool ch = false;
		for(int i=0; i<n; ++i){
			if(mp[v[i]] < 2){
				cout << v[i] << " ";
				ch = true;
			}	
		}
		if(!ch){
			cout << "No Alone Num";
		}
		cout << endl;
	}
	return 0;
}
