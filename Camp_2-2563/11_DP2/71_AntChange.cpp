/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * CENTER	: BUU
 * TASK		: Ant Change Word
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
int dp[1010][1010];
char a[1010], b[1010];
void solve(){
	scanf(" %s %s", a+1, b+1);
	int lena = strlen(a+1), lenb = strlen(b+1);
	for(int i=1; i<=lenb; ++i){
		dp[0][i] = i;
	}
	for(int i=1; i<=lena; ++i){
		dp[i][0] = i;
	}
	for(int i=1; i<=lena; ++i){
		for(int j=1; j<=lenb; ++j){
			if(a[i] == b[j]){
				dp[i][j] = dp[i-1][j-1];
			}
			else{
				dp[i][j] = min({dp[i-1][j-1], dp[i][j-1], dp[i-1][j]}) + 1;
			}
		}
	}
	printf("%d", dp[lena][lenb]);
	return ;
}

int32_t main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int t=1;
//	cin >> t;
	scanf("%d", &t);
	while(t--){
		solve();
//		cout << endl;
		printf("\n");
	}
	return 0;
}
