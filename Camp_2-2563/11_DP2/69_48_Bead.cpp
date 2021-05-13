/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * CENTER	: BUU
 * TASK		: 48_Bead
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
int a[111];
int dp[111][111];

void solve(){
	priority_queue<int>q;
	cin >> n;
	for(int i=0, x; i<n; ++i){
		cin >> x;
		q.push(x);
	}
	
	return ;
}

int32_t main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int t=1;
	cin >> t;
	while(t--){
		solve();
		cout << endl;
		memset(dp, 0, sizeof dp);
		memset(a, 0, sizeof a);
	}
	return 0;
}
