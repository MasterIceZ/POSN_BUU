#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll s, sum, maxx, a[1000100];

void solve(){
	int n;
	cin >> n;
	s = 0, sum = 0, maxx = -1e9;
	for(int i=1; i<=n; ++i){
		cin >> a[i];
		if(i % 2){
			a[i] = -a[i];
		}
		sum += a[i];
	}
	for(int i=1; i<=n; ++i){
		s += a[i];
		if(s < 0){
			s = 0;
		}
		maxx = max(maxx, s);
	}
	cout << sum - 2 * maxx;
}

signed main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int q;
	cin >> q;
	while(q--){
		solve();
		cout << "\n";
	}	
	return 0;
}
