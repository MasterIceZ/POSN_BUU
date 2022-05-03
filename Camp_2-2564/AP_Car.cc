/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: AP_Car 
 * ALGO		: Greedy
 * DATE		: 22 Apr 2022
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
struct Car{
	int stp, edp;
	bool operator < (const Car& o) const {
		if(stp != o.stp){
			return stp < o.stp;
		}
		return edp > o.edp;
	}
};

Car car[MxN];

inline void solution(){
	int n, t;
	cin >> n >> t;
	for(int i=1, x; i<=n; ++i){
		cin >> car[i].stp >> x;
		car[i].edp = car[i].stp + x * t;
	}
	sort(car + 1, car + n + 1);
	int last_stp = -1, last_edp = -1;
	int answer = 0;
	for(int i=1; i<=n; ++i){
		if(car[i].edp < last_edp){
			continue;
		}
		if(car[i].edp == last_edp && car[i].stp > last_stp){
			continue;
		}
		answer++;
		last_stp = car[i].stp;
		last_edp = car[i].edp;
	}
	cout << answer;
	return ;
}

signed main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);	
	int q = 1;
	cin >> q;
	while(q--){
		solution();
		cout << "\n";
	}
	return 0;
}
// https://github.com/MasterIceZ/archive/tree/main/cpp-template
