#include <bits/stdc++.h>

using namespace std;

const int MxN = 300030;

struct val_t {
	int one, zero;
	val_t(int v

struct segment_tree {
	struct node_t {
		val_t v;
		bool lazy;
		node_t(val_t _v, bool _lazy):
			v(_v), lazy(_lazy) {}
	};

signed main(int argc, char *argv[]) {
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int n;
	cin >> n;

	return 0;
}
