#include <bits/stdc++.h>
using namespace std;

const int di[] = {-1, 0, 0, 1};
const int dj[] = {0, -1, 1, 0};

int n, m, dist[2][1010][1010];
queue<pair<int, int>> q;
char a[1010][1010];

inline void bfs(int state){
	while(!q.empty()){
		pair<int, int> now = q.front();
		q.pop();
		for(int k=0; k<4; ++k){
			int ii = di[k] + now.first;
			int jj = dj[k] + now.second;
			if(ii < 1 || jj < 1 || ii > n || jj > m){
				continue;
			}
			if(a[ii][jj] == '#'){
				continue;
			}
			int nxt = dist[state][now.first][now.second] + 1;
			if(nxt < dist[state][ii][jj]){
				q.emplace(ii, jj);
				dist[state][ii][jj] = nxt;
			}
		}
	}
}

int main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	cin >> n >> m;
	pair<int, int> stp, edp;
	vector<pair<int, int>> shop;
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=m; ++j){
			cin >> a[i][j];
			if(a[i][j] == 'A'){
				stp = make_pair(i, j);
			}
			else if(a[i][j] == 'B'){
				edp = make_pair(i, j);
			}
			else if(a[i][j] == 'C'){
				shop.emplace_back(i, j);
			}
		}
	}
	memset(dist, 0x3f, sizeof dist);
	dist[0][stp.first][stp.second] = 0;
	q.emplace(stp);
	bfs(0);
	dist[1][edp.first][edp.second] = 0;
	q.emplace(edp);
	bfs(1);
	int answer = 1e9 + 10;
	for(auto x: shop){
		answer = min(answer, dist[0][x.first][x.second] + dist[1][x.first][x.second]);
	}
	cout << (answer == 1e9 + 10 ? -1: answer);
	return 0;
}
