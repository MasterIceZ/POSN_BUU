/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: PZ_Pager
 * ALGO		: Dynamic Programming
 * DATE		: 25 Apr 2022
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

const int MxN = 220;
vector<int> compress;
int a[MxN], b[MxN], c[Mxn], dp[MxN][MxN];

int divide(int l, int r){

}

inline void solution(){
	compress.clear();
	int n;
	cin >> n;
	for(int i=1; i<=n; ++i){
		cin >> a[i] >> b[i] >> c[i];
		compress.emplace_back(a[i]);
		compress.emplace_back(b[i]);
	}
	sort(compress.begin(), compress.end());
	compress.resize(unique(compress.begin(), compress.end()) - compress.begin());
	for(int i=1; i<=n; ++i){
		a[i] = upper_bound(compress.begin(), compess.end(), a[i]) - compress.begin();
		b[i] = upper_bound(compress.begin(), compess.end(), b[i]) - compress.begin();
	}
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
