/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * CENTER	: BUU
 * TASK		: Medal TOI15
 * ALGO		: Greedy
 * DATE		: 11 May 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#define dec(x,y) fixed << setprecision(y) << x   
#define all(x) (x).begin(), (x).end()
#define endl '\n'
#define int long long
using LL = long long;

int n, m;

void solve(){
	cin >> n;
	vector<int>v(n), w(n);
	for(auto& x: v){
		cin >> x;
	}
	for(auto& x: w){
		cin >> x;
	}
	sort(all(v));
	sort(all(w), greater<int>());
	vector<int>y;
	for(int i=0; i<n; ++i){
		y.push_back(v[i] + w[i]);
	}
	sort(all(y));
	int ans = 0;
	for(int i=1; i<n; ++i){
		ans += y[i] - y[i-1];
	}
	cout << ans;
	return ;
}

int32_t main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int t=1;
//	cin >> t;
	while(t--){
		solve();
		cout << endl;
	}
	return 0;
}
