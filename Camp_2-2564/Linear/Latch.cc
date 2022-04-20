/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Latch
 * ALGO		: Stack
 * DATE		: 17 Apr 2022
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
ll a[MxN][MxN], dp[MxN][MxN];

inline void solution(){
	int n, m;
	cin >> n >> m;
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=m; ++j){
			dp[i][j] = 1ll;
			cin >> a[i][j];
			if(a[i][j] == a[i][j - 1]){
				dp[i][j] = dp[i][j - 1] + 1ll;
			}
		}
	}
	stack<ll> st;
	ll res = 0ll, answer = 0ll;
	for(int j=1; j<=m; ++j){
		while(!st.empty()){
			st.pop();
		}
		res = 0ll;
		for(int i=1; i<=n; ++i){
			if(a[i][j] != a[i - 1][j]){
				while(!st.empty()){
					st.pop();
				}
				res = 0ll;
			}
			if(st.empty() || (!st.empty() && st.top() <= dp[i][j])){
				st.emplace(dp[i][j]);
				res += dp[i][j];
			}
			else{
				ll cnt = 0ll;
				while(!st.empty() && st.top() > dp[i][j]){
					res -= st.top();
					st.pop();
					cnt++;
				}
				res += dp[i][j] * cnt;
				while(cnt--){
					st.emplace(dp[i][j]);
				}
			}
			answer += res;
		}
	}
	cout << answer;
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
