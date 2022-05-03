/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Matrix Expo
 * ALGO		: Divide and Conquer
 * DATE		: 24 Apr 2022
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

const int MxN = 7;
int n;
ll c;

struct Matrix{
	ll a[MxN][MxN];
	Matrix(){
		for(int i=1; i<=5; ++i){
			a[i][i] = 1;
		}
	}
};
Matrix operator * (Matrix A, Matrix B){
	Matrix res;
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=n; ++j){
			ll r = 0;
			for(int k=1; k<=n; ++k){
				r = (r + A.a[i][k] * B.a[k][j]) % c;
			}
			res.a[i][j] = r;
		}
	}
	return res;
}

Matrix transition, value, mem[64];

inline void solution(){
	cin >> n;
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=n; ++j){
			cin >> transition.a[i][j];
			mem[1].a[i][j] = transition.a[i][j];
		}
	}
	ll b;
	cin >> b >> c;
	for(int i=2; i<=62; ++i){
		mem[i] = mem[i - 1] * mem[i - 1];
	}
	for(ll i=1; i<=62; ++i){
		if(b & (1ll << (i - 1))){
			value = value * mem[i];
		}
	}
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=n; ++j){
			cout << value.a[i][j] % c << " " ;
		}
		cout << "\n";
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
