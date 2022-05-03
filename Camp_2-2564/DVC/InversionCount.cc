/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Inversion Count
 * ALGO		: Fenwick Tree
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

#define int ll
const int MxN = 100010;

struct Fenwick{
	int tree[MxN];
	inline void update(int idx, int val){
		for(; idx<=100000; idx+=idx&-idx){
			tree[idx] += val;
		}
	}
	inline int read(int idx){
		int res = 0;
		for(; idx; idx-=idx&-idx){
			res += tree[idx];
		}
		return res;
	}
} fw;

int a[MxN];

inline void solution(){
	int n;
	cin >> n;
	vector<int> compress;
	for(int i=1; i<=n; ++i){
		cin >> a[i];
		compress.emplace_back(a[i]);
	}
	sort(compress.begin(), compress.end());
	compress.resize(unique(compress.begin(), compress.end()) - compress.begin());
	for(int i=1; i<=n; ++i){
		a[i] = upper_bound(compress.begin(), compress.end(), a[i]) - compress.begin();
	}
	dbg(to_string(a, 1, n));
	int cnt = 0;
	for(int i=n; i>=1; --i){
		fw.update(a[i], 1);
		cnt += fw.read(a[i] - 1);
	}
	cout << cnt;
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
