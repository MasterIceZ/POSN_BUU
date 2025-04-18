#include <bits/stdc++.h>

using namespace std;

bool ask(int x) {
	cout << x << endl;
	string r;
	cin >> r;
	return r == ">=";
}

signed main(int argc, char *argv[]) {
	int l = 1, r = 1000000;
	while(l < r) {
		int mid = (l + r + 1) / 2;
		if(ask(mid)) {
			l = mid;
		}
		else {
			r = mid - 1;
		}
	}
	cout << "! " << l << endl;
	return 0;
}
