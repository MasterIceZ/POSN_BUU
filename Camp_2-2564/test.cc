/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Hello World
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

char a[5][5];

// red, orange, yellow, white

void divide(ll x, ll y, ll n){
	dbg(x, y, n);
	if(n == 1){
		cout << a[x][y];
		exit(0);
	}
	if(x > (1 << (n - 1ll)) && y > (1 << (n - 1ll))){
		dbg("Q4");
		cout << "W";
		exit(0);
	}
	ll xx = x - (1ll << (n - 1ll));
	if(xx <= 0) xx = x;
	ll yy = y - (1ll << (n - 1ll));
	if(yy <= 0) yy = y;
	divide(xx, yy, n - 1ll);
}

inline void solution(){
	a[1][1] = 'R';
	a[1][2] = 'O';
	a[2][1] = 'Y';
	a[2][2] = 'W';
	ll n, x, y;
	cin >> n >> x >> y;
	double xx = x, yy = y;
	ll nn = ceil(log2(max(xx, yy)));
	divide(x, y, nn);
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
