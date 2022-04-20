/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Rock Paper Scissor
 * ALGO		: ?
 * DATE		: 14 Apr 2022
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
	int a, b, c;
	cin >> a >> b >> c;
	int sum = a + b + c;
	multimap<int, string> mp;
	mp.emplace(a, "PAPER");
	mp.emplace(b, "SCISSORS");
	mp.emplace(c, "ROCK");
	if(sum != 100){
		cout << "BUG";
		return ;
	}
	auto it = mp.begin();
	if(it->first == 0){
		cout << "I DON'T KNOW";
		return ;
	}
	it++, it++;
	cout << it->second;
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
