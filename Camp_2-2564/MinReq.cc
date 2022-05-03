/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: toi15_minreq
 * ALGO		: Brute Force, Permutation
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

const int MxN = 12;
const int MxM = 1e7 + 10;
int q, n, m, l[MxN], a[MxN], s[MxM], x[MxN];
bitset<MxN> used;

inline bool calc(int t){
	for(int i=1; i<=n; ++i){
		cin >> x[i];
	}
	x[n + 1] = m;
	do{
		used = 0;
		bool can = true;
		for(int i=1, j; i<=n; ++i){
			for(j=1; j<=n; ++j){
				if(used[j]){
					continue;
				}
				int left_bound = x[i], right_bound = x[i + 1], cnt = 0;
				bool ok = true;
				while(ok && left_bound < right_bound){
					int next = upper_bound(s + left_bound, s + right_bound, l[j] - a[i] - s[left_bound - 1]) - (s);
					cnt++;
					if(next == left_bound){
						ok = false;
					}
					left_bound = next;
				}
				if(cnt <= t && ok){
					used[j] = true;
					break;
				}
			}
			if(j == n + 1){
				can = false;
				break;
			}
		}
		if(can){
			return true;
		}
	}while(next_permutation(a + 1, a + n + 1));
	return false;
}

inline void solution(){
	cin >> n >> m >> q;
	for(int i=1; i<=n; ++i){
		cin >> l[i];
	}
	sort(l + 1, l + n + 1);
	for(int i=1; i<=n; ++i){
		cin >> a[i];
	}
	for(int i=1; i<=m; ++i){
		cin >> s[i];
		s[i] += s[i - 1];
	}
	vector<int> qry;
	for(int i=1, x; i<=q; ++i){
		cin >> x;
		qry.emplace_back(x);
	}
	for(auto x: qry){
		cout << (calc(x)? "P": "F") << "\n";
	}
	return ;
}

signed main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);	
	int q = 1;
//	cin >> q;
	while(q--){
		solution();
	}
	return 0;
}
// https://github.com/MasterIceZ/archive/tree/main/cpp-template
