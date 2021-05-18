/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * CENTER	: BUU
 * TASK		: RT_Hire Friend
 * ALGO		: Sweepline
 * DATE		: 17 May 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#define dec(x,y) fixed << setprecision(y) << x   
#define all(x) (x).begin(), (x).end()
#define endl '\n'
#define int long long
using LL = long long;
void init();
int n, m;

void solve(){
	cin >> n;
	map<int, int>mp;
	for(int i=0, s, e; i<n; ++i){
		cin >> s >> e;
		mp[s]++;
		mp[e+1]--;
	}	
	int qs = 0, last = 0, ans = 0;
	for(auto x: mp){
		if(qs > 1){
			ans += (qs-1) * (x.first - last);
		}
		qs += x.second;
		last = x.first;
	}
	cout << ans;
	return ;
}

int32_t main(){
	init();
	int t=1;
//	cin >> t;
	while(t--){
		solve();
		cout << endl;
	}
	return 0;
}
void init(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	#ifdef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	return ;
}
