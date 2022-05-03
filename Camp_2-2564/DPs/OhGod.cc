/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Oh God Word
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

const int MxN = 1010;
int dp[MxN][MxN];
char s[MxN];

inline void solution(){
//	string s;
//	cin >> s;
	scanf(" %s", s);
//	int n = s.size();
	int n = strlen(s);
	for(int i=0; i<n; ++i){
		dp[i][i] = 1;
	}	
	int maxx = 1, stp = 0;
	for(int i=n-2; i>=0; --i){
		if(s[i] == s[i + 1]){
			dp[i][i + 1] = 1;
			maxx = 2;
			stp = i;
		}
	}
	for(int k=3; k<=n; ++k){
		for(int i=0; i<n; ++i){
			int j = i + k - 1;
			if(dp[i + 1][j - 1] && s[i] == s[j]){
				dp[i][j] = 1;
				if(k > maxx){
					maxx = k;
					stp = i;
				}
			}
		}
	}
	for(int i=stp; i<stp+maxx; ++i){
//		cout << s[i];
		printf("%c", s[i]);
	}
	return ;
}

signed main(){
//	cin.tie(nullptr)->ios::sync_with_stdio(false);	
	int q = 1;
//	cin >> q;
	while(q--){
		solution();
//		cout << "\n";
		printf("\n");
	}
	return 0;
}
// https://github.com/MasterIceZ/archive/tree/main/cpp-template
