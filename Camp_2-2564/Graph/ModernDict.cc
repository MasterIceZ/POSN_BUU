/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Modern Dictionary
 * ALGO		: Topological Sort, Kahn's Algorithm
 * DATE		: 22 Apr 2022
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

vector<int> adj[33];
int in[33];
set<char> st;
bitset<33> have;

inline void solution(){
	int n;
	string s, last;
	cin >> n >> last;
	if(n == 1){
		cout << "?";
		return ;
	}
	for(auto x: last){
		st.emplace(x);
	}
	for(int i=2; i<=n; ++i){
		cin >> s;
		for(int j=0; j<(int) min(s.size(), last.size()); ++j){
			if(last[j] != s[j]){
				adj[last[j] - 'a'].emplace_back(s[j] - 'a');
				in[s[j] - 'a']++;
				have[s[j] - 'a'] = true;
				have[last[j] - 'a'] = true;
				break;
			}
		}
		for(auto x: s){
			st.emplace(x);
		}
		last = s;
	}
	queue<int> q, res;
	for(auto x: st){
		if(!in[x - 'a'] && have[x - 'a']){
			q.emplace(x - 'a');
		}
	}
	while(!q.empty()){
		if(q.size() != 1){
			cout << "?";
			return ;
		}
		int now = q.front();
		q.pop();
		res.emplace(now);
		for(auto x: adj[now]){
			if(--in[x] == 0){
				q.emplace(x);
			}
		}
	}
	for(int i=0; i<26; ++i){
		if(in[i] > 0){
			cout << "!";
			return ;
		}
	}
	if(res.size() != st.size()){
		cout << "?";
		return ;
	}
	while(!res.empty()){
		cout << (char)('a' + res.front());
		res.pop();
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
