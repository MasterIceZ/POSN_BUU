#include <bits/stdc++.h>

using namespace std;
using ll = long long;

inline void solve() {
	int n, m;
	cin >> n >> m;
	deque<ll> v(n);
	for(auto &x: v) {
		cin >> x;
	}
	string s;
	cin >> s;
	stack<ll> oprs, answer_stk;
	for(auto x: s) {
		if(x == 'L') {
			oprs.emplace(v.front());
			v.pop_front();
		}
		else {
			oprs.emplace(v.back());
			v.pop_back();
		}
	}
	ll answer = 1ll % m;
	while(!oprs.empty()) {
		ll t = oprs.top();
		oprs.pop();
		answer = (answer * t) % m;
		answer_stk.emplace(answer);
	}
	while(!answer_stk.empty()) {
		ll t = answer_stk.top();
		answer_stk.pop();
		cout << t << " ";
	}
	cout << "\n";
	return ;
}

signed main(int argc, char *argv[]) {
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--) {
		solve();
	}
	return 0;
}
