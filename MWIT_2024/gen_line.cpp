#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;

signed main(int argc, char *argv[]) {
	registerGen(argc, argv, 1);
	int N = opt<int> ("n");
	int Q = 1000000;

	vector<int> order;
	for(int i=1; i<=N; ++i) {
		order.emplace_back(i);
	}
	random_device rd;
	mt19937 g(rd());
	shuffle(order.begin(), order.end(), g);
	
	cout << N << " " << N - 1 << " " << 1 << "\n";
	for(int i=1; i<N; ++i) {
		int state = rnd.next(0, 1);
		if(state == 0) {
			cout << order[i - 1] << " " << order[i];
		}
		else {
			cout << order[i] << " " << order[i - 1];
		}
		cout << "\n";
	}
	cout << order[0] << "\n";
	cout << Q << "\n";
	while(Q--) {
		int state = rnd.next(0, 5);
		if(state == 0) {
			int k = rnd.next(N - 11, N - 1);
			cout << order[0] << " " << order[k] << "\n";
		}
		else {
			int state2 = rnd.next(0, 1);
			int idx_u = rnd.next(0, N - 2);
			int idx_v = rnd.next(1 + idx_u, N - 1);
			int u = order[idx_u], v = order[idx_v];
			if(state2 == 0) {
				cout << u << " " << v;
			}
			else {
				cout << v << " " << u;
			}
			cout << "\n";
		}
	}
	return 0;	
}
