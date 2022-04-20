/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Chocolate Delivery
 * ALGO		: Dynamic Programming, Fermat's Little Theorem
 * DATE		: 13 Apr 2022
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

struct Thieve{
	ll x, y;
	int idx;
	bool operator < (const Thieve& o) const {
		if(x != o.x){
			return x < o.x;
		}
		return y < o.y;
	}
	Thieve(ll a, ll b, int c): x(a), y(b), idx(c) {}
};

const int MxN = 100010;
const int MOD = 1e9 + 7;
ll factorial[2 * MxN], inverse[2 * MxN], dp[1010];
vector<Thieve> thieves;

ll mod_of_power(ll a, ll b){
	if(b == 0){
		return 1ll;
	}
	ll tmp = mod_of_power(a, b / 2);
	ll res = (tmp * tmp) % MOD;
	if(b % 2){
		res = (res * a) % MOD;
	}
	return res;
}

inline ll C(ll n, ll r){
	return (((factorial[n] * inverse[n - r]) % MOD) * inverse[r]) % MOD;
}

inline ll ways(ll x, ll y){
	ll all_ways = C(x + y - 2, y - 1), res = all_ways;
	dbg(all_ways);
	for(auto thieve: thieves){
		if(thieve.x <= x && thieve.y <= y){
			res -= (dp[thieve.idx] * C(x + y - (thieve.x + thieve.y), (y - thieve.y))) % MOD;
			res = (res + MOD) % MOD;
		}
	}
	return res;
}

inline void solution(){
	int n, q;
	ll x, y;
	cin >> n >> q;
	for(int i=1; i<=n; ++i){
		cin >> x >> y;
		thieves.emplace_back(x, y, i);
	}
	sort(thieves.begin(), thieves.end());
	factorial[0] = 1;
	factorial[1] = 1;
	for(int i=2; i<=200000; ++i){
		factorial[i] = factorial[i - 1] * i;
		factorial[i] %= MOD;
	}
	inverse[200000] = mod_of_power(factorial[200000], MOD - 2);
	inverse[0] = 1;
	for(int i=199999; i>=1; --i){
		inverse[i] = (inverse[i + 1] * (i + 1)) % MOD;
	}
	for(auto thieve: thieves){
		dp[thieve.idx] = ways(thieve.x, thieve.y);
	}
	dbg(to_string(dp, 1, n));
	while(q--){
		cin >> x >> y;
		cout << ways(x, y) << "\n";
	}
	return ;
}

signed main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);	
	int q = 1;
//	cin >> q;
	while(q--){
		solution();
	}
	return 0;
}
// https://github.com/MasterIceZ/archive/tree/main/cpp-template
