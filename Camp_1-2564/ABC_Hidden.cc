#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MxN = 1e6 + 10;
ll dpA[MxN], dpC[MxN];

void solve(){
	string s;
	cin >> s;
	int n = s.size();
	s = " " + s;
	for(int i=1; i<=n; ++i){
		dpA[i] = dpA[i - 1];
		dpC[i] = dpC[i - 1];
		if(s[i] == 'A'){
			dpA[i]++;
		}
		else if(s[i] == 'C'){
			dpC[i]++;
		}
	}
	ll answer = 0;
	for(int i=1; i<=n; ++i){
		if(s[i] == 'B'){
			answer += dpA[i - 1] * (dpC[n] - dpC[i]);
		}
	}
	cout << answer;
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
