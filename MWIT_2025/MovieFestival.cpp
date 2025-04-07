#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct interval_t {
	int l, r;
	interval_t(int _l, int _r):
		l(_l), r(_r) {}
	bool operator < (const interval_t &o) const {
		if(r != o.r) {
			return r < o.r;
		}
		return l < o.l;
	}
};

bool collide(interval_t a, interval_t b) {
	return b.r < a.l || a.r > b.l;
}

signed main(int argc, char *argv[]) {
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<interval_t> movies;
	for(int i=1, l, r; i<=n; ++i) {
		cin >> l >> r;
		movies.emplace_back(l, r);
	}
	sort(movies.begin(), movies.end());
	interval_t last(-1, -1);
	int cnt = 0;
	for(auto movie: movies) {
		if(collide(last, movie)) {
			continue;
		}
		last = movie;
		cnt++;
	}
	cout << cnt << "\n";
	return 0;
}
