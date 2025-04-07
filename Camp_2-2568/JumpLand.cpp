#include <bits/stdc++.h>

using namespace std;

const int MxN = 770;

struct merge_t {
	pair<int, int> u, v;
	double t;
	merge_t(pair<int, int> _u, pair<int, int> _v, double _t):
		u(_u), v(_v), t(_t) {}
	bool operator < (const merge_t &o) const {
		return t < o.t;
	}
};

struct disjoint_set_union {
	pair<int, int> parent[MxN][MxN];
	int sz[MxN][MxN];
	disjoint_set_union() {
		for(int i=1; i<MxN; ++i) {
			for(int j=1; j<MxN; ++j) {
				parent[i][j] = make_pair(i, j);
				sz[i][j] = 1;
			}
		}
	}
	pair<int, int> find_root(pair<int, int> u) {
		while(u != parent[u.first][u.second]) {
			u = parent[u.first][u.second];
		}
		return u;
	}
	void unite(pair<int, int> u, pair<int, int> v) {
		pair<int, int> ru = find_root(u);
		pair<int, int> rv = find_root(v);
		if(ru == rv) {
			return ;
		}
		if(sz[ru.first][ru.second] > sz[rv.first][rv.second]) {
			swap(ru, rv);
		}
		sz[rv.first][rv.second] += sz[ru.first][ru.second];
		parent[ru.first][ru.second] = rv;
	}
	int get_sz(pair<int, int> u) {
		pair<int, int> ru = find_root(u);
		return sz[ru.first][ru.second];
	}
};

double h[MxN][MxN], s[MxN][MxN];
disjoint_set_union dsu;
vector<merge_t> merge_time;
stack<pair<pair<int, int>, pair<int, int>>> rollback_stack;
int max_size;

void add_merge_time(pair<int, int> a, pair<int, int> b) {
	if(s[a.first][a.second] != s[b.first][b.second]) {
		double t = (h[a.first][a.second] - h[b.first][b.second]) / (s[b.first][b.second] - s[a.first][a.second]);
		if(t < 0) {
			return ;
		}
		merge_time.emplace_back(a, b, t);
	}
	else if(h[a.first][a.second] != h[b.first][b.second]) {
		dsu.unite(a, b);
		max_size = max(max_size, dsu.get_sz(a));
	}
}

void rollback() {
	while(!rollback_stack.empty()) {
		pair<pair<int, int>, pair<int, int>> op = rollback_stack.top();
		rollback_stack.pop();
		pair<int, int> ru = dsu.find_root(op.first), rv = dsu.find_root(op.second);
		dsu.sz[ru.first][ru.second] -= dsu.sz[rv.first][rv.second];
		dsu.parent[rv.first][rv.second ] = rv;
	}
}

void temporary_unite(pair<int, int> u, pair<int, int> v) {
	pair<int, int> ru = dsu.find_root(u);
	pair<int, int> rv = dsu.find_root(v);
	if(dsu.get_sz(ru) > dsu.get_sz(rv)) {
		swap(ru, rv);
	}
	rollback_stack.emplace(rv, ru);
	dsu.unite(rv, ru);
}

signed main(int argc, char *argv[]) {
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int n;
	cin >> n;
	max_size = 1;
	for(int i=1; i<=n; ++i) {
		for(int j=1; j<=n; ++j) {
			cin >> h[i][j];
		}
	}
	for(int i=1; i<=n; ++i) {
		for(int j=1; j<=n; ++j) {
			cin >> s[i][j];
		}
	}
	for(int i=1; i<=n; ++i) {
		for(int j=1; j<=n; ++j) {
			if(i + 1 <= n) {
				add_merge_time(make_pair(i, j), make_pair(i + 1, j));
			}
			if(j + 1 <= n) {
				add_merge_time(make_pair(i, j), make_pair(i, j + 1));
			}
		}
	}
	merge_time.emplace_back(make_pair(0, 0), make_pair(0, 0), -1);
	sort(merge_time.begin(), merge_time.end());
	for(int i=1; i<(int) merge_time.size(); ++i) {
		if(merge_time[i].t != merge_time[i - 1].t) {
			rollback();
		}
		temporary_unite(merge_time[i].u, merge_time[i].v);
		max_size = max(max_size, dsu.get_sz(merge_time[i].u));
	}
	cout << max_size << "\n";
	return 0;
}
