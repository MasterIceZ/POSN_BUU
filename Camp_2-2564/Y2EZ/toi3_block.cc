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

const int MxN = 7;
int n, m, score;
char a[MxN][MxN], opr, current;
int dx[111];

const int di[] = {-1, 0, 0, 1};
const int dj[] = {0, -1, 1, 0};

inline void fall(){
	dbg("falling");
	for(int j=1; j<=m; ++j){
		for(int i=n-1; i>=1; --i){
			int x = i;
			while(x <= n && a[x + 1][j] == '-' && isalpha(a[x][j])){
				swap(a[x + 1][j], a[x][j]);
				x++;
			}
		}
	}
}

void destroy(int i, int j){
	dbg("destroying");
	score += 5;
	a[i][j] = '-';
	for(int k=0; k<4; ++k){
		int ii = di[k] + i;
		int jj = dj[k] + j;
		if(ii < 1 || jj < 1 || ii > n || jj > m){
			continue ;
		}
		if(a[ii][jj] != current){
			continue;
		}
		destroy(ii, jj);
	}
}

inline bool ok(int x, int y){
	bool res = isalpha(a[x][y]), res2 = false;
	if(!res){
		return false;
	}
	for(int k=0; k<4; ++k){
		res2 |= (a[x][y] == a[x + di[k]][y + dj[k]]);
	}
	return res2;
}

inline void solution(){
	cin >> n >> m;
	assert(1 <= n && n <= 5 && 1 <= m && m <= 5);
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=m; ++j){
			cin >> a[i][j];
		}
	}
	int q;
	cin >> q;
	dx['L'] = -1;
	dx['R'] = 1;
	while(q--){
		int x, y;
		cin >> x >> y >> opr;
		x++, y++;
		int nxt_y = dx[opr] + y;
		if(nxt_y >= 1 && nxt_y <= m && isalpha(a[x][y]) && a[x][nxt_y] == '-'){
			swap(a[x][y], a[x][nxt_y]);
			dbg(a[x][y], a[x][nxt_y]);
			dbg(x, y, x, nxt_y);
			fall();
			for(int i=1; i<n; ++i){
				for(int j=2; j<m; ++j){
					if(ok(i, j)){
						current = a[i][j];
						destroy(i, j);
						fall();
					}
				}
			}
		}
		else{
			score -= 5;
		}
#ifdef _DEBUG
		for(int i=1; i<=n; ++i){
			for(int j=1; j<=m; ++j){
				cout << a[i][j] << " ";
			}
			cout << "\n";
		}
#endif
	}
	cout << score << "\n";
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=m; ++j){
			cout << a[i][j] << " ";
		}
		cout << "\n";
	}
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
