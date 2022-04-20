/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: PT_Brackets
 * ALGO		: Heap
 * DATE		: 17 Apr 2022
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
	cin >> s;
	ll res = 0, a, b, k = 0;
	bool ok = true;
	priority_queue<ll> pq;
	for(auto x: s){
		if(x == '('){
			k++;
		}
		else if(x == ')'){
			k--;
		}
		else{
			cin >> a >> b;
			pq.emplace(b - a);
			res += b;
			k--;
		}
		if(k < 0){
			if(pq.empty()){
				ok = false;
				break;
			}
			else{
				res -= pq.top();
				pq.pop();
				k += 2;
			}
		}
	}
	cout << ((k == 0 && ok)? res: -1);
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
