/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * CENTER	: BUU
 * TASK		: Matrix Chain Multiplication
 * ALGO		: Dynamic Programming
 * DATE		: 10 May 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#define dec(x,y) fixed << setprecision(y) << x   
#define all(x) (x).begin(), (x).end()
#define endl '\n'
#define int long long
using LL = long long;

int n, m;
int r[22], c[22], dp[22][22], path[22][22];

void pr(int l, int r){
	if(l == r){
		cout << "A" << l + 1;
		return ;
	}
	cout << "(";
	pr(l, path[l][r]);
	cout << " x ";
	pr(path[l][r]+1, r);
	cout << ")";
}

void solve(){
	cin >> n;
	for(int i=0; i<n; ++i){
		cin >> r[i] >> c[i];
	}
	for(int sz=1; sz < n; ++sz){
		for(int i=0; i<n-sz; ++i){
			int j = sz + i;
			int nin = INT_MAX;
			for(int k=i; k<j; ++k){
				int now = dp[i][k] + dp[k+1][j] + r[i] * c[k] * c[j];
				if(now < nin){
					nin = now;
					path[i][j] = k;
				}
			}
			dp[i][j] = nin;
		}
	}
	cout << dp[0][n-1];
	pr(0, n-1);
	return ;
}

int32_t main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int t=1;
//	cin >> t;
	while(t--){
		solve();
		cout << endl;
	}
	return 0;
}
