/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: AP_Magic Hat
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

struct Hat{
	int v, w, type, next, w2;
	Hat(int a, int b, int c, int d, int e): v(a), w(b), type(c), next(d), w2(e) {} 
	bool operator < (const Hat& o) const {
		return w > o.w;
	}
};

inline void DB(priority_queue<Hat> pq){
	dbg("----");
	while(!pq.empty()){
		dbg(pq.top().v, pq.top().w, pq.top().next, pq.top().w2);
		pq.pop();
	}
	dbg("----");
}

inline void solution(){
	int n, m, type, v, w, d, x;
	cin >> n >> m;
	priority_queue<Hat> pq;
	for(int i=1, t; i<=n+m; ++i){
		cin >> t;
		if(t == 1){
			cin >> type;
			if(type == 1){
				cin >> w >> v;
				pq.emplace(v, w, 1, -1, -1);
			}
			else if(type == 2){
				cin >> w >> v >> d;
				pq.emplace(v, w, 2, d, -1);
			}
			else{
				cin >> w >> v >> d >> x;
				pq.emplace(v, w, 3, d, x);
			}
		}
		else{
			while(!pq.empty() && pq.top().type != 1 && pq.top().next <= i){
				Hat tmp = pq.top();
				pq.pop();
				dbg(tmp.v, tmp.w);
				if(tmp.type == 2){
					continue;
				}
				dbg(tmp.v, tmp.w2);
				pq.emplace(tmp.v, tmp.w2, 1, -1, -1);
			}
			DB(pq);
			if(pq.empty()){
				cout << "0";
			}
			else{
				dbg(pq.top().w);
				cout << pq.top().v ;
				pq.pop();
			}
			cout << "\n";
		}
	}
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
