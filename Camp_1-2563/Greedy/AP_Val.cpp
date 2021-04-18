#include<bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	if(n<0){
		cout << -1 << endl;
		return 0;
	}
	if(n==0){
		cout << 10 << endl;
		return 0;
	}
	if(n<10){
		cout << n << endl;
		return 0;
	}
	vector<int>a;
	for(int i=9; i>=2; --i){
		while(n%i==0){
			a.push_back(i);
			n/=i;
		}
	}	
	if(n!=1){
		cout << -1 << endl;
		return 0;
	}
	sort(a.begin(), a.end());
	for(auto x: a){
		cout << x;
	}
	cout << endl;
	return 0;
}
