#include<bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	vector<int>v(n);
	for(auto &x : v){
		cin >> x;
	}
	sort(v.begin(), v.end());
	if(n <3){
		cout << "no";
	}
	else if(v[0] + v[1] > v[n-1]){
		cout << "no";
	}
	else{
		cout << "yes";
	}
	cout << endl;

	return 0;
}
