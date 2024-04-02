#include "testlib.h"
#include <bits/stdc++.h>
#include "aquagenlib.h"

using namespace std;

signed main(int argc, char *argv[]) {
	registerGen(argc, argv, 1);
	int MIN_N = atoi(argv[1]);
	int MAX_N = atoi(argv[2]);
	int MIN_M = atoi(argv[3]);
	int MAX_M = atoi(argv[4]);
	const int MAX_W = 1e9;
	
	int n = rnd.next(MIN_N, MAX_M);
	int m = rnd.next(MIN_M, (int) min((ll) n * ((ll) n - 1ll) / 2ll, (ll) MAX_M));

	vector<pair<int, int>> g = gen_connected_graph(n, m);

	cout << n << " " << m << "\n";
	for(auto edge: g) {
		ll w = rnd.next(1, MAX_W);
		cout << edge.first << " " << edge.second << " " << w << "\n";
	}
	return 0;
}
