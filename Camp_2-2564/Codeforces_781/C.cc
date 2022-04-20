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

const int MxN = 2e5 + 10;
int deg[MxN];
vector<int> v;

inline bool ok(int x){
	int le = x - v.size();
	for(int i=0; i<(int) v.size(); ++i){
		le -= max(0, v[i] + i - x);
	}
	return le >= 0;
}

inline void solution(){
	memset(deg, 0, sizeof deg);
	v.clear();
	int n;
	cin >> n;
	for(int i=2, x; i<=n; ++i){
		cin >> x;
		deg[x]++;
	}
	for(int i=1; i<=n; ++i){
		if(deg[i] > 0){
			v.emplace_back(deg[i]);
		}
	}
	v.emplace_back(1);
	sort(v.begin(), v.end(), greater<int> ());
	int l = (int) v.size() - 1, r = n;
	while(l < r){
		int mid = (l + r) >> 1;
//		dbg(l, r);
		if(ok(mid)){
			r = mid;
		}
		else{
			l = mid + 1;
		}
	}
	cout << l;
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
