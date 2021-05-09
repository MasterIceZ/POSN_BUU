/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * CENTER	: BUU
 * TASK		: toi13_robot
 * ALGO		: Breadth First Search
 * DATE		: 8 May 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#define dec(x,y) fixed << setprecision(y) << x   
#define all(x) (x).begin(), (x).end()
#define endl '\n'
#define int long long
using LL = long long;

int n, m;
int layer[2222][2222];
char a[2222][2222];

const int di[] = {-1, 0, 0, 1}, dj[] = {0, -1, 1, 0};

void solve(){
	cin >> n >> m;
	memset(layer, -1, sizeof layer);
	queue<pair<int, int>>q;
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=m; ++j){
			cin >> a[i][j];
			if(a[i][j] == 'X'){
				a[i][j] = 'E';
				q.emplace(i, j);
				layer[i][j] = 0;
			}
		}
	}
	int cnt = 0, ans = 0;
	while(!q.empty()){
		auto now = q.front();
		q.pop();
		if(a[now.first][now.second] == 'A'){
			ans += 2* layer[now.first][now.second];
			cnt++;
		}
		for(int k=0; k<4; ++k){
			int ii = now.first + di[k], jj = now.second + dj[k];
			if(ii < 1 || jj < 1 || ii > n || jj > m || a[ii][jj] == 'W'){
				continue;
			}
			if(layer[ii][jj] < layer[now.first][now.second] && layer[ii][jj] > -1){
				continue;
			}
			if(layer[ii][jj] != -1){
				continue;
			}
			layer[ii][jj] = layer[now.first][now.second] + 1;
			q.emplace(ii, jj);
		}
	}
	cout << cnt << " " << ans;
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
