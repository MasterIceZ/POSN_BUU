/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: PN_Parenthesis
 * ALGO		: Stack
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

stack<pair<char, int>> st;
vector<int> v;

inline void add(int state){
	if(v.size() < state){
		v.emplace_back(1);
	}
	else{
		v[--state]++;
	}
}

inline void solution(){
	int n, cnt=0;
	string s;
	cin >> n >> s;
	s = " " + s;
	for(int i=1; i<=n; ++i){
		if(st.empty() || s[i] == '('){
			st.emplace(s[i], 1);
		}
		else{
			int max_state = 0;
			while(!st.empty() && st.top().first != '('){
				max_state = max(st.top().second, max_state);
				st.pop();
			}
			if(!st.empty()){
				st.pop();
			}
			st.emplace('a', max_state + 1);
			add(max_state + 1);
			cnt++;
		}
	}
	cout << cnt << "\n";
	cout << v.size() << "\n";
	for(auto x: v){
		cout << x << " ";
	}
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
