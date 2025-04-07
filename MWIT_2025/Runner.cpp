#include <bits/stdc++.h>

using namespace std;

const int MxN = 100010;
const int MxM = 10010;

int cnt_lane[MxM], mem_idx[MxN], mem_max[MxN];

signed main(int argc, char *argv[]) {
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int n, m, max_cnt = 0;
	cin >> n >> m;
	for(int i=1, id, lane, speed; i<=n; ++i) {
		cin >> id >> lane >> speed;
		int pos = ++cnt_lane[lane];
		max_cnt = max(max_cnt, cnt_lane[lane]);
		if(speed > mem_max[pos]) {
			mem_max[pos] = speed;
			mem_idx[pos] = id;
		}
		else if(speed == mem_max[pos] && id < mem_idx[pos]) {
			mem_idx[pos] = id;
		}
	}
	for(int i=1; i<=max_cnt; ++i) {
		cout << mem_idx[i] << "\n";
	}
	return 0;
}
