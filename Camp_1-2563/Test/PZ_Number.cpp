#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

int n, m;

void solve(){
	cin >> n;
	vector<int>v(n);
	for(int i=0; i<n; ++i){
		cin >> v[i];
	}	
	sort(v.begin(), v.end(), greater<int>());
	vector<int>s, t;
	for(int i=0; i<n; ++i){
		if(i == 0){
			s.push_back(v[i]);
			t.push_back(v[i]);
		}
		else{
			s.push_back(s[i-1] + v[i] +t[i-1]);
			t.push_back(v[i] + t[i-1]);
		}
	}
	int q;
	cin >> q;
	while(q--){
		int k;
		cin >> k;
		cout << (upper_bound(s.begin(), s.end(), k) - s.begin())+1 << endl;
	}
	return ;
}

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t = 1;
//	cin >> t;
	while(t--){
		solve();
		cout << endl;
	}

	return 0;
}
