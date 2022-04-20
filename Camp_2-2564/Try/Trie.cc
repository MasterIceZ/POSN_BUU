/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		:
 * ALGO		:
 * DATE		:
 * */

#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//#include <ext/rope>

#ifndef _DEBUG
// @==== Libary ====@ //

// @================@ //
#endif

using namespace std;
//using namespace __gnu_pbds;
//using namespace __gnu_cxx;

// template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update> ;

// @=== Debugger ===@ //
#ifdef _DEBUG
#include "debug.hpp"
#else
#define dbg(...) 0
#endif
// @================@ //

using ll = long long;

struct Trie{
	struct TrieNode{
		map<char, int> next;
		bool isEnd;
		TrieNode(char nxt='$', int idx=-1, bool x=true){
			next.emplace(nxt, idx);
			isEnd = x;
		}
	};
	vector<TrieNode> tree;
	void insert(char v, int idx, bool isEnd){
		if(tree.empty() && idx == 0){
			tree.emplace_back(v, -1, isEnd);
			return ;
		}
		bool gone = false;
		for(auto x: tree[idx].next){
			if(x.first == v){
				gone = true;
				insert(v, x.second, isEnd);
				break;
			}
		}
		if(!gone){
			tree[idx].next[v] = tree.size();
			tree.emplace_back(v, tree.size(), isEnd);
		}
	}
	inline void insert(string s){
		for(auto x: s){
			insert(x, 0, false);
		}
	}
} trie;

inline void solution(){
	string s = "abc";
	trie.insert(s);
	for(auto x: trie.tree[1].next){
		dbg(x);
	}
	for(auto x: trie.tree[2].next){
		dbg(x);
	}
	return ;
}

signed main(){
	int q = 1;
//	cin >> q;
	while(q--){
		solution();
		cout << "\n";
	}
	return 0;
}
// https://github.com/MasterIceZ/archive/tree/main/cpp-template
