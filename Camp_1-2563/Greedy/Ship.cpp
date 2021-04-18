#include<bits/stdc++.h>
using namespace std;

#define int long long

int a[555], b[555];

int32_t main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	for(int i=1; i<=n; ++i){
		cin >> a[i] >> b[i];
	}
	sort(a+1, a+n+1);
	sort(b+1, b+n+1);
	int cnt = 0;
	for(int i=1; i<=n; ++i){
		cnt += abs(a[i] - i) + abs(b[i] - i);
	}
	cout << cnt << endl;
	return 0;
}
