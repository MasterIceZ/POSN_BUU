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

const int MxN = 100100;
int a[MxN];
int n, m;

inline bool ok(int x){
	int cnt_router = 1, router_now = a[1] + x;
	for(int i=2; i<=m; ++i){
		if(router_now + x < a[i]){
			cnt_router++;
			router_now = a[i] + x;
		}
	}
	return cnt_router <= n;
}

inline void solution(){
	cin >> n >> m;
	for(int i=1; i<=m; ++i){
		cin >> a[i];
		a[i] *= 10;
	}
	sort(a + 1, a + m + 1);
	int l = 0, r = 1e9 + 100;
	while(l < r){
		int mid = (l + r) / 2;
		if(ok(mid)){
			r = mid;
		}
		else{
			l = mid + 1;
		}
	}
	cout << (l / 10) << "." << (l % 10);
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
