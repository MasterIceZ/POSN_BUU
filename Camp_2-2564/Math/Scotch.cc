/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Scotch
 * ALGO		: ?
 * DATE		: 22 Apr 2022
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

ll cntA[3], cntB[3], cntAB[6];

inline void solution(){
	int n, a, b;
	cin >> n >> a >> b;
	for(int i=1; i<=n; ++i){
		if(i % (2 * a) <= a && i % (2 * a) != 0){
			if(i % (2 * b) <= b && i % (2 * b) != 0){
				cntA[0]++, cntB[0]++, cntAB[0]++;
			}
			else{
				cntA[0]++, cntB[1]++, cntAB[1]++;
			}
		}
		else{
			if(i % (2 * b) <= b && i % (2 * b) != 0){
				cntA[1]++, cntB[0]++, cntAB[2]++;
			}
			else{
				cntA[1]++, cntB[1]++, cntAB[3]++;
			}
		}
	}
	ll res = 0ll;
	for(int i=0; i<=1; ++i){
		res += cntA[i] * cntA[i];
		res += cntB[i] * cntB[i];
	}
	for(int i=0; i<=3; ++i){
		res -= cntAB[i] * cntAB[i];
	}
	cout << res;
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
