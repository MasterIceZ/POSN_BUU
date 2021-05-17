/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * CENTER	: BUU
 * TASK		: Castle Stair
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

int a[100100];
int qs[100100];

int MOD = 95959;

void solve(){
	int k;
	cin >> n >> k;
	for(int i=1; i<=n; ++i){
		cin >> a[i];
	}
	qs[1] = 1, qs[2] = 1;
	for(int i=3; i<=n; ++i){
		qs[i] = 2*qs[i-1];
		int idx = lower_bound(a+1, a+n+1, a[i]+k) - (a+1);
		cout << "idx : " << idx << endl;
		if(a[i] + k < a[idx]){
			qs[i] -= qs[n - idx + 1];
			cout << "haha" << endl;
		}
		qs[i] %= MOD;
		qs[i] += MOD;
		qs[i] %= MOD;
	}
	for(int i=1; i<=n; ++i){
		cout << qs[i] << " ";
	}
	cout << endl;
	cout << (qs[n] + MOD)%MOD;
	return ;
}

int32_t main(){
	init();
	int t=1;
	cin >> t;
	while(t--){
		solve();
//		cout << endl;
		cout << endl;
		memset(qs, 0, sizeof qs);
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
