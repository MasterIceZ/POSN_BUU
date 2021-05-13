/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * CENTER	: BUU
 * TASK		: Choose the Jobs
 * ALGO		: Dynamic Programming
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

struct A{
	int s, e, w;
	bool operator < (const A& o)const{
		if(e!=o.e){
			return e < o.e;
		}
		return s < o.s;
	}
};
A a[100100];
int b[100100], dp[100100];

void solve(){
	cin >> n;
	for(int i=1; i<=n; ++i){
		cin >> a[i].s >> a[i].e >> a[i].w;
	}
	sort(a+1, a+n+1);
	for(int i=1; i<=n; ++i){
		b[i] = a[i].e;
	}
	for(int i=1; i<=n; ++i){
		int idx = lower_bound(b+1, b+n+1, a[i].s) - (b+1);
		dp[i] = max(dp[i-1], dp[idx] + a[i].w);
	}
	cout << dp[n];
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
