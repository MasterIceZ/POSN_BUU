/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Anagram
 * ALGO		: Hash
 * DATE		: 14 Apr 2022
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

const int MxN = 2020;
const int HSH = 2129;

vector<ll> table;
ll pw[33];

inline void solution(){
	pw[0] = 1;
	for(int i=1; i<=27; ++i){
		pw[i] = pw[i - 1] * HSH;
	}
	string s, t;
	cin >> s >> t;
	int n = s.size(), m = t.size();
	s = " " + s, t = " " + t;
	for(int i=1; i<=n; ++i){
		ll hsh = 0;
		for(int j=i; j<=n; ++j){
			hsh += pw[s[j] - 'A'];
			table.emplace_back(hsh);
		}
	}
	sort(table.begin(), table.end());
	int answer = 0;
	for(int i=1; i<=m; ++i){
		ll hsh = 0;
		for(int j=i; j<=m; ++j){
			hsh += pw[t[j] - 'A'];
			if(*lower_bound(table.begin(), table.end(), hsh) == hsh){
				answer = max(answer, j - i + 1);
			}
		}
	}
	cout << answer;
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
