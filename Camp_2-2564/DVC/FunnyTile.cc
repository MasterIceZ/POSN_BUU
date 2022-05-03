/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Funny Tile
 * ALGO		: Divide and Conquer
 * DATE		: 24 Apr 2022
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
	int type, x, y;
	Tile(int a, int b, int c): type(a), x(b), y(c) {}
	bool operator < (const Tile& o) const {
		if(type != o.type){
			return type < o.type;
		}
		else if(x != o.x){
			return x < o.x;
		}
		return y < o.y;
	}
};

vector<Tile> tiles;

void divide(int n, pair<int, int> up, pair<int, int> hole){
	if(n == 1){
		return ;
	}
	n /= 2;
	int state = (up.first + n <= hole.first) + (up.second + n <= hole.second) * 2;
	for(int i=0; i<2; ++i){
		for(int j=0; j<2; ++j){
			if(j * 2 + i == state){
				divide(n, {up.first + n * i, up.second + n * j}, hole);
			}
			else{
				divide(n, {up.first + n * i, up.second + n * j}, {up.first + n - i, up.second + n - j});
			}
		}
	}
	tiles.emplace_back(state, up.first + n - 1, up.second + n - 1);
}

inline void solution(){
	int n;
	pair<int, int> hole;
	cin >> n >> hole.first >> hole.second;
	divide(n, {0, 0}, hole);
	sort(tiles.begin(), tiles.end());
	cout << tiles.size() << "\n";
	for(auto x: tiles){
		cout << x.type << " " << x.x << " " << x.y << "\n";
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
