/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * CENTER	: BUU
 * TASK		: PT_PM2.5
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
char mp[1111][1111];
int dist[1111][1111];
const int di[] = {-1, 0, 0, 1}, dj[] = {0, -1, 1, 0};

void solve(){
	int r, c, d=-1, ans=0, ii, jj;
	cin >> r >> c;
	memset(dist, -1, sizeof dist);
	queue<pair<int, int>> q;
	for(int i=1; i<=r; ++i){
		for(int j=1; j<=c; ++j){
			cin >> mp[i][j];
			if(mp[i][j] == 'E'){
				q.emplace(i, j);
				dist[i][j] = 0;
			}
		}
	}
	while(!q.empty()){
		auto f = q.front();
		q.pop();
		for(int k=0; k<4; ++k){
			ii = f.first + di[k], jj = f.second + dj[k];
			if(ii < 1 || jj < 1 || ii > r || jj > c){
				continue;
			}
			if(mp[ii][jj] == '#' || dist[ii][jj] != -1){
				continue;
			}
			dist[ii][jj] = dist[f.first][f.second] + 1;
			if(mp[ii][jj] == 'S'){
				d = dist[ii][jj];
			}
			q.emplace(ii, jj);
		}
	}
	for(int i=1; i<=r; ++i){
		for(int j=1; j<=c; ++j){
			if(dist[i][j] != -1 && dist[i][j] <= d && mp[i][j] >= '0' && mp[i][j] <= '9'){
				ans += mp[i][j] - '0';
			}
		}
	}
	cout << (d==-1?-1:ans);
	return ;
}

int32_t main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int t=1;
	cin >> t;
	while(t--){
		solve();
		cout << endl;
	}
	return 0;
}
