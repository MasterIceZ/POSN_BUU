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
	ll n;
	cin >> n;
	if(n < 0){
		cout << "-1" ;
		return ;
	}
	if(n == 0){
		cout << "10";
		return ;
	}
	if(n < 10){
		cout << n ;
		return ;
	}
	vector<int> v;
	for(int i=9; i>=2; --i){
		while(n % i == 0){
			v.push_back(i);
			n /= i;
		}
	}
	if(v.empty() || n != 1){
		cout << "-1";
		return ;
	}
	sort(v.begin(), v.end());
	for(auto x: v){
		cout << x;
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
