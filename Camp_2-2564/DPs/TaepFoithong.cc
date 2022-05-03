/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Taep Foithong
 * ALGO		: Dynamic Programming
 * DATE		: 27 Apr 2022
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

const int MxN = 5e6 + 50;
int pw[10];
bitset<MxN> visited, dp;
string s;

inline int convert(string s){
	int res = 0;
	for(auto x: s){
		res += pw[x - '0'];
	}
	return res;
}

bool divide(int now){
	if(visited[now]){
		return dp[now];
	}
	visited[now] = true;
	s = to_string(now);
	int t = convert(s);
	if(now == t){
		return dp[now] = true;
	}
	return dp[now] = divide(t);
}

inline void solution(){
	cin >> s;
	int now = convert(to_string(convert(s)));
	cout << (divide(now) ? "Yes": "No");
	return ;
}

signed main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);	
	int q = 1, k;
	cin >> q >> k;
	for(int i=1; i<=9; ++i){
		pw[i] = 1;
		for(int j=1; j<=k; ++j){
			pw[i] *= i;
		}
	}
	while(q--){
		solution();
		cout << "\n";
	}
	return 0;
}
// https://github.com/MasterIceZ/archive/tree/main/cpp-template
