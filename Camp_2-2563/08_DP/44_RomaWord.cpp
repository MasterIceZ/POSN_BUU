/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * CENTER	: BUU
 * TASK		: Roma Word
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

char a[2222], b[2222], c[2222];
int dp[2222][2222], path[2222][2222];

void solve(){
	scanf(" %s %s", a+1, b+1);	
	int lena = strlen(a+1), lenb = strlen(b+1);
	for(int i=1; i<=lena; ++i){
		for(int j=1; j<=lenb; ++j){
			if(a[i] == b[j]){
				dp[i][j] = dp[i-1][j-1] + 1;
				path[i][j] = 1;
			}
			else if(dp[i-1][j] >= dp[i][j-1]){
				dp[i][j] = dp[i-1][j];
				path[i][j] = 2;
			}
			else{
				dp[i][j] = dp[i][j-1];
				path[i][j] = 3;
			}
		}
	}
	printf("%lld\n", dp[lena][lenb]);
	if(!dp[lena][lenb]){
		printf("No Roma word");
		return ;
	}
	int i = lena, j = lenb, ptr = 0;
	while(i > 0 && j > 0){
		if(path[i][j] == 1){
			c[ptr++] = a[i];
			--i, --j;
		}
		else if(path[i][j] == 2){
			--i;
		}
		else{
			--j;
		}
	}
	for(int i=ptr-1; i>=0; --i){
		printf("%c", c[i]);
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
