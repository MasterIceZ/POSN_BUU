#include<bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	cin >> n >> k;
	vector<int>a(n), b(n);
	for(int i=0; i<n; ++i){
		cin >> a[i] >> b[i];
	}
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	int nax = INT_MIN;
	for(int i=0; i<n; ++i){
		nax = max(nax, i - (lower_bound(a.begin(), a.end(), a[i]-k)-a.begin()));
	}
	for(int i=0; i<n; ++i){
		nax = max(nax, i - (lower_bound(b.begin(), b.end(), b[i]-k)-b.begin()));
	}
	cout << nax;
	return 0;
}
