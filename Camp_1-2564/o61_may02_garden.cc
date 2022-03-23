/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Colorful Garden
 * ALGO		: Dynamic Programming
 * DATE		: 22 Mar 2022
 * */

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>
// @==== Libary ====@ //

// @================@ //

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
const int MOD = 1e6 + 3;
vector<int> adj[MxN], v[MxN];
ll dp[MxN][1 << 10], a[MxN];

inline void solution(){
	int n, m, c;
	cin >> n >> m >> c;
	for(int i=0; i<n; ++i){
		cin >> a[i];
		dp[i][1 << a[i]] = 1;
	}
	for(int i=1, u, v; i<=m; ++i){
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for(int i=0; i<(1 << c); ++i){
		v[__builtin_popcount(i)].push_back(i);
	}
	for(int i=2; i<=c; ++i){
		for(auto x: v[i]){
			for(int j=0; j<n; ++j){
				if(!(x >> a[j] & 1)){
					continue;
				}
				for(auto y: adj[j]){
					dp[j][x] = (dp[j][x] + dp[y][x ^ (1 << a[j])]) % MOD;
				}
			}
		}
	}
	int res = 0;
	for(int i=0; i<n; ++i){
		res = (res + dp[i][(1 << c) - 1] % MOD);
	}
	cout << res;
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
