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
	int n;
	cin >> n;
	vector<int> a(n + 1);
	set<int> st;
	map<int, int> mp;
	int maxx = 0, res;
	for(int i=1; i<=n; ++i){
		cin >> a[i];
		st.emplace(a[i]);
		mp[a[i]]++;
		if(mp[a[i]] > maxx){
			maxx = mp[a[i]];
			res = a[i];
		}
	}
	if((int) st.size() == 1){
		cout << 0;
		return ;
	}
	int answer = 1;
	int number_of_swap = n - maxx;
	if(maxx * 2 >= n){
		answer += number_of_swap;
		cout << answer;
		return ;
	}
	answer += number_of_swap;
	while(n - maxx > 0){
		maxx *= 2;
		answer++;
	}
	cout << answer - 1;
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
