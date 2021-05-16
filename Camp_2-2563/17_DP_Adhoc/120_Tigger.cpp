/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * CENTER	: BUU
 * TASK		: Tigger
 * ALGO		: Dynamic Programming
 * DATE		: 16 May 2021
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
int dp[1010][1010], a[1010];

int play(int now, int last){
	if(now < 1 || now > n){
		return 1e9;
	}
	if(dp[now][last]){
		return dp[now][last];
	}
	if(now == n){
		return a[now];
	}
	return dp[now][last] = a[now] + min(play(now+last+1, last+1), play(now-last, last));
}

void solve(){
	cin >> n;
	for(int i=1; i<=n; ++i){
		cin >> a[i];
	}
	cout << play(2, 1);
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
