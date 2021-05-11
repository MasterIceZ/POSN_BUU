/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * CENTER	: BUU
 * TASK		: Oh My God Word
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
char a[1010];

void solve(){
//	string a;
//	cin >> a;
	scanf(" %s", a);
//	int len = a.size();
	int len = strlen(a);
	for(int i=0; i<len; ++i){
		dp[i][i] = 1;
	}	
	int nax = 1, att = 0;
	for(int i=len-2; i>=0; --i){
		if(a[i] == a[i+1]){
			dp[i][i+1] = 1;
			nax = 2;
			att = i;
		}
	}
	for(int k=3; k<=len; ++k){
		for(int i=0; i<=len; ++i){
			int j = i + k - 1;
			if(dp[i+1][j-1] == 1 && a[i] == a[j]){
				dp[i][j] = 1;
				if(k > nax){
					nax = k, att = i;
				}
			}
		}
	}
	for(int i=att; i<att+nax; ++i){
//		cout << a[i];
		printf("%c", a[i]);
	}
	printf("\n");
	return ;
}

int32_t main(){
//	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int t=1;
//	cin >> t;
	while(t--){
		solve();
//		cout << endl;
	}
	return 0;
}
