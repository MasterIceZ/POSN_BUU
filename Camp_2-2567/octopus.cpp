// Q_Octopus

#include <bits/stdc++.h>

using namespace std;

const int MxN = 100010;

int w[MxN], qs[MxN], out[MxN];
int p[MxN], cycle[MxN];

signed main(int argc, char *argv[]) {
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	for(int i=1; i<=k; ++i) {
		cin >> w[i];
		qs[i] = qs[i - 1] + w[i]; // store weight in circle
	}
	for(int i=k+1, v; i<=n; ++i) {
		cin >> v >> w[i];
		p[v] = i;
	}
	for(int i=1; i<=k; ++i) {
		int v = i;
		cycle[v] = i; // cycle[v] = from v to who in cycle
		while(p[v] != 0) {
			out[p[v]] = out[v] + w[p[v]]; // out[i] = weight from cycle to i
			v = p[v];
			cycle[v] = i;
		}
	}
	int q;
	cin >> q;
	while(q--) {
		int a, b;
		cin >> a >> b;
		if(cycle[a] == cycle[b]) {
			// in same branch
			cout << abs(out[a] - out[b]) << "\n";
			continue;
		}
		// run from a to circle and b to circle
		int answer = out[a] + out[b];
		int root_a = cycle[a]; // root of a (in circle)
		int root_b = cycle[b]; // root of b (in circle)
		if(root_a > root_b) {
			swap(root_a, root_b);
		}
		int first_path = qs[root_b - 1] - qs[root_a - 1]; // main path
		int second_path = qs[k] - first_path; // alternating path
		answer += min(first_path, second_path);
		cout << answer << "\n";
	}
	return 0;
}
