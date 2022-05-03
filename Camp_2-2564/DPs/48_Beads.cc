/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: 48_Beads
 * ALGO		: Dynamic Programming
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

const int MOD = 100;
const int MxN = 110;
int a[MxN], dp[MxN][MxN][3];

int divide(int l, int r){
	if(l == r){
		dp[l][r][1] = a[l];
		dp[l][r][0] = 0;
		return 0;
	}
	if(dp[l][r][1] != -1){
		return dp[l][r][0] ;
	}
	int res = 1e9 + 100;
	for(int k=l; k<r; ++k){
		int cur = divide(l, k)  + divide(k + 1, r) + dp[l][k][1] * dp[k + 1][r][1];
		if(cur < res){
			res = cur;
			dp[l][r][1] = (dp[l][k][1] + dp[k + 1][r][1]) % 100;
		}
	}
	return dp[l][r][0] = res;
}

inline void solution(){
	int n;
	cin >> n;
	for(int i=1; i<=n; ++i){
		cin >> a[i];
	}
	memset(dp, -1, sizeof dp);
	cout << divide(1, n);
	return ;
}

signed main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);	
	int q = 1;
	cin >> q;
	while(q--){
		solution();
		cout << "\n";
	}
	return 0;
}
// https://github.com/MasterIceZ/archive/tree/main/cpp-template
