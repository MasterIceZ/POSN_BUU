/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Choose Job
 * ALGO		: Dynamic Programming
 * DATE		: 21 Apr 2022
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

struct Job{
	int st, ed, w;
	bool operator < (const Job& o) const {
		if(ed != o.ed){
			return ed < o.ed;
		}
		return st < o.st;
	}
};

const int MxN = 1e5 + 10;
Job a[MxN];
int mem[MxN], dp[MxN];

inline void solution(){
	int n;
	cin >> n;
	for(int i=1; i<=n; ++i){
		cin >> a[i].st >> a[i].ed >> a[i].w;
	}
	sort(a + 1, a + n + 1);
	for(int i=1; i<=n; ++i){
		mem[i] = a[i].ed;
	}
	for(int i=1; i<=n; ++i){
		int idx = lower_bound(mem + 1, mem + n + 1, a[i].st) - (mem + 1);
		dp[i] = max(dp[i - 1], dp[idx] + a[i].w);
	}
	cout << dp[n];
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
