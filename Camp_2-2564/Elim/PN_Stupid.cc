/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: PN_Stupid
 * ALGO		: Search by Elimination
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

ll s, p;
bool answered = false;

inline bool ok(ll a){
	ll b = s - a;
	if(a * b == p && a * b / b == a){
		answered = true;
		return true;
	}
	return (a * b > p || a * b / b != a);
}

inline void solution(){
	cin >> s >> p;
	ll l = 0, r = s / 2;
	answered = false;
	while(l <= r){
		ll mid = (l + r) >> 1;
		bool _ok = ok(mid);
		dbg(l, r, mid, _ok);
		if(answered){
			cout << min(mid, s - mid) << " " << max(mid, s - mid);
			return ;
		}
		if(_ok){
			r = mid - 1;
		}
		else{
			l = mid + 1;
		}
	}
	cout << "No answer";
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
