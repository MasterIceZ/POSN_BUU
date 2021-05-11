/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * CENTER	: BUU
 * TASK		: Kuth Coin
 * ALGO		: Dynamic Programming
 * DATE		: 9 May 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#define dec(x,y) fixed << setprecision(y) << x   
#define all(x) (x).begin(), (x).end()
#define endl '\n'
#define int long long
using LL = long long;

int n, m;

int coin[] = {1, 5, 10, 25, 50};
int dp[100100];
const int MOD = 1000003;
void nugget(){
	dp[0] = 1;
	for(int i=0; i<5; ++i){
		for(int j=coin[i]; j<=100000; ++j){
			if(j - coin[i] < 0){
				continue;
			}
			dp[j] += dp[j - coin[i]];
			dp[j] %= MOD;
		}
	}
}

void solve(){
	cin >> n;
	cout << dp[n] ;
	return ;
}

int32_t main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int t=1;
	nugget();
	cin >> t;
	while(t--){
		solve();
		cout << endl;
	}
	return 0;
}
