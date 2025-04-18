#include <bits/stdc++.h>

using namespace std;

const int MxN = 1010;
const int di[] = {0, -1, 1, 0}, dj[] = {-1, 0, 0, 1};

string a[MxN], s;
deque<pair<int, int>> q;
int dist[MxN][MxN];

inline void solve() {
	int n, m;
	cin >> n >> m;
	for(int i=1; i<=n; ++i) {
		cin >> s;
		a[i] = " " + s;
	}
	memset(dist, 0x3f, sizeof dist);
	q.emplace_back(1, 1);
	dist[1][1] = 0;
	while(!q.empty()) {
		pair<int, int> u = q.front();
		q.pop_front();
		for(int k=0; k<4; ++k) {
			int ii = u.first + di[k];
			int jj = u.second + dj[k];
			if(ii < 1 || jj < 1 || ii > n || jj > m) {
				continue;
			}
			if(a[ii][jj] == a[u.first][u.second] && dist[ii][jj] > dist[u.first][u.second]) {
				q.emplace_front(ii, jj);
				dist[ii][jj] = dist[u.first][u.second];
			}
			else if(a[ii][jj] != a[u.first][u.second] && dist[ii][jj] > dist[u.first][u.second] + 1) {
				q.emplace_back(ii, jj);
				dist[ii][jj] = dist[u.first][u.second] + 1;
			}
		}
	}
	cout << dist[n][m] << "\n";
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
