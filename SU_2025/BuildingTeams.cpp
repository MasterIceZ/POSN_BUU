#include <bits/stdc++.h>

using namespace std;

const int MxN = 100010;

vector<int> adj[MxN];
int color[MxN];

bool bipartite_check(int u, int c) {
    if(color[u] != 0) {
        return color[u] == c;
    }
    color[u] = c;
    for(auto v: adj[u]) {
        if(bipartite_check(v, 3 - c) == false) {
            return false;
        }
    }
    return true;
}

signed main(int argc, char *argv[]) {
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for(int i=1, u, v; i<=m; ++i) {
		cin >> u >> v;
		adj[u].emplace_back(v);
		adj[v].emplace_back(u);
	}
	bool ok = true;
	for(int i=1; i<=n; ++i) {
		if(color[i] != 0) {
			continue;
		}
		ok &= bipartite_check(i, 1);
	}
	if(!ok) {
		cout << "IMPOSSIBLE\n";
	}
	else {
		for(int i=1; i<=n; ++i) {
			cout << color[i] << " ";
		}
		cout << "\n";
	}
	return 0;
}
