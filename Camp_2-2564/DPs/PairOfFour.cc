/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Pair of Four
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

const int MxN = 1010;
char a[MxN];
int dp[MxN][MxN];

int divide(int l, int r){
	if(l == r){
		return dp[l][r] = 0;
	}
	if(dp[l][r] != -1){
		return dp[l][r];
	}
	if(a[l] == a[r]){
		return dp[l][r] = 1 + divide(l + 1, r - 1);
	}
	int res = 0;
	for(int k=l; k<r; ++k){
		res = max(res, divide(l, k) + divide(k + 1, r));
	}
	return dp[l][r] = res;
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
//	cin >> q;
	while(q--){
		solution();
		cout << "\n";
	}
	return 0;
}
// https://github.com/MasterIceZ/archive/tree/main/cpp-template
