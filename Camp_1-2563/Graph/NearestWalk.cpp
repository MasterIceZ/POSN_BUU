#include<bits/stdc++.h>
using namespace std;
char a[1111][1111];
int dist[1111][1111];

const int di[] = {-1, 0, 0, 1}, dj[] = {0, -1, 1, 0};

void solve(){
	int n, m;
	scanf("%d %d", &n, &m);
	pair<int, int> start, stop;
	for(int i=0; i<n; ++i){
		for(int j=0; j<m; ++j){
			char x;
			scanf(" %c",&a[i][j]);
			if(a[i][j] == 'A'){
				start = make_pair(i, j);
			}
			if(a[i][j] == 'B'){
				stop = make_pair(i, j);
			}
		}
	}
	memset(dist, -1, sizeof dist);
	queue<pair<int, int>>q;
	q.push(start);
	dist[start.first][start.second] = 0;
	while(!q.empty()){
		auto now = q.front();
		int i = now.first, j = now.second;
		q.pop();
		for(int k=0; k<4; ++k){
			int ii = i + di[k],  jj = j + dj[k];
			if(ii<0 || jj<0 ||ii>=n || jj>=m){
				continue;
			}
			if(a[ii][jj] == '#' || dist[ii][jj] != -1){
				continue;
			}
			dist[ii][jj] = dist[i][j]+1;
			q.push(make_pair(ii, jj));
		}
	}
	printf("%d\n", dist[stop.first][stop.second]);
	return ;
}

int main (){
	int t;
	scanf("%d", &t);
	while(t--){
		solve();
	}
	return 0;
}
