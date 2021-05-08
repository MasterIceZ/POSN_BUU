/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * CENTER	: BUU
 * TASK		: Bar Chart
 * ALGO		: Stack
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
int a[100100], l[100100], r[100100];

void solve(){
	cin >> n;
	for(int i=1; i<=n; ++i){
		cin >> a[i];
	}
	for(int i=1; i<=n; ++i){
		l[i] = i - 1;
		while(l[i] > 0 && a[i] <= a[l[i]]){
			l[i] = l[l[i]];
		}
	}
	for(int i=n; i>=1; --i){
		r[i] = i + 1;
		while(r[i] <= n && a[i] <= a[r[i]]){
			r[i] = r[r[i]];
		}
	}
	int ans = INT_MIN;
	for(int i=1; i<=n; ++i){
		ans = max(ans, (r[i] - l[i] - 1)*a[i]);
	}
	cout << ans;
	memset(a, 0, sizeof a);
	memset(l, 0, sizeof l);
	memset(r, 0, sizeof r);
	return ;
}

int32_t main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int t=1;
	cin >> t;
	while(t--){
		solve();
		cout << endl;
	}
	return 0;
}
