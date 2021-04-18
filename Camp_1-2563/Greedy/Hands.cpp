#include<bits/stdc++.h>
using namespace std;

#define int long long

char b[1001];

int32_t main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	cin >> n >> k;
	int sum = 0;
	vector<int>v(n);
	for(auto& x: v){
		cin >> x;
	}	
	sort(v.begin(), v.end(), greater<int>());
	for(int i=0; i<n; i+=k){
		sum += v[i];
	}
	cout << sum << endl;
	return 0;
}
