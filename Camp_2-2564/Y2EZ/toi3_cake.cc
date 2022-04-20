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

int a[6];

inline void solution(){
	int n;
	cin >> n;
	for(int i=1; i<=n; ++i){
		for(int j=1, x; j<=5; ++j){
			cin >> x;
			a[j] += x;
		}
	}
	int split = 0, cnt = 0;
	while(a[1] + a[2] + a[3] + a[4] + a[5] != 0){
		if(a[1] > 0 && split >= 8){
			a[1]--;
			split -= 8;
		}
		else if(a[2] > 0 && split >= 6){
			a[2]--;
			split -= 6;
		}
		else if(a[3] > 0 && split >= 4){
			a[3]--;
			split -= 4;
		}
		else if(a[4] > 0 && split >= 2){
			a[4]--;
			split -= 2;
		}
		else if(a[5] > 0 && split >= 1){
			a[5]--;
			split--;
		}
		else{
			split = 8;
			cnt++;
		}
	}
	cout << cnt ;
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
