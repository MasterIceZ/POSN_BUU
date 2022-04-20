/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Fire
 * ALGO		: Heap
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
	int n;
	cin >> n;
	int max_state = 2 * n;
	vector<vector<int>> timer (max_state + 10);
	for(int i=1, x; i<=n; ++i){
		for(int j=1; j<=n; ++j){
			cin >> x;
			timer[i + j].emplace_back(x);
		}
	}
	int answer = 0;
	priority_queue<int> pq;
	for(int i=max_state; i>=3; --i){
		for(auto x: timer[i]){
			pq.emplace(x);
		}
		dbg(pq);
		answer += pq.top();
		pq.pop();
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
