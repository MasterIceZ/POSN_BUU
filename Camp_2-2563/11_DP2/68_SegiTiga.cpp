/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * CENTER	: BUU
 * TASK		: Segi Tiga Operation
 * ALGO		: Dynamic Programming
 * DATE		:
 * */
#include<bits/stdc++.h>
using namespace std;

#define dec(x,y) fixed << setprecision(y) << x   
#define all(x) (x).begin(), (x).end()
#define endl '\n'
#define int long long
using LL = long long;

int n, m;
bool dp[333][333][5];

int opr(int a, int b){
	if(a == 0 && b == 2){
		return 0;
	}
	if((a == 0 && b== 0) ||	(a == 1 && b == 0) || (a == 2 && b == 1)){
		return 2;
	}
	return 1;
}

void solve(){
	cin >> n;
	string s;
	cin >> s;
	if(s[0] != '0'){
		cout << "no";
		return ;
	}
	for(int i=0; i<n; ++i){
		dp[i][i][s[i] - '0'] = true;
	}
	for(int sz=1; sz<n; ++sz){
		for(int i=0; i+sz<n; ++i){
			int j = i + sz; 
			for(int k=i; k<j; ++k){
				for(int a=0; a<3; ++a){
					for(int b=0; b<3; ++b){
						if(dp[i][k][a] && dp[k+1][j][b]){
							dp[i][j][opr(a, b)] = 1;
						}
					}
				}
			}
		}
	}
	cout << (dp[0][n-1][0]?"yes":"no");
	return ;
}

int32_t main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int t=1;
//	cin >> t;
	t = 20;
	while(t--){
		solve();
		cout << endl;
		memset(dp, false, sizeof dp);
	}
	return 0;
}
