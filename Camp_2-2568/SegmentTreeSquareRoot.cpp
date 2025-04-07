#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 100;
const int MxN = 100010;

struct segmen_tree {
	int t[MxN << 2];
	void update(int l, int r, int id, int v, int idx) {
		if(l > id || r < id || l > r) {
			return ;
		}
		if(l == r) {
			t[idx] = v;
			return ;
		}
		int mid = (l + r) >> 1;
		update(l, mid, id, v, idx << 1);
		update(mid + 1, r, id, v, idx << 1 | 1);
		t[idx] = max(t[idx << 1], t[idx << 1 | 1]);
	}
	int query(int l, int r, int wl, int wr, int idx) {
		if(l > r || l > wr || r < wl) {
			return -INF;
		}
		if(wl <= l && r <= wr) {
			return t[idx];
		}
		int mid = (l + r) >> 1;
		return max(query(l, mid, wl, wr, idx << 1), query(mid + 1, r, wl, wr, idx << 1 | 1));
	}
} seg;

signed main(int argc, char *argv[]) {
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int n, q;
	cin >> n >> q;
	while(q--) {
		char o;
		cin >> o;
		if(o == 'U') {
			int x, v;
			cin >> x >> v;
			seg.update(1, n, x, v, 1);
		}
		else {
			int wl, wr;
			cin >> wl >> wr;
			cout << seg.query(1, n, wl, wr, 1) << "\n";
		}
	}
	return 0;
}
