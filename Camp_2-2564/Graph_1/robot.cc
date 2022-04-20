/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: toi13_robot
 * ALGO		: Breadth First Search
 * DATE		: 19 Apr 2022
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

const int MxN = 2020;
queue<pair<int, int>> q;
char a[MxN][MxN];
ll dist[MxN][MxN];

const int di[] = {-1, 0, 0, 1}, dj[] = {0, -1, 1, 0};

inline void solution(){
	memset(dist, -1, sizeof dist);
	int n, m;
	cin >> n >> m;
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=m; ++j){
			cin >> a[i][j];
			if(a[i][j] == 'X'){
				a[i][j] = 'E';
				dist[i][j] = 0;
				q.emplace(i, j);
			}
		}
	}
	ll cnt = 0, d = 0;
	while(!q.empty()){
		pair<int, int> now = q.front();
		q.pop();
		if(a[now.first][now.second] == 'A'){
			cnt++;
			d += 2 * dist[now.first][now.second];
		}
		for(int k=0; k<4; ++k){
			int ii = now.first + di[k];
			int jj = now.second + dj[k];
			if(ii < 1 || jj < 1 || ii > n || jj > m){
				continue;
			}
			if(dist[ii][jj] != -1 || a[ii][jj] == 'W'){
				continue;
			}
			q.emplace(ii, jj);
			dist[ii][jj] = dist[now.first][now.second] + 1;
		}
	}
	cout << cnt << " " << d;
	return ;
}

signed main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);	
	int q = 1;
//	cin >> q;
	while(q--){
		solution();
		cout << "\n";
	}
	return 0;
}
// https://github.com/MasterIceZ/archive/tree/main/cpp-template
