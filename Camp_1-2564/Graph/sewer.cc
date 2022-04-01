#include <bits/stdc++.h>
using namespace std;

const int MxN = 110;
char a[MxN][MxN];
vector<pair<int, int>> adj[MxN][MxN];
int visited[MxN][MxN];

signed main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=m; ++j){
			cin >> a[i][j];
			if(a[i][j] == 'R' || a[i][j] == 'B'){
				adj[i][j].emplace_back(i, j + 1);
				adj[i][j + 1].emplace_back(i, j);
			}
			if(a[i][j] == 'D' || a[i][j] == 'B'){
				adj[i][j].emplace_back(i + 1, j);
				adj[i + 1][j].emplace_back(i, j);
			}
		}
	}
	memset(visited, -1, sizeof visited);
	visited[1][1] = 1;
	queue<pair<int, int>> q;
	q.emplace(1, 1);
	while(!q.empty()){
		pair<int, int> now = q.front();
		q.pop();
		for(auto x: adj[now.first][now.second]){
			if(visited[now.first][now.second] + 1 > visited[x.first][x.second] && visited[x.first][x.second] != -1){
				continue;
			}
			if(visited[now.first][now.second] + 1 == visited[x.first][x.second]){
				cout << visited[x.first][x.second] << "\n" << x.first << " " << x.second << "\n";
				return 0;
			}
			visited[x.first][x.second] = visited[now.first][now.second] + 1;
			q.emplace(x);
		}
	}
	return 0;
}
