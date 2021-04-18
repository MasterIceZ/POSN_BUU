#include<bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	vector<int>a(n), b(n);
	for(auto& x : a){
		cin >> x;
	}
	for(auto& x : b){
		cin >> x;
	}
	int ans = -1e9;
	sort(a.begin(), a.end());
	sort(b.begin(), b.end(), greater<int>());
	for(int i=0; i<n; ++i){
		ans = max(ans, min(a[i],b[i]));
	}	
	cout << ans << endl;

	return 0;
}
