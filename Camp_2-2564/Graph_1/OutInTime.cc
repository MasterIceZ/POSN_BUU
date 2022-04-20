/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: PN_Out In Time
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

const int MxN = 33;
char a[MxN][MxN];
queue<pair<int, int>> q;
set<pair<int, int>> st;

const int di[] = {-1, 0, 0, 1}, dj[] = {0, -1, 1, 0};
int dist[33][33];
bool visited[33][33];

inline void solution(){
	memset(dist, -1, sizeof dist);
	memset(visited, false, sizeof visited);
	st.clear();
	int n, m, t;
	cin >> n >> m >> t;
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=m; ++j){
			cin >> a[i][j];
		}
	}
	pair<int, int> stp, edp;
	cin >> stp.first >> stp.second >> edp.first >> edp.second;
	q.emplace(stp);
	dist[stp.first][stp.second] = 0;
	visited[stp.first][stp.second] = true;
	while(!q.empty()){
		pair<int, int> now = q.front();
		q.pop();
		for(int k=0; k<4; ++k){
			int ii = now.first + di[k];
			int jj = now.second + dj[k];
			if(ii < 1 || jj < 1 || ii > n || jj > m){
				continue;
			}
			if(a[ii][jj] == '.' && !visited[ii][jj]){
				st.emplace(ii, jj);
				q.emplace(ii, jj);
				dist[ii][jj] = 1 + dist[now.first][now.second];
				visited[ii][jj] = true;
			}
		}
	}
	if(dist[edp.first][edp.second] > t || dist[edp.first][edp.second] == -1){
		cout << "-1";
	}
	else{
		cout << (1 + min((t - dist[edp.first][edp.second]) / 2 + dist[edp.first][edp.second], (int) st.size()));
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
