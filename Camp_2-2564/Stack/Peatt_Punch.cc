/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Peatt Punch
 * ALGO		: Stack
 * DATE		: 7 Apr 2022
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

const int MxN = 100010;
int a[MxN], required[MxN];

inline void solution(){
	stack<pair<int, int>> st;
	int h, l, q, power = 0;
	cin >> l >> q;
	for(int i=1, h; i<=l; ++i){
		cin >> h;
		while(!st.empty() && st.top().first >= h){
			st.pop();
		}
		if(st.empty()){
			power = 0;
		}
		else{
			power = max(st.top().second, h - st.top().first);
		}
		required[i] = power;
		st.emplace(h, power);
	}
	sort(required + 1, required + l + 1);
	while(q--){
		cin >> h;
		cout << (l - (upper_bound(required + 1, required + l + 1, h) - (required + 1))) << "\n";
	}
	return ;
}

signed main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);	
	int q = 1;
//	cin >> q;
	while(q--){
		solution();
	}
	return 0;
}
// https://github.com/MasterIceZ/archive/tree/main/cpp-template
