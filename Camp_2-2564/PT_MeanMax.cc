/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: PT_MeanMax
 * ALGO		: Search by elimination
 * DATE		: 11 Apr 2022
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

const int MxN = 300030;
double a[MxN], maxx = 0;
int n;

inline bool ok(int x){
	double sum = 0, res = 0;
	for(int i=1; i<=n; ++i){
		sum += a[i];
		if(i >= x){
			sum -= a[i - x];
			res = max(res, sum / x);
		}
	}
	maxx = max(maxx, res);
	return maxx == res;
}

inline void solution(){
	int k;
	cin >> n >> k;
	double sum = 0;
	for(int i=1; i<=n; ++i){
		cin >> a[i];
		sum += a[i];
		if(i >= k){
			sum -= a[i - k];
			maxx = max(maxx, sum / k);
		}
	}
	int l = k, r = n;
	dbg(l, r, n, k);
	while(l < r){
		dbg(l, r);
		int mid = (1 + l + r) >> 1;
		if(ok(mid)){
			l = mid;
		}
		else{
			r = mid - 1;
		}
	}
	cout << fixed << setprecision(1) << maxx;
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
