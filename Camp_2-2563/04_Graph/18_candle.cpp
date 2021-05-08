/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * CENTER	: BUU
 * TASK		: Candle
 * ALGO		: Breadth First Search
 * DATE		: 7 May 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#define dec(x,y) fixed << setprecision(y) << x   
#define all(x) (x).begin(), (x).end()
#define endl '\n'
#define int long long
using LL = long long;

int n, m;

const int d8i[] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int d8j[] = {-1, 0, 1, -1, 1, -1, 0, 1};

char a[2222][2222];

void solve(){
	cin >> n >> m;
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=m; ++j){
			cin >> a[i][j];
		}
	}
	int cnt = 0;
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=m; ++j){
			if(a[i][j] == '1'){
				cnt++;
				queue<pair<int, int>>q;
				q.emplace(i, j);
				while(!q.empty()){
					auto now = q.front();
					q.pop();
					for(int k=0; k<8; ++k){
						if(a[now.first+d8i[k]][now.second+d8j[k]] == '1'){
							a[now.first+d8i[k]][now.second+d8j[k]] = '0';
							q.emplace(now.first + d8i[k], now.second + d8j[k]);
						}
					}
				}
			}
		}
	}
	cout << cnt;
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
