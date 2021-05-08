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
char a[33][33];
bool visited[33][33];
int layer[33][33];
const int di[] = {-1, 0, 0, 1}, dj[] = {0, -1, 1, 0};

void solve(){
	memset(visited, false, sizeof visited);
	memset(layer, -1, sizeof layer);
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
	set<pair<int, int>>s;
	q.emplace(start);
	layer[start.first][start.second] = 0;
	while(!q.empty()){
		auto now = q.front();
		q.pop();
//		cerr << "pop~\n";
//		if(q.empty()){
//			cerr << "empty!\n";
//		}
		if(visited[now.first][now.second]){
			continue;
		}
		visited[now.first][now.second] = true;
		for(int k=0; k<4; ++k){
			int ii = now.first + di[k];
			int jj = now.second + dj[k];
			if(ii < 1 || jj < 1 || ii > n || jj > m){
				continue;
			}
			if(a[ii][jj] != '#' && !visited[ii][jj]){
				q.emplace(ii, jj);
				layer[ii][jj] = layer[now.first][now.second]+1;
				s.emplace(ii, jj);
			}
		}
	}
//	cerr << "size : "<< s.size() << endl;
//	cout << (layer[stop.first][stop.second]<=t?layer[stop.first][stop.second]:-1);
	if(layer[stop.first][stop.second] > t || layer[stop.first][stop.second] == -1){
		cout << -1;
		return;
	}
	int le = t - layer[stop.first][stop.second];
	le = min(le/2 + layer[stop.first][stop.second], (int)s.size());
//	cout << "left : " << le << endl;
//	cout << "size : " << s.size() << endl;
//	cout << layer[stop.first][stop.second] + le + 1;
	cout << le +1;
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
