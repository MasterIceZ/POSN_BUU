/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * CENTER	: BUU
 * TASK		: Sewer
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

char a[111][111];
vector<pair<int, int>>g[111][111];
int layer[111][111];

void solve(){
	memset(layer, -1, sizeof layer);
	cin >> n >> m;
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=m; ++j){
			cin >> a[i][j];
			if(a[i][j] == 'R' || a[i][j] == 'B'){
				g[i][j].emplace_back(i, j+1);
				g[i][j+1].emplace_back(i, j);
			}
			if(a[i][j] == 'D' || a[i][j] == 'B'){
				g[i][j].emplace_back(i+1, j);
				g[i+1][j].emplace_back(i, j);
			}
		}
	}
	layer[1][1] = 1;
	queue<pair<int, int>>q;
	q.emplace(1, 1);
	while(!q.empty()){
		auto now = q.front();
		q.pop();
		for(auto x: g[now.first][now.second]){
			if(layer[now.first][now.second] + 1 > layer[x.first][x.second] &&
				layer[x.first][x.second] != -1){
				continue;
			}
			if(layer[now.first][now.second] + 1 == layer[x.first][x.second]){
				cout << layer[x.first][x.second] << endl;
				cout << x.first << " " << x.second;
				return ;
			}
			layer[x.first][x.second] = layer[now.first][now.second] + 1;
			q.emplace(x.first, x.second);
		}
	}
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
