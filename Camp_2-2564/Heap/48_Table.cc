/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: 48_Table
 * ALGO		: Heap
 * DATE		: 17 Apr 2022
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
	int x, y, id, val;
	bool operator < (const Tile& o) const {
		return val > o.val;
	}
	Tile(int a, int b, int c, int d): x(a), y(b), id(c), val(d) {}
};

pair<int, int> a[333][5050];

inline void solution(){
	priority_queue<Tile> pq;
	int r, c, m, opr, x, y, z;
	cin >> r >> c >> m;
	for(int i=1; i<=r; ++i){
		for(int j=1; j<=c; ++j){
			pq.emplace(i, j, 0, 0);
		}
	}
	for(int i=1; i<=m; ++i){
		cin >> opr;
		if(opr == 1){
			cin >> x >> y >> z;
			a[x][y] = make_pair(z, i);
			pq.emplace(x, y, i, z);
		}
		else if(opr == 2){
			cin >> x >> y;
			a[x][0] = make_pair(y, i);
			pq.emplace(x, 0, i, y);
		}
		else if(opr == 3){
			cin >> x >> y;
			if(a[x][0].second > a[x][y].second){
				cout << a[x][0].first;
			}
			else{
				cout << a[x][y].first;
			}
			cout << "\n";
		}
		else{
			while(!pq.empty()){
				Tile now = pq.top();
				if(now.y == 0){
					bool ok = false;
					if(a[now.x][0].second > now.id){
						pq.pop();
						continue;
					}
					for(int j=1; j<=c; ++j){
						if(a[now.x][j].second < now.id){
							ok = true;
							break;
						}
					}
					if(!ok){
						pq.pop();
						continue;
					}
					cout << now.val << "\n";
					break;
				}
				else{
					if(a[now.x][now.y].second > now.id || a[now.x][0].second > now.id){
						pq.pop();
						continue;
					}
					cout << now.val << "\n";
					break;
				}
			}
		}
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
