/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: PM2.5
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

const int MxN = 1010;
char a[MxN][MxN];
int dist[MxN][MxN];

const int di[] = {-1, 0, 0, 1}, dj[] = {0, -1, 1, 0};

inline void solution(){
	int n, m;
	cin >> n >> m;
	memset(dist, -1, sizeof dist);
	queue<pair<int, int>> q;
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=m; ++j){
			cin >> a[i][j];
			if(a[i][j] == 'E'){
				q.emplace(i, j);
				dist[i][j] = 0;
			}
		}
	}
	int to_s = -1;
	while(!q.empty()){
		pair<int, int> now = q.front();
		q.pop();
		if(a[now.first][now.second] == 'S'){
			to_s = dist[now.first][now.second];
		}
		for(int k=0; k<4; ++k){
			int ii = di[k] + now.first;
			int jj = dj[k] + now.second;
			if(ii < 1 || jj < 1 || ii > n || jj > m){
				continue;
			}
			if(a[ii][jj] == '#' || dist[ii][jj] != -1){
				continue;
			}
			dist[ii][jj] = dist[now.first][now.second] + 1;
			q.emplace(ii, jj);
		}
	}
	int res = 0;
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=m; ++j){
			if(dist[i][j] != -1 && isdigit(a[i][j]) && dist[i][j] <= to_s){
				res += a[i][j] - '0';
			}
		}
	}
	cout << (to_s == -1? -1: res);
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
