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

inline void solution(){
	vector<int> v = {0, 1, 2, 3, 4, 5, 6};
	string s;
	cin >> s;
	for(auto x: s){
		if(x == 'F'){
			v[0] = v[2];
			v[2] = v[1];
			v[1] = v[5];
			v[5] = v[6];
			v[6] = v[0];
		}
		else if(x == 'B'){
			v[0] = v[1];
			v[1] = v[2];
			v[2] = v[6];
			v[6] = v[5];
			v[5] = v[0];
		}
		else if(x == 'L'){
			v[0] = v[1];
			v[1] = v[4];
			v[4] = v[6];
			v[6] = v[3];
			v[3] = v[0];
		}
		else if(x == 'R'){
			v[0] = v[1];
			v[1] = v[3];
			v[3] = v[6];
			v[6] = v[4];
			v[4] = v[0];
		}
		else if(x == 'C'){
			v[0] = v[2];
			v[2] = v[4];
			v[4] = v[5];
			v[5] = v[3];
			v[3] = v[0];
		}
		else{
			v[0] = v[2];
			v[2] = v[3];
			v[3] = v[5];
			v[5] = v[4];
			v[4] = v[0];
		}
	}
	cout << v[2] << " ";
	return ;
}

signed main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);	
	int q = 1;
	cin >> q;
	while(q--){
		solution();
	}
	return 0;
}
// https://github.com/MasterIceZ/archive/tree/main/cpp-template
