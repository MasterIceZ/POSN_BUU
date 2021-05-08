/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * CENTER	: BUU
 * TASK		: Electricity
 * ALGO		: Heap
 * DATE		: 6 May 2021
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
	int k;
	cin >> n >> k;
	vector<int>v(n);
	for(auto& x: v){
		cin >> x;
	}	
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.emplace(v[0], 0);
	int ans = 0;
	for(int i=1; i<n; ++i){
		while(!pq.empty() && i - pq.top().second > k){
			pq.pop();
		}
		ans = pq.top().first + v[i];
		pq.emplace(ans, i);
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
