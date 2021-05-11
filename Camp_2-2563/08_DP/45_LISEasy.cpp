/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * CENTER	: BUU
 * TASK		: LIS easy
 * ALGO		: Dynamic Programming
 * DATE		: 9 May 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#define dec(x,y) fixed << setprecision(y) << x   
#define all(x) (x).begin(), (x).end()
#define endl '\n'
#define int long long
using LL = long long;

int n, m;
int a[1111], dp[1111], path[1111], ans[1111];

void solve(){
	cin >> n;
	for(int i=1; i<=n; ++i){
		cin >> a[i];
		dp[i] = -1;
	}
	dp[1] = 1, path[1] = 0;
	int att = 0, nax = 0;
	for(int i=1; i<=n; ++i){
		for(int j=1; j<i; ++j){
			if(a[j] < a[i] && (dp[j] + 1 > dp[i] || dp[i] == -1)){
				dp[i] = dp[j]+1;
				path[i] = j;
			}
		}
		if(dp[i] == -1){
			dp[i] = 1;
		}
		if(dp[i] > nax){
			nax = dp[i], att = i;
		}
	}
	cout << nax << endl;
	for(int i=0; i<nax; ++i){
		ans[i] = a[att];
		att = path[att];
	}
	for(int i=0; i<nax; ++i){
		cout << ans[nax - 1 -i] << " ";
	}
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
