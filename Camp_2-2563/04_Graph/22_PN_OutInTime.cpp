/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * CENTER	: BUU
 * TASK		: PN_Out in time
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
int a[33][33];

const int di[] = {-1, 0, 0, 1}, dj[] = {0, -1, 1, 0};

void solve(){
	int t;
	cin >> n >> m >> t;
	pair<int, int> start, stop;
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=m; ++j){
			cin >> a[i][j];
		}
	}	
	cin >> start.first >> start.second >> stop.first >> stop.second;
	queue<pair<int, int>> q;
	q.emplace(start);
	while(!q.empty()){
		auto now = q.front();
		q.pop();
		if(visited[now.first][now.second]){
			continue;
		}
		if(now == stop){
			break;
		}
		for(int k=0; k<4; ++k){
			int ii = now.first + di[k];
			int jj = now.second + dj[k];

		}
	}
	cout << cnt;
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
