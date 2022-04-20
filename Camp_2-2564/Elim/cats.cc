/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Cats
 * ALGO		: Binary Search
 * DATE		: 16 Apr 2022
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

const int MxN = 2000020;
ll a[MxN], n, top = -1;

inline bool ok(int x){
	for(int i=1; i<=n; ++i){
		if(x < a[i]){
			if(top == -1){
				top = a[i];
			}
			else if(top == a[i]){
				top = -1;
			}
			else if(top != a[i]){
				top = -1;
				return false;
			}
		}
	}
	return true;
}

inline void solution(){
	cin >> n;
	for(int i=1; i<=n; ++i){
		cin >> a[i];
	}
	ll l = 0, r = *max_element(a + 1, a + n + 1);
	dbg(l, r);
	while(l < r){
		ll mid = (l + r) >> 1;
		bool _ok = ok(mid);
		dbg(l, r, mid, _ok);
		if(_ok){
			r = mid;
		}
		else{
			l = mid + 1;
		}
	}
	cout << l;
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
