/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: RO
 * ALGO		: Dynamic Programming 
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

inline void solution(){
	int n, k;
	string s;
	cin >> n >> k >> s;
	s = " " + s;
	int cnt_r = 0, cnt_o = 0;
	for(int i=1; i<=n; ++i){
		cnt_r += (s[i] == 'R');
		cnt_o += (s[i] == 'O');
	}
	if(cnt_o % cnt_r == 0 && cnt_o / cnt_r == k){
		cout << n;
		return ;
	}
	int res = 0;
	ll cur = 0;
	unordered_map<ll, int> mp;
	for(int i=1; i<=n; ++i){
		if(s[i] == 'R'){
			cur -= k;
		}
		else{
			cur += 1;
		}
		if(mp[cur]){
			res = max(res, i - mp[cur]);
		}
		else{
			mp[cur] = i;
		}
	}
	cout << res;
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
