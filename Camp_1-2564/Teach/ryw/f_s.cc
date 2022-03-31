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

struct A{
	int val, idx, cnt;
	bool operator < (const A& o) const {
		if(cnt != o.cnt){
			return cnt > o.cnt;
		}
		return idx < o.idx;
	}
};

inline void solution(){
	int n, _;
	cin >> n >> _;
	map<int, int> mp, id;
	for(int i=1, x; i<=n; ++i){
		cin >> x;
		mp[x]++;
		if(id[x] == 0){
			id[x] = i;
		}
	}
	vector<A> v;
	for(auto x: mp){
		v.push_back({x.first, id[x.first], x.second});
	}
	sort(v.begin(), v.end());
	for(auto x: v){
		while(x.cnt--){
			cout << x.val << " ";
		}
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
