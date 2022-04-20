/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		:
 * ALGO		:
 * DATE		:
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

int n, m, a[111][111], dp[111][111];

inline void solution(){
	int s;
	cin >> m >> s >> n;
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=m; ++j){
			cin >> a[i][j];
		}
	}
	dp[0][s] = 1;
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=m; ++j){
			if(!a[i][j]){
				for(int k=-1; k<=1; ++k){
					dp[i][j] |= dp[i - 1][j + k];
				}
			}
		}
	}
	int edp = -1;
	for(int i=1; i<=m; ++i){
		if(dp[n][i]){
			edp = i;
		}
	}
	stack<int> st;
	for(int i=n; i>=1; --i){
		if(dp[i - 1][edp - 1]){
			st.emplace(2);
			edp--;
		}
		else if(dp[i - 1][edp]){
			st.emplace(3);
		}
		else{
			st.emplace(1);
			edp++;
		}
	}
	while(!st.empty()){
		cout << st.top() << "\n";
		st.pop();
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
