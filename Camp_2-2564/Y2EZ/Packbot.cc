/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Packbot
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

stack<int> num, opr;

inline void calc(){
	int r = num.top();
	num.pop();
	int l = num.top();
	num.pop();
	int sum = l + r;
	num.push(sum * (100 + (1 << opr.top())) / 100);
	opr.pop();
}

inline void solution(){
	string s;
	cin >> s;
	for(auto x: s){
		if(isalpha(x)){
			num.emplace(20);
		}
		else if(x == '['){
			opr.emplace(-1);
		}
		else if(x == ']'){
			while(!opr.empty() && opr.top() != -1){
				calc();
			}
			opr.pop();
		}
		else{
			while(!opr.empty() && opr.top() >= x - '0' + 1){
				calc();
			}
			opr.push(x - '0' + 1);
		}
	}
	while(!opr.empty()){
		calc();
	}
	cout << num.top();
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
