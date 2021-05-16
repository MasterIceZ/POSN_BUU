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

double pos[33][33], dp[33][1100000];

double play(int now, int bit){
	if(now == n){
		return 1;
	}
	if(dp[now][bit] != -1){
		return dp[now][bit];
	}
	double nax = 0;
	for(int i=0; i<n; ++i){
		if((bit&(1<<i)) == 0){
			nax = max(nax, pos[now][i] * play(now+1, bit|(1<<i)));
		}
	}
	return dp[now][bit] = nax;
}

void solve(){
	cin >> n;
	for(int i=0; i<n; ++i){
		for(int j=0; j<n; ++j){
			cin >> pos[i][j];
			pos[i][j] /= 100;
		}
	}	
	for(int i=0; i<n; ++i){
		for(int j=0; j<(1<<n); ++j){
			dp[i][j] = -1;
		}
	}
	cout << fixed << setprecision(2) << play(0, 0) * 100;
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
