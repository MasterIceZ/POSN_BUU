/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: PeatPacman
 * ALGO		: Breadth First Search
 * DATE		: 18 Apr 2022
 * */

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>

#ifndef _DEBUG
// @==== Libary ====@ //

// @================@ //
#endif

using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;

template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update> ;

// @=== Debugger ===@ //
#ifdef _DEBUG
#include "debug.hpp"
#else
#define dbg(...) 0
#endif
// @================@ //

using ll = long long;

struct Tile{
	pair<int, int> position;
	int w;
	Tile(int a, int b, int c): position({a, b}), w(c) {}
	Tile(pair<int, int> a, int b): position(a), w(b) {}
};

const int MxN = 770;
int g_dist[MxN][MxN];
bool visited[MxN][MxN];
char a[MxN][MxN];
queue<pair<int, int>> q;
queue<Tile> qq;

const int di[] = {-1, 0, 0, 1};
const int dj[] = {0, -1, 1, 0};

inline void solution(){
	memset(g_dist, 0x3f, sizeof g_dist);
	memset(visited, false, sizeof visited);
	int n, m, tt, ghosts;
	pair<int, int> stp;
	cin >> n >> m >> ghosts >> tt >> stp.first >> stp.second;
	stp.first++, stp.second++;
	for(int i=1; i<=ghosts; ++i){
		int t, x, y;
		cin >> t >> x >> y;
		x++, y++;
		if(g_dist[x][y] > t){
			g_dist[x][y] = t;
			q.emplace(x, y);
		}
	}
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=m; ++j){
			cin >> a[i][j];
		}
	}
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
			int nxt = 1 + g_dist[now.first][now.second];
			if(g_dist[ii][jj] > nxt){
				g_dist[ii][jj] = nxt;
				q.emplace(ii, jj);
			}
		}
	}
	qq.emplace(stp, 0);
	int answer = 0;
	visited[stp.first][stp.second] = true;
	while(!qq.empty()){
		Tile now = qq.front();
		qq.pop();
		answer = max(answer, g_dist[now.position.first][now.position.second]);
		dbg(now.position, now.w);
		for(int k=0; k<4; ++k){
			int ii = di[k] + now.position.first;
			int jj = dj[k] + now.position.second;
			if(ii < 1 || jj < 1 || ii > n || jj > m){
				continue;
			}
			if(visited[ii][jj] || a[ii][jj] == '#' || g_dist[ii][jj] <= now.w + 1){
				continue;
			}
			visited[ii][jj] = true;
			qq.emplace(ii, jj, now.w + 1);
		}
	}
	if(answer - tt > 0){
		cout << "YES";
	}
	else{
		cout << "NO " << answer-1;
	}
	return ;
}

signed main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);	
	int q = 1;
	cin >> q;
	while(q--){
		solution();
		cout << "\n";
	}
	return 0;
}
// https://github.com/MasterIceZ/archive/tree/main/cpp-template
