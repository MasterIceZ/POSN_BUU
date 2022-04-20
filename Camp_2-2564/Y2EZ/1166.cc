/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Flower Garden
 * ALGO		: Breadth First Search
 * DATE		: 13 Apr 2022
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
int cnt = 0, maxx = 0, n, m;
char a[MxN][MxN];

queue<pair<int, int>> q;
const int di[] = {-1, 0, 0, 1};
const int dj[] = {0, -1, 1, 0};

inline bool check(int i, int j){
	for(int k=0; k<4; ++k){
		if(a[i + di[k]][j + dj[k]] == '#'){
			return false;
		}	
	}
	return true;
}

inline void bfs(int i, int j){
	if(!check(i, j)){
		return ;
	}
	q.emplace(i, j);
	cnt = 1;
	a[i][j] = '@';
	while(!q.empty()){
		pair<int, int> now = q.front();
		q.pop();
		for(int k=0; k<4; ++k){
			int ii = di[k] + now.first;
			int jj = dj[k] + now.second;
			if(a[ii][jj] == '.' && check(ii, jj)){
				a[ii][jj] = '@';
				if(ii == 1 || jj == 1 || ii == n || jj == m){
					continue;
				}
				q.emplace(ii, jj);
			}
		}
	}
	return ;
}

inline void bfs2(int i, int j){
	q.emplace(i, j);
	a[i][j] = '#';
	cnt = 1;
	while(!q.empty()){
		pair<int, int> now = q.front();
		q.pop();
		for(int k=0; k<4; ++k){
			int ii = di[k] + now.first;
			int jj = dj[k] + now.second;
			if(ii < 1 || jj < 1 || ii > n || jj > m){
				continue;
			}
			if(a[ii][jj] != '@'){
				continue;
			}
			a[ii][jj] = '#';
			q.emplace(ii, jj);
			cnt++;
		}
	}
	maxx = max(cnt, maxx);
}

inline void solution(){
	cin >> n >> m;
	memset(a, '.', sizeof a);
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=m; ++j){
			cin >> a[i][j];
		}
	}
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=m; ++j){
			if(a[i][j] == '.'){
				bfs(i, j);
			}
		}
	}
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=m; ++j){
			if(a[i][j] == '@'){
				bfs2(i, j);
			}
		}
	}
	cout << maxx << "\n";
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
