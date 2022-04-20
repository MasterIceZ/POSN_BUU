/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Buu Opposite
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
using T = pair<pair<int, int>, pair<int, int>>;

const int MxN = 44;
char v[MxN][MxN];
int dist[MxN][MxN][MxN][MxN], dist2[MxN][MxN][MxN][MxN];
 
const int di[] = {-1, 0, 0, 1}, dj[] = {0, -1, 1 ,0};
 
inline void solution(){
	int n, m;
	cin >> n >> m;
	pair<int, int> A, B;
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=m; ++j){
			cin >> v[i][j];
			if(v[i][j] == 'A'){
				A = make_pair(i, j);
			}
			else if(v[i][j] == 'B'){
				B = make_pair(i, j);
			}
		}
	}
	memset(dist, -1, sizeof dist);
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=m; ++j){
			queue<pair<int, int>> q;
			q.emplace(i, j);
			dist[i][j][i][j] = 0;
			while(!q.empty()){
				pair<int, int> now = q.front();
				q.pop();
				for(int k=0; k<4; ++k){
					int ii = now.first + di[k], jj = now.second + dj[k];
					if(ii < 1 || jj < 1 || ii > n || jj > m){
						continue;
					}
					if(v[ii][jj] == '#' || dist[i][j][ii][jj] != -1){
						continue;
					}
					dist[i][j][ii][jj] = dist[i][j][now.first][now.second] + 1;
					q.emplace(ii, jj);
				}	
			}
		}
	}
	if(dist[A.first][A.second][B.first][B.second] == -1){
		cout << -1 << " " << 0;
		return ;
	}
	queue<pair<pair<int, int>, pair<int, int>>> q;
	memset(dist2, -1, sizeof dist2);
	dist2[A.first][A.second][B.first][B.second] = 0;
	q.emplace(A, B);
 
	int step, diff;
	step = diff = INT_MAX;
 
	while(!q.empty()){
		pair<pair<int, int>, pair<int, int>> now = q.front();
		q.pop();
		dbg(now);
 
		if( abs(now.first.first - now.second.first) + abs(now.first.second - now.second.second) <= step){
			if(dist[now.first.first][now.first.second][now.second.first][now.second.second] < step){
				step = dist[now.first.first][now.first.second][now.second.first][now.second.second];
				diff = dist2[now.first.first][now.first.second][now.second.first][now.second.second] + 1;
			}
			else if(dist[now.first.first][now.first.second][now.second.second][now.second.second] == step){
				diff = min(diff, dist2[now.first.first][now.first.second][now.second.first][now.second.second]);
			}
			dbg(step, diff);
		}
 
		for(int k=0; k<4; ++k){
			int aii = now.first.first + di[k];
			int ajj = now.first.second + dj[k];
			int bii = now.second.first - di[k];
			int bjj = now.second.second - dj[k];
			bool okA, okB;
			okA = okB = true;
			if(aii < 1 || ajj < 1 || aii > n || ajj > m || v[aii][ajj] == '#'){
				okA = false;
			}
			if(bii < 1 || bjj < 1 || bii > n || bjj > m || v[bii][bjj] == '#'){
				okB = false;
			}
			if(okA && okB){
				if(dist2[aii][ajj][bii][bjj] != -1){
					continue;
				}
				dist2[aii][ajj][bii][bjj] = dist2[now.first.first][now.first.second][now.second.first][now.second.second] + 1;
				q.emplace(make_pair(aii, ajj), make_pair(bii, bjj));
			}
			else if(okA && !okB){
				if(dist2[aii][ajj][now.second.first][now.second.second] != -1){
					continue;
				}
				dist2[aii][ajj][now.second.first][now.second.second] = dist2[now.first.first][now.first.second][now.second.first][now.second.second] + 1;
				q.emplace(make_pair(aii, ajj), now.second);
			}
			else if(!okA && okB){
				if(dist2[now.first.first][now.first.second][bii][bjj] != -1){
					continue;
				}
				dist2[now.first.first][now.first.second][bii][bjj] = dist2[now.first.first][now.first.second][now.second.first][now.second.second] + 1;
				q.emplace(now.first, make_pair(bii, bjj));
			}
		}
	}
	cout << step << " " << diff-1;
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
