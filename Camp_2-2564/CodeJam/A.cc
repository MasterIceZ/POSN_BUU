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

inline void solution(){
	string s;
	cin >> s;
	set<char> st;
	for(auto x: s){
		st.emplace(x);
	}
	if(st.size() == 1){
		cout << s;
		return ;
	}
	string t = string(1, s[0]);
	bool dd = false;
	for(int i=1; i<s.size(); ++i){
		if(t.back() < s[i] && !dd){
			t += t.back();
			dd = true;
		}
		t += s[i];
		dd = false;
	}
	cout << t;
	return ;
}

signed main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);	
	int q = 1;
	cin >> q;
	for(int i=1; i<=q; ++i){
		cout << "Case #" << i << ": ";
		solution();
		cout << "\n";
	}
	return 0;
}
// https://github.com/MasterIceZ/archive/tree/main/cpp-template
