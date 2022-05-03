/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Beta Mode
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

const int MxN = 10010;
int dp[2][MxN];

inline void solution(){
	string s, t;
	cin >> s >> t;
	int n = s.size(), m = t.size();
	int stp = -1, maxx = 0;
	s = " " + s, t = " " + t;
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=m; ++j){
			if(s[i] == t[j]){
				dp[i % 2][j] = dp[(i + 1) % 2][j - 1] + 1;
				if(dp[i % 2][j] > maxx){
					maxx = dp[i % 2][j];
					stp = i;
				}
			}
		}
	}
	vector<char> answer;
	for(; stp-- && maxx-- ; ){
		answer.emplace_back(s[stp + 1]);
	}
	reverse(answer.begin(), answer.end());
	for(auto x: answer){
		cout << x ;
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
