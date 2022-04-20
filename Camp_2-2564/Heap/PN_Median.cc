/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: PN_Median
 * ALGO		: Heap
 * DATE		: 11 Apr 2022
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
	ll x;
	cin >> n;
	priority_queue<ll> minn;
	priority_queue<ll, vector<ll>, greater<ll>> maxx;
	cin >> x;
	minn.emplace(x);
	cout << x << ".0\n" ;
	double med = x;
	for(int i=2; i<=n; ++i){
		cin >> x;
		if(minn.size() == maxx.size()){
			if(x <= med){
				minn.emplace(x);
				med = (double) minn.top();
			}
			else{
				maxx.emplace(x);
				med = (double) maxx.top();
			}
		}
		else if(minn.size() > maxx.size()){
			if(x > med){
				maxx.emplace(x);
			}
			else{
				maxx.emplace(minn.top());
				minn.pop();
				minn.emplace(x);
			}
			med = (double) (maxx.top() + minn.top()) / 2;
		}
		else{
			if(x > med){
				minn.emplace(maxx.top());
				maxx.pop();
				maxx.emplace(x);
			}
			else{
				minn.emplace(x);
			}
			med = (double) (maxx.top() + minn.top()) / 2;
		}
		cout << fixed << setprecision(1) << med << "\n" ;
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
