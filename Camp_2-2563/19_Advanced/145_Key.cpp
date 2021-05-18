/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * CENTER	: BUU
 * TASK		: Key TOI12
 * ALGO		: Dynamic Programming
 * DATE		: 17 May 2021
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

char str[1005], str2[1005], ip[3003];
int dp[1005][1005];

void solve(){
	scanf(" %s", ip+1);
	for(int i=0; i<=n; ++i){
		for(int j=0; j<=m; ++j){
			dp[i][j] = 0;
			if(i!=0 && dp[i-1][j] == i+j-1 && str[i] == ip[i+j]){
				dp[i][j] = i+j;
			}
			if(j!=0 && dp[i][j-1] == i+j-1 && str2[j] == ip[i+j]){
				dp[i][j] = i+j;
			}
		}
	}
	printf((dp[n][m]==n+m)?"Yes":"No");
	return ;
}

int32_t main(){
	int t=1;
	scanf(" %s %s %lld", str+1, str2+1, &t);
//	cin >> t;
	n = strlen(str+1), m = strlen(str2+1);
	while(t--){
		solve();
		printf("\n");
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
