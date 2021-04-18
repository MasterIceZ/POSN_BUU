#include<bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, x, y;
	cin >> n;
	vector<pair<int, int>> v;
	for(int i=0; i<n; ++i){
		cin >> x >> y;
		v.emplace_back(y, x);
	}	
	double nax = -1e9;
	int ans, ans2,cnt;
	cnt = ans = ans2 = 0;
	v.emplace_back(-1, -1);
	sort(v.begin(), v.end());
	for(int i=1; i<=n; ++i){
		cnt += v[i].second;
		if((double)cnt/(double)v[i].first > nax){
			nax = (double)cnt/ (double)v[i].first;
			ans = (int)cnt;
			ans2 = v[i].first;
		}
	}
	cout << ans << " " << ans2 << endl;
	return 0;
}
