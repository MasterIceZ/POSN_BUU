/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * CENTER	: BUU
 * TASK		: Transitive Closure
 * ALGO		: Floyd Warshall
 * DATE		: 13 May 2021
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
int dp[555][555];

void solve(){
	cin >> n;
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=n;++j){
			cin >> dp[i][j];
		}
	}
	for(int k=1; k<=n; ++k){
		for(int i=1; i<=n; ++i){
			for(int j=1; j<=n; ++j){
				dp[i][j] |= dp[i][k] & dp[k][j];
			}
		}
	}
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=n;++j){
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}
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
