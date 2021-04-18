#include<bits/stdc++.h>
using namespace std;

#define int long long

char b[1001];

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
	for(int i=1; i<n; ++i){
		nax = max(nax, i - (lower_bound(a.begin(), a.begin()+i-1, a[i]-k)-a.begin()));
	}
	for(int i=1; i<n; ++i){
		nax = max(nax, i - (lower_bound(b.begin(), b.begin()+i-1, b[i]-k)-b.begin()));
	}
	cout << nax;
	return 0;
}
