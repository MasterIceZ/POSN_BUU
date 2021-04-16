#include<bits/stdc++.h>
using namespace std;

#define int long long

int a[500100];

int32_t main () {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	for(int i=1; i<=n; ++i){
		cin >> a[i];
	}
	sort(a+1, a+n+1);
	int sum = 0;
	for(int i=1; i<=n; ++i){
		sum += (a[i]*2) + (a[i] - a[i-1]);
	}
	sum += n + a[n];
	cout << sum;

	return 0;
}
