/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: toi1_roman
 * ALGO		: ?
 * DATE		: 9 Apr 2022
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

int ii, vv, cc, xx, ll;

void conv(int n){
	for(; n>=100; n-=100){
		cc++;
	}
	for(; n>=90; n-=90){
		cc++;
		xx++;
	}
	for(; n>=50; n-=50){
		ll++;
	}
	for(; n>=40; n-=40){
		ll++;
		xx++;
	}
	for(; n>=10; n-=10){
		xx++;
	}
	for(; n>=9; n-=9){
		xx++;
		ii++;
	}
	for(; n>=5; n-=5){
		vv++;
	}
	for(; n>=4; n-=4){
		vv++;
		ii++;
	}
	for(; n; n--){
		ii++;
	}
}

inline void solution(){
	int n;
	cin >> n;
	for(int i=1; i<=n; ++i){
		conv(i);
	}
	cout << ii << " " << vv << " " << xx << " " << ll << " " << cc;
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
