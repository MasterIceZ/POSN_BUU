/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Longest Repeated Substring
 * ALGO		: Search by Elimination
 * DATE		: 15 Apr 2022
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

int n, m;
string s, now;
unordered_map<string, int> mp;

inline bool ok(int x){
	mp.clear();
	for(int it=1, i=x; i<=n; ++i, ++it){
		now = s.substr(it, x);
		mp[now]++;
		if(mp[now] >= m){
			return true;
		}
	}
	return false;
}

inline void solution(){
	cin >> n >> m >> s;
	s = " " + s;
	int l = 0, r = n;
	while(l < r){
		int mid = (l + r + 1) >> 1;
		bool _ok = ok(mid);
		dbg(mid, _ok);
		if(_ok){
			l = mid;
		}
		else{
			r = mid - 1;
		}
	}
	cout << l ;
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
