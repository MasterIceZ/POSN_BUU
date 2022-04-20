/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: AP_Bush
 * ALGO		: Search By Elimination
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

const int MxN = 1010;
ll n, w, a[MxN];

inline bool ok(ll x){
	ll res = (x + 1ll) * (x + 1ll) * n;
//	dbg(res);
	for(ll i=2ll; i<=n; ++i){
		if(a[i] == a[i - 1]){
			res -= (x + 1ll) * (x + 1ll);
			continue;
		}
		if(a[i - 1] + x < a[i] - x){
			continue;
		}
		ll dist = 2ll * x + a[i - 1] - a[i] + 1ll;
		dbg(dist);
		if(dist % 2){
			res -= (dist + 1ll) / 2ll * (dist + 1ll) / 2ll;
		}
		else{
			ll cnts = dist / 2ll;
			res -= cnts + (cnts * cnts);
		}
	}
//	dbg(x, res);
	return res >= w;
}

inline void solution(){
	cin >> n >> w;
	for(ll i=1; i<=n; ++i){
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	ll l = 0, r = 1e9;
	while(l < r){
		ll mid = (l + r) >> 1;
		dbg(l, mid, r);
		if(ok(mid)){
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
//	a[1] = 2, a[2] = 8;
//	n = 2ll;
//	dbg(ok(3));
	int q = 1;
	cin >> q;
	while(q--){
		solution();
		cout << "\n";
	}
	return 0;
}
// https://github.com/MasterIceZ/archive/tree/main/cpp-template
