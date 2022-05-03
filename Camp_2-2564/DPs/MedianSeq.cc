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

const int MxN = 100010;
const int offset = 100000;
ll a[MxN], l[2 * MxN], r[2 * MxN];

inline void solution(){
	int n, middle;
	ll k;
	cin >> n >> k;
	for(int i=1; i<=n; ++i){
		cin >> a[i];
		if(a[i] == k){
			middle = i;
		}
	}
	l[offset] = r[offset] = 1;
	int current = 0;
	for(int i=middle + 1; i<=n; ++i){
		if(a[i] < k){
			current--;
		}
		else{
			current++;
		}
		l[current + offset]++;
	}
	current = 0;
	for(int i=middle - 1; i>=1; --i){
		if(a[i] < k){
			current--;
		}
		else{
			current++;
		}
		r[current + offset]++;
	}
	ll answer = 0ll;
	for(int i=0; i<=2*offset; ++i){
		answer += (l[i] * r[2 * offset - i]);
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
