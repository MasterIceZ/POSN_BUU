/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: toi1_pattern
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

using ll = long long;

char A[50050][77];

inline void solution(){
	memset(A, 'o', sizeof A);
	int q, maxx = 0;
	cin >> q;
	while(q--){
		int a, b, c;
		cin >> a >> b >> c;
		while(c-- && b <= 70){
			A[a][b] = 'x';
			b++;
		}
		maxx = max(maxx, a);
	}
	for(int i=1; i<=maxx; ++i){
		for(int j=1; j<=70; ++j){
			cout << A[i][j];
		}
		cout << "\n";
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
