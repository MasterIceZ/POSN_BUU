/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		:
 * ALGO		:
 * DATE		:
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

const int di[] = {-1, 0, 0, 1};
const int dj[] = {0, -1, 1, 0};

const int MxN = 33;
int dist[MxN][MxN];
char a[MxN][MxN];
bool visited[MxN][MxN];

inline void solution(){
	memset(dist, -1, sizeof dist);
	memset(visited, false, sizeof visited);
	int n, m, t;
	cin >> n >> m >> t;
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=m; ++j){
			cin >> a[i][j];
		}
	}
	pair<int, int> stp, edp;
	cin >> stp.first >> stp.second;
	cin >> edp.first >> edp.second;
	queue<pair<int, int>> q;
	q.emplace(stp);
	dist[stp.first][stp.second] = 0;
	int cnt_walked = 0;
	while(!q.empty()){
		pair<int, int> now = q.front();
		q.pop();
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
			if(a[ii][jj] == '#' || visited[ii][jj]){
				continue;
			}
			q.emplace(ii, jj);
			dist[ii][jj] = dist[now.first][now.second] + 1;
			cnt_walked += 1;
		}
	}
	if(dist[edp.first][edp.second] > t || dist[edp.first][edp.second] == -1){
		cout << -1;
		return ;
	}
	int remain = t - dist[edp.first][edp.second];
	remain = 1 + min(remain / 2 + dist[edp.first][edp.second], cnt_walked);
	cout << remain;
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
