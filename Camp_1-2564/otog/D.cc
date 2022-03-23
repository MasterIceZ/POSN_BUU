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

int n, m;
void rec(int cur, int state){
	cout << cur << " " ;
	if(state == 1 && cur == n){
		return ;
	}
	if(state == 0 && cur - m < 0){
		cout << "PULL ";
		rec(cur, 1);
		return ;
	}
	if(!state){
		rec(cur - m, state);
		return ;
	}
	rec(cur + m, state);
}

inline void solution(){
	cin >> n >> m;
	rec(n, 0);
	return ;
}

signed main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);	
	solution();
	cout << "\n";
	return 0;
}
// https://github.com/MasterIceZ/archive/tree/main/cpp-template
