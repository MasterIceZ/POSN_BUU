/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: FC_Golden Age
 * ALGO		: Dynamic Programming on Tree
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

const int MxN = 5050;
int n, dp[MxN][110], a[MxN];


int dfs(int u, int k){
	if(k == 0 || u > n){
		return 0;
	}
	if(dp[u][k] != -1){
		return dp[u][k];
	}
	for(int i=0; i<k; ++i){
		dp[u][k] = max(dp[u][k], a[u] + dfs(2 * u, i) + dfs(2 * u + 1, k - i - 1));
	}
	return dp[u][k];
}

inline void solution(){
	int k;
	memset(dp, -1, sizeof dp);
	cin >> n >> k;
	for(int i=1; i<=n; ++i){
		cin >> a[i];
	}
	int answer = 0;
	for(int i=1; i<=n; ++i){
		answer = max(answer, dfs(i, k));
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
