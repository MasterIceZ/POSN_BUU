#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;

const long long MAX_X = 1e18;

signed main(int argc, char *argv[]) {
	registerGen(argc, argv, 1);
	int N = opt<int> ("n");
	int answer_position = rnd.next(1, N);
	set<long long> numbers;

	for(int i=1; i<=N; ++i) {
		long long x = rnd.next(1ll, MAX_X);
		numbers.emplace(x);
	}

	int expected_position = rnd.next(1, N);
	for(int i=1; i<=n; ++i) {

	}

	cout << N << "\n";
	cout << 
	return 0;
}
