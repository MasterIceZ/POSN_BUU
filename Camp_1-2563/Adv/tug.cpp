#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) (x).begin(), (x).end()
const int INF = 1e9+7;
int32_t main (){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	vector<int>v(n), w(n);
	for(auto &x: v){
		cin >> x;
	}
	for(auto &x: w){
		cin >> x;
	}
	sort(all(v));
	sort(all(w));
	int ans = 0;
	for(int i=0; i<n; ++i){
		ans += abs(v[i] - w[i]);
	}
	cout << ans;
	return 0;
}
