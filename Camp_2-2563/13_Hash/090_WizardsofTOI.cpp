/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * CENTER	: BUU
 * TASK		: Widzards of TOI
 * ALGO		: Hash Table
 * DATE		: 13 May 2021
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

const int MxN = 5000011;
int x[4][1555], y[4][1555], hashtable[MxN];
int keep[2][MxN];

void solve(){
	int xt, yt;
	cin >> xt >> yt >> n;
	for(int i=0; i<4; ++i){
		for(int j=0; j<n; ++j){
			cin >> x[i][j] >> y[i][j];
		}
	}
	for(int i=0; i<n; ++i){
		for(int j=0; j<n; ++j){
			int r = x[0][i] + x[1][j];
			int s = y[0][i] + y[1][j];
			int t = ((r+(3*s)%MxN)%MxN + MxN)%MxN;
			while(hashtable[t]!=0){
				++t; t%=MxN;
			}
			hashtable[t] = (1500*i) + j + 1;
			keep[0][t] = r;
			keep[1][t] = s;
		}
	}
	for(int i=0; i<n; ++i){
		for(int j=1; j<n; ++j){
			int r = xt - (x[2][i]+x[3][j]);
			int s = yt - (y[2][i]+y[3][j]);
			int t = ((r+(3*s)%MxN)%MxN + MxN)%MxN;
			while(hashtable[t]!=0){
				if(keep[0][t] == r && keep[1][t] == s){
					int p = hashtable[t] - 1;
					cout << x[0][p/1500] << " ";
					cout << y[0][p/1500] << endl;
					cout << x[1][p%1500] << " ";
					cout << y[1][p%1500] << endl;
					cout << x[2][i] << " " ;
					cout << y[2][i] << endl;
					cout << x[3][j] << " " ;
					cout << y[3][j] << endl;
					return ;
				}
				++t, t %= MxN;
			}
		}
	}
	return ;
}

int32_t main(){
	init();
	int t=1;
//	cin >> t;
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
