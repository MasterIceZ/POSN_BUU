/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * CENTER	: BUU
 * TASK		: Longest
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
const int MxN = 1e3 + 10;
int l[MxN][MxN], u[MxN][MxN], d[MxN][MxN], r[MxN][MxN];
char a[MxN][MxN];

void solve(){
	cin >> n >> m;
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=m; ++j){
			cin >> a[i][j];
			if(a[i][j] == '1'){
				r[i][j] = r[i][j-1] + 1;
			}
			else{
				r[i][j] = 0;
			}
		}
		for(int j=m; j>=1; --j){
			if(a[i][j] == '1'){
				l[i][j] = l[i][j+1] + 1;
			}
			else{
				l[i][j] = 0;
			}
		}
	}
	for(int j=1; j<=m; ++j){
		for(int i=1; i<=n; ++i){
			if(a[i][j] == '1'){
				d[i][j] = d[i-1][j] + 1;
			}
			else{
				d[i][j] = 0;
			}
		}
		for(int i=n; i>=1; --i){
			if(a[i][j] == '1'){
				u[i][j] = u[i+1][j] + 1;
			}
			else{
				u[i][j] = 0;
			}
		}
	}
	int nax = 0;
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=m; ++j){
			nax = max({nax,
					u[i][j] + l[i][j] - 1,
					u[i][j] + r[i][j] - 1,
					d[i][j] + l[i][j] - 1,
					d[i][j] + r[i][j] - 1});
		}
	}
	cout << nax ;
	return ;
}

int32_t main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int t=1;
	cin >> t;
	while(t--){
		solve();
		cout << endl;
		memset(u, 0, sizeof u);
		memset(l, 0, sizeof l);
		memset(r, 0, sizeof r);
		memset(d, 0, sizeof d);	
	}
	return 0;
}
