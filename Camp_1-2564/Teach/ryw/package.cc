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

const int MxN = 1e5 + 10;
int w[MxN], c[MxN], types[MxN];
int n, k, it;

inline bool ok(int x){
	int sum = 0, cnt_boxes = 1;
	for(int i=1; i<=n; ++i){
		sum += w[i];
		if(sum > x || types[c[i]] == it){
			cnt_boxes++, it++;
			sum = w[i];
		}
		types[c[i]] = it;
	}
	return cnt_boxes <= k;
}

inline void solution(){
	memset(types, 0, sizeof types);
	cin >> n >> k;
	int maxx = -1, sum = 0;
	bool _ok = true;
	for(int i=1; i<=n; ++i){
		cin >> w[i] >> c[i];
		maxx = max(w[i], maxx);
		sum += w[i];
		types[c[i]]++;
		if(types[c[i]] > k){
			_ok = false;
		}
	}
	if(!_ok){
		cout << "-1";
		return ;
	}
	memset(types, 0, sizeof types);
	int l = maxx, r = sum + 1;
	while(l < r){
		int mid = (l + r) / 2;
		++it;
		if(ok(mid)){
			r = mid;
		}
		else{
			l = mid + 1;
		}
	}
	if(l > sum){
		cout << "-1";
	}
	else{
		cout << l;
	}
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
