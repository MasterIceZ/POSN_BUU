/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Pipe
 * ALGO		: ?
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

struct Coor{
	int x, y;
	Coor(int a=0, int b=0): x(a), y(b) {}
};

const int MxN = 15010;
Coor a[MxN];
int edge[MxN];

inline void solution(){
	int n, k;
	cin >> n >> k;
	for(int i=1; i<=n; ++i){
		cin >> a[i].x >> a[i].y;
	}
	memset(edge, 0x3f, sizeof edge);
	edge[1] = 0;
	for(int i=1; i<n; ++i){
		int minn = 1e9 + 100, swp = -1;
		for(int j=i+1; j<=n; ++j){
			edge[j] = min(edge[j], abs(a[i].x - a[j].x) + abs(a[i].y - a[j].y));
			if(edge[j] < minn){
				minn = edge[j];
				swp = j;
			}
		}
		swap(edge[i + 1], edge[swp]);
		swap(a[i + 1], a[swp]);
	}
	sort(edge + 1, edge + n + 1);
	cout << accumulate(edge + 1, edge + n - k + 2, 0);
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
