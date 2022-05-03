/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: BT_Works
 * ALGO		: Dynamic Programming, Fermat's Little Theorem, Combinatorics
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

const int MxN = 2010;
const ll MOD = 1e9 + 7;
ll factorial[MxN], inverse[MxN];

ll mod_of_power(ll a, ll b){
	if(b == 1){
		return a;
	}
	else if(b == 0){
		return 1;
	}
	ll div = mod_of_power(a, b / 2);
	ll res = (div * div) % MOD;
	if(b % 2){
		res = (res * a) % MOD;
	}
	return res;
}

inline ll C(int a, int b){
	return ((factorial[a] * inverse[a - b]) % MOD * inverse[b]) % MOD;
}

inline void solution(){
	int n, m, d;
	cin >> n >> m >> d;
	cout << C(n - d * (m - 1), m);
	return ;
}

signed main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);	
	factorial[0] = 1;
	int N = 2000;
	for(int i=1; i<=N; ++i){
		factorial[i] = (factorial[i - 1] * i) % MOD;
	}
	inverse[0] = 1;
	inverse[N] = mod_of_power(factorial[N], MOD - 2);
	for(int i=N-1; i>=1; --i){
		inverse[i] = (inverse[i + 1] * (i + 1)) % MOD;
	}
	int q = 1;
	cin >> q;
	while(q--){
		solution();
		cout << "\n";
	}
	return 0;
}
// https://github.com/MasterIceZ/archive/tree/main/cpp-template
