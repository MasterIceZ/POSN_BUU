/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Expression Tree
 * ALGO		: Expression Tree
 * DATE		: 17 Apr 2022
 * */

#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// #include <ext/rope>

#ifndef _DEBUG
// @==== Libary ====@ //

// @================@ //
#endif

using namespace std;
// using namespace __gnu_pbds;
// using namespace __gnu_cxx;

// template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update> ;

// @=== Debugger ===@ //
#ifdef _DEBUG
#include "debug.hpp"
#else
#define dbg(...) 0
#endif
// @================@ //

using ll = long long;

struct Node{
	char v, l, r;
	Node(char a='$', char b=0, char c=0): v(a), l(b), r(c) {}
};

const int MxN = 1010;
Node tree[MxN];

stack<int> st;

void inorder(int x){
	if(tree[x].l){
		cout << "(";
		inorder(tree[x].l);
	}
	cout << tree[x].v;
	if(tree[x].r){
		inorder(tree[x].r);
		cout << ")";
	}
}

void preorder(int x){
	cout << tree[x].v;
	if(tree[x].l){
		preorder(tree[x].l);
	}
	if(tree[x].r){
		preorder(tree[x].r);
	}
}

inline void solution(){
	string s;
	getline(cin, s);
	int it = 0;
	for(auto x: s){
		if(x == ' '){
			continue;
		}
		if(isalpha(x)){
			tree[++it].v = x;
			st.emplace(it);
			dbg(st);
		}
		else if(x == '+' || x == '-' || x == '*' || x == '/'){
			tree[++it].v = x;
			tree[it].r = st.top();
			st.pop();
			tree[it].l = st.top();
			st.pop();
			st.push(it);
		}
	}
	inorder(it);
	cout << "\n";
	preorder(it);
	cout << "\n";
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
