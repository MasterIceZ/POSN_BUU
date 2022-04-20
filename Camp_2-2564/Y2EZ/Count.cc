/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Count
 * ALGO		: Fenwick Tree
 * DATE		: 13 Apr 2022
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

// Josephus Problem

const int MxN = 200020;
bitset<MxN> alive;

struct FenwickTree{
	int tree[MxN];
	inline void build(int n){
		for(int i=1; i<=n; ++i){
			tree[i] += 1;
			if(i + (i & -i) <= n){
				tree[i + (i & -i)] += tree[i];
			}
		}
	}
	inline void update(int idx){
		for(; idx <= 200000; idx+=idx&-idx){
			tree[idx] -= 1;
		}
	}	
	inline int read(int idx){
		int res = 0;
		for(; idx; idx-=idx&-idx){
			res += tree[idx];
		}
		return res;
	}
	inline int next(int l, int r, int idx){
		int stp = l - 1;
		while(l < r){
			int mid = (l + r) >> 1;
			if(read(mid) - read(stp) >= idx){
				r = mid;
			}
			else{
				l = mid + 1;
			}
		}
		return l;
	}
} fw;

inline void solution(){
	int n, k;
	cin >> n >> k;
	fw.build(n);
	for(int people=n-1; people>=1; people--){
		fw.update(k);
		int cur = (k - 1) % people + 1;
		int nxt = fw.read(n) - fw.read(k);
		if(cur <= nxt){
			k = fw.next(k + 1, n, cur);
		}
		else{
			k = fw.next(1, k - 1, cur - nxt);
		}
	}
	cout << k ;
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
