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

const int MxN  = 110;
const int nugget[] = {6, 9, 20};
int dp[MxN];

inline void solution(){
	int n, printed = 0;
	cin >> n;
	dp[0] = 1;
	for(int i=6; i<=n; ++i){
		int ok = 0;
		for(int j=0; j<3; ++j){
			if(i - nugget[j] < 0){
				continue;
			}
			ok |= dp[i - nugget[j]];
		}
		dp[i] = ok;
		if(ok){
			cout << i << "\n";
			printed = 1;
		}
	}
	if(!printed){
		cout << "no";
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
