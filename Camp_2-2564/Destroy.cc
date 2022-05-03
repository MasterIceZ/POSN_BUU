/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Destroy Bottle
 * ALGO		: Greedy, Brute Force
 * DATE		: 21 Apr 2022
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

struct A{
	int w, idx;
	bool operator < (const A& o) const {
		return w < o.w;
	}
	A(int a, int b): w(a), idx(b) {}
};

const int MxN = 100010;
int timer[MxN];

inline void solution(){
	priority_queue<A> pq;
	int n, q;
	cin >> n >> q;
	for(int i=1, x; i<=n; ++i){
		cin >> x;
		pq.emplace(x, i);
	}
	for(int i=1, x, res=0; i<=q; ++i, res=0){
		cin >> x;
		while(!pq.empty()){
			A now = pq.top();
			if(now.w > x){
				if(timer[now.idx] != i && timer[now.idx]){
					pq.pop();
					continue;
				}
				if(!timer[now.idx + 1] && now.idx + 1 <= n){
					timer[now.idx + 1] = i;
					res++;
				}
				if(!timer[now.idx - 1] && now.idx - 1 >= 1){
					timer[now.idx - 1] = i;
					res++;
				}
				if(!timer[now.idx]){
					timer[now.idx] = i;
					res++;
				}
				pq.pop();
			}
			else{
				break;
			}
		}
		cout << res << "\n";
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
