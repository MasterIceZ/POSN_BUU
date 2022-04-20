/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: BST Travel 2
 * ALGO		: ?
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

struct BST{
	struct Node{
		int v, l, r;
		Node(int a=0, int b=-1, int c=-1): v(a), l(b), r(c) {}
	};
	Node tree[333];
	int cnt = 0;
	inline void insert(int v){
		if(cnt == 0){
			tree[1].v = v;
			cnt = 1;
			return ;
		}
		int cur = 1;
		tree[++cnt].v = v;
		while(1){
			if(tree[cur].v < v){
				if(tree[cur].r == -1){
					tree[cur].r = cnt;
					break;
				}
				else{
					cur = tree[cur].r;
				}
			}
			else{
				if(tree[cur].l == -1){
					tree[cur].l = cnt;
					break;
				}
				else{
					cur = tree[cur].l;
				}
			}
		}
	}
	void preorder(int x){
		cout << tree[x].v << " ";
		if(tree[x].l != -1){
			preorder(tree[x].l);
		}
		if(tree[x].r != -1){
			preorder(tree[x].r);
		}
	}
	void inorder(int x){
		if(tree[x].l != -1){
			inorder(tree[x].l);
		}
		cout << tree[x].v << " ";
		if(tree[x].r != -1){
			inorder(tree[x].r);
		}
	}
	void postorder(int x){
		if(tree[x].l != -1){
			postorder(tree[x].l);
		}
		if(tree[x].r != -1){
			postorder(tree[x].r);
		}
		cout << tree[x].v << " ";
	}
} bst;

inline void solution(){
	int n, x;
	cin >> n;
	for(int i=1, x; i<=n; ++i){
		cin >> x;
		bst.insert(x);
	}
	bst.preorder(1);
	cout << "\n";
	bst.postorder(1);
	cout << "\n";
	bst.inorder(1);
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
