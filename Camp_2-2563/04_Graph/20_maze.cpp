/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * CENTER	: BUU
 * TASK		: Maze
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

struct A{
	int i, j, w;
};
const int di[] = {-1, 0, 0, 1}, dj[] = {0, -1, 1, 0};
int a[222][222], dis[2][222][222], x[3], y[3];

void solve(){
	int r, c, mi = INT_MAX, cnt =0;
	cin >> r >> c >> x[0] >> y[0] >> x[1] >> y[1];
	for(int i=1; i<=r; ++i){
		for(int j=1; j<=c; ++j){
			cin >> a[i][j];
			dis[0][i][j] = dis[1][i][j] = INT_MAX;
		}
	}
	for(int i=0; i<=1; ++i){
		queue<A>bfs;
		bfs.push({x[i], y[i], 0});
		while(!bfs.empty()){
			int ii = bfs.front().i;
			int jj = bfs.front().j;
			int ww = bfs.front().w;
			bfs.pop();
			if(dis[i][ii][jj] != INT_MAX){
				continue;
			}
			dis[i][ii][jj] = ww;
			for(int k=0; k<4; ++k){
				int iii = ii + di[k], jjj = jj + dj[k];
				if(iii < 1 || jjj < 1 || iii > r || jjj > c){
					continue;
				}
				if(dis[i][iii][jjj]!=INT_MAX){
					continue;
				}
				if(a[iii][jjj] == 1){
					bfs.push({iii, jjj, ww + 1});
				}
				if(a[iii][jjj] == 0){
					dis[i][iii][jjj] = ww + 1;
				}
			}
		}
	}
	for(int i=1; i<=r; ++i){
		for(int j=1; j<=c; ++j){
			if(a[i][j] == 0 && dis[0][i][j] != INT_MAX && dis[1][i][j] != INT_MAX){
				cnt++;
				if(dis[0][i][j] + dis[1][i][j] + 1 < mi){
					mi = dis[0][i][j] + dis[1][i][j] + 1;
				}
			}
		}
	}
	cout << cnt << " " << mi ;
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
