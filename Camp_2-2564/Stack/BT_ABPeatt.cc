/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: BT_ABPeatt
 * ALGO		: Queue
 * DATE		: 16 Apr 2022
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
	string s;
	int k;
	cin >> s >> k;
	int n = s.size(), cnt = 0, answer = 0;
	s = " " + s;
	queue<char> q;
	for(int i=1; i<=n; ++i){
		q.emplace(s[i]);
		if(s[i] == 'B'){
			cnt++;
		}
		while(cnt > k){
			cnt -= (q.front() == 'B');
			q.pop();
		}
		answer = max(answer, (int) q.size());
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
