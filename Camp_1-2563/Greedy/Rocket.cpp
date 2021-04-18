#include<bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	vector<int>a(n), b(n);
	for(int i=0; i<n; ++i){
		cin >> a[i] >> b[i];
	}		
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	int ans = 0, x;
	for(int i=0; i<m; ++i){
		cin >> x;
		ans += (lower_bound(a.begin(), a.end(), x) - a.begin()) - (upper_bound(b.begin(), b.end(), x) - b.begin());
		ans %= 2007;
	}
	cout << ans;
	return 0;
}
