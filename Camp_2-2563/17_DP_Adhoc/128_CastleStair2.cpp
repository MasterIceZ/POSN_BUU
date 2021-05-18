/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * CENTER	: BUU
 * TASK		:
 * ALGO		:
 * DATE		:
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

int qs[100100], qs2[100100], a[100100];

int MOD = 95959;

void solve(){
	int k;
	cin >> n >> k;
	for(int i=1; i<=n; ++i){
		cin >> a[i];
	}	
	qs[1] = 1;
	for(int i=1; i<=n; ++i){
		int idx = lower_bound(a+1, a+n+1, a[i]-k) - (a+1);
		qs[i] += qs[i-1];
		qs[i] %= MOD;
		qs[i] +=qs[i-1];
		qs[i] %= MOD;
		if(a[i] > k){
			qs[i] -= qs[idx];
			qs[i] %= MOD;
		}
		qs[i] += MOD;
		qs[i] %= MOD;
	}
	cout << (qs[n] - qs[n-1] + MOD)%MOD;
	return ;
}

int32_t main(){
	init();
	int t=1;
	cin >> t;
	while(t--){
		solve();
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
