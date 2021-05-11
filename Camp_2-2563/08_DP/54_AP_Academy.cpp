/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * CENTER	: BUU
 * TASK		: AP_Academy
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

int st[1001000], ed[1001000];

void solve(){
	int s, f;
	cin >> s >> f;
	cout << st[f] - ed[s-1];
	return ;
}

int32_t main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	cin >> n;
	int tim = 0;
	for(int i=1, s, f; i<=n; ++i){
		cin >> s >> f;
		st[s]++;
		ed[f]++;
		tim = max({tim, f, s});
	}	
	for(int i=1; i<=1000000; ++i){
		st[i] += st[i-1];
		ed[i] += ed[i-1];
	}
	int t=1;
	cin >> t;
	while(t--){
		solve();
		cout << endl;
	}
	return 0;
}
