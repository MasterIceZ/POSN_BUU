/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * CENTER	: BUU
 * TASK		: Beta Mode
 * ALGO		: Dynamic Programming
 * DATE		: 9 May 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#define dec(x,y) fixed << setprecision(y) << x   
#define all(x) (x).begin(), (x).end()
#define endl '\n'
using LL = long long;

int n, m;

char a[10010], b[10010];
int dp[3][10010];

void solve(){
	int ans = -1, att;
	scanf(" %s %s", a+1, b+1);
	int lena = strlen(a+1), lenb = strlen(b+1);
	for(int i=1; i<=lena; ++i){
		for(int j=1; j<=lenb; ++j){
			if(a[i] != b[j]){
				dp[i%2][j] = 0;
			}
			else{
				dp[i%2][j] = dp[(i-1)%2][j-1] + 1;
				if(dp[i%2][j] > ans){
					ans = dp[i%2][j];
					att = j;
				}
			}
		}
	}
	for(int i=att-ans+1; i<=att; ++i){
		printf("%c", b[i]);
	}
	return ;
}

int32_t main(){
//	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int t=1;
//	cin >> t;
	while(t--){
		solve();
//		cout << endl;
		printf("\n");
	}
	return 0;
}
