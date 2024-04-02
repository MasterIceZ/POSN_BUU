#include <bits/stdc++.h>

using namespace std;

const int MxN = 3000030;

int h[MxN];
stack<int> st;

signed main(int argc, char *argv[]) {
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for(int i=1; i<=n; ++i) {
		cin >> h[i];
	}
	st.emplace(n);
	int answer = 0, idx = -1;
	for(int i=n-1; i>=1; --i) {
		while(!st.empty() && h[st.top()] <= h[i]) {
			st.pop();
		}
		st.emplace(i);
		if(answer < ((int) st.size() - 1)) {
			answer = (int) st.size() - 1;
			idx = i;
		}
		else if(answer == ((int) st.size() - 1)) {
			idx = i;
		}
	}
	if(answer == 0 || idx == -1) {
		cout << -1 << "\n";
	}
	else {
		cout << idx << " " << answer << "\n";
	}
	return 0;
}
