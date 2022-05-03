/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Matrix Chain
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

const int MxN = 11;
int row[MxN], col[MxN], dp[MxN][MxN], pth[MxN][MxN];

int divide(int l, int r){
	if(l == r){
		return dp[l][r] = 0;
	}
	if(dp[l][r] != -1){
		return dp[l][r];
	}
	int res = 1e9 + 10;
	for(int k=l; k<r; ++k){
		int cur = divide(l, k) + divide(k + 1, r) + row[l] * col[k] * col[r];
		if(cur < res){
			res = cur;
			pth[l][r] = k;
		}
	}
	return dp[l][r] = res;
}

void dfs(int l, int r){
	if(l == r){
		cout << "A" << l;
		return ;
	}
	cout << "(";
	dfs(l, pth[l][r]);
	cout << " x ";
	dfs(pth[l][r] + 1, r);
	cout << ")";
}

inline void solution(){
	int n;
	cin >> n;
	for(int i=1; i<=n; ++i){
		cin >> row[i] >> col[i];
	}
	memset(dp, -1, sizeof dp);
	cout << divide(1, n) << "\n";
	dfs(1, n);
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
