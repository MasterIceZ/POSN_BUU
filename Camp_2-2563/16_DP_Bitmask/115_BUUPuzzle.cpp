/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * CENTER	: BUU
 * TASK		: BUU Puzzle
 * ALGO		: Dynamic Programming with Bit-mask
 * DATE		: 16 May 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#define dec(x,y) fixed << setprecision(y) << x   
#define all(x) (x).begin(), (x).end()
#define endl '\n'
using LL = long long;
void init();
int n, m;

int s[] = {0, 1, 2 ,4 , 5, 8, 9, 10, 16, 17, 18, 20, 21};
int dp[33][50050], a[5][50050];

void solve(){
	cin >> n;
	for(int i=0; i<5; ++i){
		for(int j=0; j<n; ++j){
			cin >> a[i][j];
		}
	}
	int sum = 0;
	for(int j=0; j<n; ++j){
		for(int i=0; i<13; ++i){
			sum = 0;
			for(int k=0; k<5; ++k){
				if(s[i]&(1<<k)){
					sum += a[k][j];
				}
			}
			for(int k=0; k<13; ++k){
				if((s[i]&s[k])==0){
					dp[i][j+1] = max(dp[i][j+1], dp[k][j] + sum);
				}
			}
		}
	}
	int ans = 0;
	for(int i=0; i<13; ++i){
		ans = max(ans, dp[i][n]);
	}
	cout << ans;
	memset(dp, 0, sizeof dp);
	return ;
}

int32_t main(){
	init();
	int t=1;
	cin >> t;
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
