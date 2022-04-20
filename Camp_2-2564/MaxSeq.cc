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

int a[3333];

inline void solution(){
	int n;
	cin >> n;
	bool can = false;
	for(int i=1; i<=n; ++i){
		cin >> a[i];
		if(a[i] > 0){
			can = true;
		}
	}
	if(!can){
		cout << "Empty sequence";
		return ;
	}
	int maxx = -1e9, st = 1, ed = 0, sum = 0, last = 1;
	for(int i=1; i<=n; ++i){
		sum += a[i];
		if(sum > maxx){
			maxx = sum;
			st = last;
			ed = i;
		}
		if(sum < 0){
			sum = 0;
			last = i + 1;
		}
	}
	for(int i=st; i<=ed; ++i){
		cout << a[i] << " " ;
	}
	cout << "\n" << maxx;
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
