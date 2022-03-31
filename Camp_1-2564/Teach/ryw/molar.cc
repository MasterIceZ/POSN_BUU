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

char s[111];
stack<ll> st;

inline void solution(){
	scanf(" %s", s + 1);
	int len = strlen(s + 1);
	for(int i=1; i<=len; ++i){
		char a = s[i];
		if(a == '('){
			st.push(-1);
		}
		else if(a == ')'){
			ll sum = 0;
			while(!st.empty() && st.top() != -1){
				sum += st.top();
				st.pop();
			}
			st.pop();
			st.push(sum);
		}
		else if(isdigit(a)){
			ll now = a - '0';
			ll cur = st.top();
			st.pop();
			st.push(now * cur);
		}
		else{
			ll to_push = -1;
			if(a == 'H'){
				to_push = 1;
			}
			else if(a == 'O'){
				to_push = 16;
			}
			else{
				to_push = 12;
			}
			st.push(to_push);
		}
	}
	ll res = 0;
	while(!st.empty()){
		res += st.top();
		st.pop();
	}
	printf("%lld", res);
	return ;
}

signed main(){
//	cin.tie(nullptr)->ios::sync_with_stdio(false);	
	int q = 1;
	scanf("%d", &q);
	while(q--){
		solution();
		printf("\n");
	}
	return 0;
}
// https://github.com/MasterIceZ/archive/tree/main/cpp-template
