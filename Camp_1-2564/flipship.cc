#include <bits/stdc++.h>
using namespace std;

inline void solve(){
	int n;
	cin >> n;
	int cnt[] = {0, 0};
	for(int i=1, x; i<=n; ++i){
		cin >> x;
		if(x){
			cnt[i % 2]++;
		}
	}
	if(n % 2 || abs(cnt[0] - cnt[1]) <= 1){
		cout << "YES";
	}
	else{
		cout << "NO";
	}
}

signed main(){
	int q;
	cin >> q;
	while(q--){
		solve();
		cout << "\n";
	}
	return 0;
}
