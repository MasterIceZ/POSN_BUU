// Peatt Board

#include <bits/stdc++.h>

using namespace std;

const int MxN = 1010;

int board[MxN][MxN];

signed main(int argc, char *argv[]) {
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int w, h, n;
	cin >> w >> h >> n;
	for(int i=1, a, b, c, d; i<=n; ++i) {
		cin >> a >> b >> c >> d;
		board[b][a]++;
		board[d + 1][a]++;
		board[b][c + 1]++;
		board[d + 1][c + 1]++;
	}
	for(int i=1; i<=h; ++i) {
		for(int j=1; j<=w; ++j) {
			board[i][j] = (board[i][j] + board[i - 1][j] + board[i][j - 1] + board[i - 1][j - 1]) % 2;
			cout << board[i][j];
		}
		cout << "\n";
	}
	return 0;
}
