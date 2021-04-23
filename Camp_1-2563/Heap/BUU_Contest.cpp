#include<bits/stdc++.h>
using namespace std;

#define int long long

int32_t main (){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int d, k;
	cin >> d >> k;	
	priority_queue<int>pq;
	int ans = 0;
	for(int i=0; i<d; ++i){
		int n, m;
		cin >> n >> m;
		for(int j=0; j<n; ++j){
			int x;
			cin >> x;
			pq.push(x-i*k);
		}
		for(int j=0; j<m; ++j){
			ans += pq.top()+i*k;
			pq.pop();
		}
	}
	cout << ans;

	return 0;
}
