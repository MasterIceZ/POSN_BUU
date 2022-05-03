/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Tarn Sequence
 * ALGO		: Dynamic Programming
 * DATE		: 20 Apr 2022
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

const int MxN = 100010;

int a[MxN], dp[MxN];
vector<int> mem[MxN];

inline void solution(){
	int n;
	cin >> n;
	for(int i=1; i<=n; ++i){
		cin >> a[i];
		a[i] = -a[i];
	}
	int sz = 0;
	for(int i=1; i<=n; ++i){
		int idx = lower_bound(dp, dp + sz, a[i]) -  dp;
		if(idx == sz){
			sz++;
		}
		dp[idx] = a[i];
		mem[idx].emplace_back(a[i]);
	}
	cout << sz << "\n";
	vector<int> answer;
	answer.emplace_back(mem[sz - 1][0]);
	int last = mem[sz - 1][0];
	for(int i=sz-2; i>=0; --i){
		for(auto x: mem[i]){
			if(x < last){
				last = x;
				answer.emplace_back(last);
				break;
			}
		}
	}
	reverse(answer.begin(), answer.end());
	for(auto x: answer){
		cout << -x << " ";
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
